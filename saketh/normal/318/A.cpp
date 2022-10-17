#include <iostream>
using namespace std;

long long N, K;

int main(){
    cin >> N >> K;
    long long odd = (N+1)/2;
    if(K <= odd) cout << 2*K-1 << endl;
    else cout << 2*(K-odd) << endl;
    return 0;
}