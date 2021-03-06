//
//  main.cpp
//  JustAnotherHangMan
//
//  Created by Thanapat Sorralump on 25/7/2564 BE.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

void displayGameDetail(int maxTries);
string chooseSecretWord();
void replaceDashes(char guessWord[], int length);
void displayWord(string word, int length);
int isGuessTrue(string secretWord, char guessWord[], char letter);
bool shouldStopGame(char guessWord[], int length);

int main(int argc, const char * argv[]) {
    int maxTries = 5;
    int remainingTries = 5;
    char guessLetter;
    string guessWord;
    int guessWordLength;
    displayGameDetail(maxTries);
    
    guessWord = chooseSecretWord();
    guessWordLength = (unsigned int)guessWord.length();
    
    char playWord[guessWordLength];
    replaceDashes(playWord, guessWordLength);
    
    while (remainingTries > 0) {
        cout << "Your guess word is: ";
        displayWord(playWord, guessWordLength);
        
        cout << "You have " << remainingTries << " times lefts" << endl;
        
        cout << "Guess the character: ";
        cin >> guessLetter;
        
        bool shouldContinue = false;
        
        int guessResult = isGuessTrue(guessWord, playWord, guessLetter);
        
        if (guessResult == 0) {
            shouldContinue = true;
            remainingTries -= 1;
            cout << "Wrong!!!" << endl;
        }
        
        if (guessResult == 1) {
            cout << "Correct!!!" << endl;
        }
        
        if (guessResult == 2) {
            cout << "You have guessed this letter already!!!" << endl;
        }
        
        cout << "------------------------\n" << endl;
        
        if (shouldStopGame(playWord, guessLetter)) {
            break;
        }
    }
    
    string endGameText = (remainingTries > 0) ? "Win!!!" : "You died";
    cout << endGameText << endl;
    cout << "Secret word is " + guessWord + ".\n" << endl;
}

bool shouldStopGame(char guessWord[], int length) {
    for (int i = 0; i < length; i++) {
        if (guessWord[i] == '-') {
            return false;
        }
    }
    return true;
}

int isGuessTrue(string secretWord, char guessWord[], char letter) {
    int returnResult = 0;
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == letter) {
            if (guessWord[i] == '-') {
                guessWord[i] = letter;
                returnResult = 1;
                continue;
            } else {
                return 2;
            }
        }
    }
    return returnResult;
}

void replaceDashes(char guessWord[], int length) {
    for (int i = 0; i < length; i++) {
        guessWord[i] = '-';
    }
    guessWord[length] = '\0';
}

void displayWord(string word, int length) {
    for (int i = 0; i < length; i++) {
        cout << word[i];
    }
    cout << endl;
}

string chooseSecretWord() {
    string randomWords[] = { "crossing", "offspring", "car", "maid", "ostracize", "official", "consider", "question", "bar", "contrary", "economics", "air", "sword", "index", "ground", "moon", "confusion", "struggle", "bury", "empire" };
    srand((unsigned)time(NULL));
    int randomIndex = rand() % 20;
    
    return randomWords[randomIndex];
}

void displayGameDetail(int maxTries) {
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Welcome to JustAnotherHangMan" << endl;
    cout << "You can guess the secret word for " << maxTries << " times. If you can't, you will die" << endl;
    cout << "Let's get started !!!!" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++\n" << endl;
}
