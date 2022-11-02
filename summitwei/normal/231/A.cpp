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

    int count = 0;
    int a, b, c;
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        if(a+b+c>1){
            count++;
        }
    }
    cout << count;
    return 0;
}