#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll mpow(ll b, ll e) {
    if(e == 0)
        return 1;
    if(e % 2)
        return (b * mpow(b, e - 1)) % MOD;
    ll p = mpow(b, e/2);
    return (p * p) % MOD;
}

int main() {
    ll n;
    cin >> n;
    ll side = mpow(2, n);
    cout << (side*(side + 1)/2ll) % MOD << endl;
}