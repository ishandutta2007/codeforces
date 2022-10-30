#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main(){
    string K;
    cin >> K;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for(int i=0; i<K.length(); i++){
        if(i % 2 == 0){
            if(K[i]=='1'){
                count1++;
            } else if(K[i]=='2'){
                count2++;
            } else{
                count3++;
            }
        }
    }

    string finalString="";
    for(int a=0; a<count1; a++){
        finalString += "1+";
    }
    for(int b=0; b<count2; b++){
        finalString += "2+";
    }
    for(int c=0; c<count3; c++){
        finalString += "3+";
    }

    finalString.erase(finalString.end()-1, finalString.end());

    cout << finalString;
}