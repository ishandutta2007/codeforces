#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <ctype.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string hi;
    int count=0;
    for(int i=0; i<N; i++){
        cin >> hi;
        if(hi[1]=='+'){
            count++;
        } else{
            count--;
        }
    }
    cout << count;
    return 0;
}