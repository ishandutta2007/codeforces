#include <iostream>
#include <string>

using namespace std;

void wordToNumbers(string word){
    int midLetters = word.length();
    char firstLetter = word.front();
    char lastLetter = word.back();
    cout <<firstLetter <<(midLetters-2) <<lastLetter <<endl;
}

int main(){
    string wordInput;
    string firstNum;

    getline(cin,firstNum);

    int i = stoi(firstNum);

    for(i>=1; i--;){
        getline(cin,wordInput);

        if (wordInput.length() > 10){
            wordToNumbers(wordInput);
        } else {
            cout <<wordInput <<endl;
        }
    }
    return 0;
}