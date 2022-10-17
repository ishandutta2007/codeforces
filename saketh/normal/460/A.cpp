#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, M;

int main(){
    cin >> N >> M;

    int day = 0;
    
    while(N > 0){
        N--;
        if(day%M == M-1) N++;
        day++;
    }

    cout << day << endl;
    return 0;
}