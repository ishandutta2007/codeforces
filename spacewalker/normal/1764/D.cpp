#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 5010;

ll MOD;

ll fact[NMAX];
ll invfact[NMAX];

ll modexp(ll b, ll e = MOD - 2) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b % MOD, e/2) % MOD;
}

ll binom(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return fact[n] * invfact[n-r] % MOD * invfact[r] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n >> MOD;
    int maxGap = n/2;

    fact[0] = 1;
    for (int i = 1; i < NMAX; ++i) fact[i] = (fact[i-1] * i) % MOD;
    invfact[NMAX-1] = modexp(fact[NMAX-1]);
    for (int i = NMAX-2; i >= 0; --i) {
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
    }

    ll ans = 0;
    for (int i = maxGap + 1; i <= n; ++i) {
        int internal = max(0, n-i-1);
        for (int safePick = 0; safePick <= internal; ++safePick) {
            ll goodLast = maxGap - (i - maxGap) + 1;
            if (goodLast < 0) continue;
            ll cans = goodLast % MOD * fact[i-2 + safePick] % MOD * binom(internal, safePick) % MOD * n % MOD;
            ans = (ans + cans) % MOD;
        }
    }
    cout << ans << endl;
}