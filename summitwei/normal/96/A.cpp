#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <ctype.h>
using namespace std;

int main(){
    string numbers;
    cin >> numbers;
    int blah = numbers.length();
    int combo = 0;
    bool currentIs0 = true;
    char c;
    for (int i=0; i<blah; i++){
        c = numbers[i];
        if(c == '0' && currentIs0){
            combo++;
            if(combo == 7){
                cout << "YES";
                return 0;
            }
        } else if(c == '0' && !currentIs0){
            currentIs0 = true;
            combo = 1;
        } else if(c == '1' && !currentIs0){
            combo++;
            if(combo == 7){
                cout << "YES";
                return 0;
            }
        } else if(c == '1' && currentIs0){
            currentIs0 = false;
            combo = 1;
        }
    }
    cout << "NO";
    return 0;
}