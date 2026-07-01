#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

struct Question {
    string question;
    string options[4];
    int answer; // 1, 2, 3, or 4
};

void displayQuestion(const Question& q, int questionNumber) {
    cout << "Question " << questionNumber << ": " << q.question << endl;
    for (int j = 0; j < 4; j++) {
        cout << j + 1 << ". " << q.options[j] << endl;
    }
}

vector<Question> selectRandomQuestions(const vector<Question>& allQuestions, int numQuestions) {
    vector<Question> selectedQuestions;
    vector<int> indices(allQuestions.size());
    for (int i = 0; i < allQuestions.size(); i++) {
        indices[i] = i;
    }
    random_shuffle(indices.begin(), indices.end());
    for (int i = 0; i < numQuestions; i++) {
        selectedQuestions.push_back(allQuestions[indices[i]]);
    }
    return selectedQuestions;
}

int main() {
    const int QUESTIONS_PER_ROUND = 5;
    const int ROUNDS = 3;
    const int PRIZE_PER_QUESTION = 100;

    vector<Question> set1 = {
        {"What is the capital of Japan?", {"Seoul", "Beijing", "Tokyo", "Bangkok"}, 3},
        {"Who painted the ceiling of the Sistine Chapel?", {"Leonardo da Vinci", "Michelangelo", "Raphael", "Van Gogh"}, 2},
        {"What is the chemical symbol for gold?", {"Au", "Ag", "Pb", "Fe"}, 1},
        {"What is the largest ocean on Earth?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 4},
        {"Who wrote 'Pride and Prejudice'?", {"Charlotte Brontë", "Jane Austen", "Charles Dickens", "Mark Twain"}, 2},
        {"What is the smallest country in the world?", {"Monaco", "Nauru", "Vatican City", "Malta"}, 3},
        {"What is the main ingredient in hummus?", {"Chickpeas", "Lentils", "Beans", "Rice"}, 1},
        {"Which planet is known as the Red Planet?", {"Earth", "Venus", "Mars", "Jupiter"}, 3},
        {"Who discovered penicillin?", {"Louis Pasteur", "Alexander Fleming", "Marie Curie", "Thomas Edison"}, 2},
        {"What is the capital of Canada?", {"Toronto", "Ottawa", "Vancouver", "Montreal"}, 2},
        {"What is the longest river in the world?", {"Amazon", "Nile", "Yangtze", "Mississippi"}, 1},
        {"What is the hardest natural substance on Earth?", {"Gold", "Iron", "Diamond", "Quartz"}, 3},
        {"In what year did the Titanic sink?", {"1905", "1912", "1915", "1920"}, 2},
        {"Who is known as the father of modern physics?", {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"}, 2},
        {"What is the currency of the United Kingdom?", {"Dollar", "Euro", "Pound", "Yen"}, 3},
        {"Which gas is most abundant in the Earth's atmosphere?", {"Oxygen", "Nitrogen", "Carbon Dioxide", "Hydrogen"}, 2},
        {"What is the main ingredient in sushi?", {"Fish", "Rice", "Seaweed", "Tofu"}, 2},
        {"What is the capital of Italy?", {"Florence", "Venice", "Rome", "Milan"}, 3},
        {"Who wrote the play 'Hamlet'?", {"Shakespeare", "Dickens", "Ibsen", "Chekhov"}, 1},
        {"What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 2},
        {"Which planet is known for its rings?", {"Mars", "Saturn", "Jupiter", "Neptune"}, 2},
        {"Who is the author of the Harry Potter series?", {"J.K. Rowling", "J.R.R. Tolkien", "Suzanne Collins", "C.S. Lewis"}, 1},
        {"What is the boiling point of water?", {"90°C", "100°C", "110°C", "120°C"}, 2},
        {"What element does 'O' represent on the periodic table?", {"Osmium", "Oxygen", "Gold", "Silver"}, 2},
        {"What is the largest desert in the world?", {"Sahara", "Arabian", "Gobi", "Antarctic"}, 4},
        {"Which country is known as the land of the rising sun?", {"China", "Japan", "Korea", "Thailand"}, 2},
        {"What is the main language spoken in Brazil?", {"Spanish", "English", "Portuguese", "French"}, 3},
        {"Which organ is responsible for pumping blood?", {"Brain", "Liver", "Heart", "Lungs"}, 3},
        {"What is the smallest prime number?", {"0", "1", "2", "3"}, 3},
        {"Which ocean is the largest?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 4},
        {"What is the first element on the periodic table?", {"Hydrogen", "Helium", "Oxygen", "Lithium"}, 1},
        {"What year did World War II end?", {"1945", "1939", "1940", "1946"}, 1},
        {"What is the capital of Australia?", {"Sydney", "Melbourne", "Canberra", "Brisbane"}, 3},
        {"Who painted the Mona Lisa?", {"Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Claude Monet"}, 3},
        {"What is the tallest mountain in the world?", {"K2", "Kangchenjunga", "Mount Everest", "Lhotse"}, 3},
    };

    vector<Question> set2 = {
        {"Which planet is closest to the sun?", {"Earth", "Venus", "Mars", "Mercury"}, 4},
        {"What is the capital of France?", {"Paris", "London", "Rome", "Berlin"}, 1},
        {"What gas do plants absorb from the atmosphere?", {"Oxygen", "Carbon Dioxide", "Nitrogen", "Hydrogen"}, 2},
        {"What is the largest continent?", {"Asia", "Africa", "North America", "South America"}, 1},
        {"What is the currency of Japan?", {"Yen", "Won", "Dollar", "Pound"}, 1},
        {"What is the main ingredient in bread?", {"Flour", "Sugar", "Yeast", "Salt"}, 1},
        {"What is the boiling point of water in Fahrenheit?", {"212°F", "100°F", "32°F", "150°F"}, 1},
        {"Which famous scientist developed the theory of relativity?", {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"}, 2},
        {"What is the chemical formula for water?", {"H2O", "CO2", "NaCl", "C6H12O6"}, 1},
        {"How many continents are there?", {"5", "6", "7", "8"}, 3},
        {"What is the main ingredient in guacamole?", {"Tomato", "Avocado", "Pepper", "Onion"}, 2},
        {"What is the capital of Italy?", {"Rome", "Venice", "Florence", "Milan"}, 1},
        {"What is the hardest rock?", {"Basalt", "Granite", "Marble", "Quartzite"}, 4},
        {"Which organ is responsible for detoxification in the body?", {"Heart", "Liver", "Kidney", "Lungs"}, 2},
        {"Who wrote '1984'?", {"George Orwell", "Aldous Huxley", "Ray Bradbury", "F. Scott Fitzgerald"}, 1},
        {"What is the most widely spoken language in the world?", {"English", "Mandarin", "Spanish", "Hindi"}, 2},
        {"What is the capital of Egypt?", {"Cairo", "Alexandria", "Giza", "Luxor"}, 1},
        {"What is the currency of the USA?", {"Euro", "Dollar", "Pound", "Yen"}, 2},
        {"What is the main source of energy for the Earth?", {"The Moon", "The Sun", "The Stars", "Wind"}, 2},
        {"Which animal is known as the king of the jungle?", {"Elephant", "Lion", "Tiger", "Bear"}, 2},
        {"What is the primary ingredient in chocolate?", {"Cocoa Beans", "Sugar", "Milk", "Butter"}, 1},
        {"Which is the smallest continent?", {"Asia", "Australia", "Europe", "Antarctica"}, 2},
        {"Which instrument has 88 keys?", {"Piano", "Guitar", "Violin", "Flute"}, 1},
        {"What is the chemical symbol for silver?", {"Si", "Ag", "Au", "Pb"}, 2},
        {"What is the capital of India?", {"New Delhi", "Mumbai", "Bangalore", "Chennai"}, 1},
        {"What is the primary gas in the Earth's atmosphere?", {"Oxygen", "Nitrogen", "Carbon Dioxide", "Hydrogen"}, 2},
        {"What is the capital of Russia?", {"Moscow", "St. Petersburg", "Novosibirsk", "Yekaterinburg"}, 1},
        {"What is the fastest land animal?", {"Cheetah", "Lion", "Tiger", "Gazelle"}, 1},
        {"What is the largest planet in our solar system?", {"Earth", "Jupiter", "Saturn", "Mars"}, 2},
        {"What is the currency of Canada?", {"Dollar", "Pound", "Euro", "Yen"}, 1},
        {"What element does 'Na' represent on the periodic table?", {"Nitrogen", "Sodium", "Noble gas", "Neon"}, 2},
        {"What is the capital of Germany?", {"Berlin", "Munich", "Frankfurt", "Hamburg"}, 1},
        {"Which organ is vital for breathing?", {"Heart", "Brain", "Lungs", "Liver"}, 3},
        {"What is the square root of 64?", {"6", "7", "8", "9"}, 3},
    };

    srand(static_cast<unsigned int>(time(0)));
    int totalScore = 0;

    for (int round = 1; round <= ROUNDS; round++) {
        cout << "\nRound " << round << ":\n";
        vector<Question> selectedQuestions = selectRandomQuestions(set1, QUESTIONS_PER_ROUND);

        int roundScore = 0;
        for (int i = 0; i < selectedQuestions.size(); i++) {
            displayQuestion(selectedQuestions[i], i + 1);
            int userAnswer;
            cout << "Your answer (1-4): ";
            cin >> userAnswer;

            if (userAnswer == selectedQuestions[i].answer) {
                cout << "Correct!" << endl;
                roundScore += PRIZE_PER_QUESTION;
            } else {
                cout << "Incorrect! The correct answer was: " << selectedQuestions[i].options[selectedQuestions[i].answer - 1] << endl;
            }
        }

        totalScore += roundScore;
        cout << "You scored " << roundScore << " points in this round!" << endl;
    }

    cout << "\nGame Over! Your total score is: " << totalScore << endl;
    return 0;
}