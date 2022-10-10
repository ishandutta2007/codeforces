

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int q;
    cin >> q;
    while(q--) {
        ll n, a, b;
        cin >> n >> a >> b;
        if(b > 2ll*a) {
            cout << n*a << endl;
            continue;
        }
        if(n % 2) {
            cout << a + b*(n - 1)/2ll << endl;
            continue;
        }
        cout << b*n/2ll << endl;
    }
}