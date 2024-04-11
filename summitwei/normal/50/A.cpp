#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <ctype.h>
using namespace std;

int main(){
    int M;
    int N;
    cin >> M >> N;

    int prod = M * N;
    int answer = (prod/2);

    cout << answer;
}