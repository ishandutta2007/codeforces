#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main(){
    string A, B;

    cin >> A >> B;

    int len1 = A.length();
    int len2 = B.length();

    string newA = "";
    string newB = "";

    char temp;
    for(int i=0; i<len1; i++){
        temp = A[i];
        temp = tolower(temp);
        newA += temp;
    }
    for(int j=0; j<len2; j++){
        temp = B[j];
        temp = tolower(temp);
        newB += temp;
    }
    
    int smaller = min(len1, len2);
    
    for(int k=0; k<smaller; k++){
        char char1 = newA[k];
        char char2 = newB[k];
        if(char1 < char2){
            cout << -1;
            return 0;
        } else if (char1 > char2){
            cout << 1;
            return 0;
        }
    }

    if(len1 == len2){
        cout << 0;
    } else if (len1 > len2){
        cout << 1;
    } else{
        cout << -1;
    }


    return 0;
}