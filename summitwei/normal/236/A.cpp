#include <bits/stdc++.h>
using namespace std;

int main(){
    string N;
    cin >> N;

    int uniqueChars = 0;
    vector<char> usedChars;
    usedChars.resize(N.length());

    for(int i=0; i<N.length(); i++){
        bool isItUnique = true;
        for(int j=0; j<uniqueChars; j++){
            if(N[i] == usedChars[j]){
                isItUnique = false;
            }
        }
        if(isItUnique){
            usedChars[uniqueChars] = N[i];
            uniqueChars++;
        }
    }


    if(uniqueChars % 2 == 0){
        cout << "CHAT WITH HER!";
    } else{
        cout << "IGNORE HIM!";
    }
    
    return 0;
}