#include <iostream>

using namespace std;

int main() {
    long long n, k, t;
    cin >> n >> k >> t;
    if(t <= k){
        cout << t;
    }
    else if(t >=k+1 && t <= n){
        cout << k;
    }
    else if( t >=n+1 && t <= n+k){
        cout << k - t + n;
    }
}