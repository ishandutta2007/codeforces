#include <iostream>
using namespace std;

long long N, L = 0;

int main(){
    cin >> N;

    for(long long C = 1; C <= N; C+=L+1){
        N -= C;
        L++;
    }

    cout << L << endl;
}