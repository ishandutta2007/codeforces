#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

int main() {
    cin >> n >> m;
    while(true){
        if(n == 0 || m == 0) break;
        if(n >= 2 * m){
            n -= n / (2*m) * (2*m);
        }
        else if(m >= 2 * n){
            m -= m / (2*n) * (2*n);
        }
        else break;
    }
    cout << n << " " << m;
}