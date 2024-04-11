#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <ctype.h>
using namespace std;



int main(){
    string originalInput;
    vector<char> result1;
    cin >> originalInput;
    int strLen = originalInput.length();
    result1.resize(strLen);
    for(int i=0; i<strLen; i++){
        int temp1 = originalInput[i];
        if(originalInput[i] > 64 && originalInput[i] < 91){
            temp1 += 32;
        }
        result1[i] = temp1;
    }
    int count = 0;
    int tempWeirdCount=0;
    for(int j=0; j<strLen; j++){
        char temp2 = result1[tempWeirdCount];
        if(temp2 == 'a' || temp2 == 'e' || temp2 == 'i' || temp2 == 'o' || temp2 == 'u' || temp2 == 'y'){
            result1.erase(result1.begin()+(tempWeirdCount));
            count++;
        } else{
            tempWeirdCount++;
        }
    }
    int newSize = strLen - count;
    result1.resize(newSize);

    vector<char> result2;
    result2.resize(newSize*2);

    for(int k=0; k<newSize*2; k++){
        if(k%2==0){
            result2[k]='.';
        } else{
            result2[k]=result1[k/2];
        }
    }

    for(int a=0; a<newSize*2; a++){
        cout << result2[a];
    }
    return 0;
}