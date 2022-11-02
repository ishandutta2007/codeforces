#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
    long long m;
    long long n;
    long long a;
    cin >> m >> n >> a;
    long long tempm;
    long long tempn;
    if(m % a == 0){
        tempm = (m - (m % a))/a;
    } else {
        tempm = (m - (m % a))/a + 1;
    }
    if(n % a == 0){
        tempn = (n - (n % a))/a;
    } else {
        tempn = (n - (n % a))/a + 1;
    }
    long long answer;
    answer = tempm * tempn;
    cout << answer;
    return 0;
}