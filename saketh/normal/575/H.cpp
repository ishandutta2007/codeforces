#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXV = 2e6 + 100;
const int MOD = 1e9 + 7;

ll fact[MAXV];

ll mpow(ll b, ll e) {
    if (e == 0) return 1;
    if (e&1) return b * mpow(b, e-1) % MOD;
    return mpow(b * b % MOD, e / 2);
}

ll inv(ll v) {
    return mpow(v, MOD - 2);
}

ll ncr(ll n, ll r) {
    return fact[n] * inv(fact[r] * fact[n-r] % MOD) % MOD;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < MAXV; i++) 
        fact[i] = i * fact[i-1] % MOD;

    ll N;
    cin >> N;

    cout << ( ncr(2 * (N + 1), N + 1) - 1 + MOD ) % MOD << "\n";
}