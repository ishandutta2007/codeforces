#include <iostream>
using namespace std;

long long N;

int main(){
    cin >> N;
    if(N % 2) cout << "-";
    cout << (N+1)/2 << endl;
    return 0;
}