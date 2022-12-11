#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int NMAX = 2e5;

ll modexp(ll b, ll e = MOD - 2) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

ll fact[NMAX], invfact[NMAX];

ll binom(ll n, ll r) {
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

ll solve() {
    int n; scanf("%d", &n);
    static char str[NMAX]; scanf("%s", str);
    bool allOnes = true;
    for (int i = 0; i < n; ++i) if (str[i] == '0') allOnes = false;
    if (allOnes) return 1;
    int b = 0, w = 0;
    int st = 0, ed = n - 1;
    if (n > 1) {
        if (str[0] == '1' && str[1] == '0') ++st;
        if (str[n-1] == '1' && str[n-2] == '0') --ed;
    }
    for (int i = st; i <= ed;) {
        if (str[i] == '0') {
            ++b; ++i;
        } else if (i == n - 1) {
            break;
        } else if (str[i+1] == '0') {
            ++b; i += 2;
        } else {
            ++w; i += 2;
        }
    }
    return binom(b + w, w);
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < NMAX; ++i) fact[i] = (fact[i-1] * i) % MOD;
    invfact[NMAX - 1] = modexp(fact[NMAX-1]);
    for (int i = NMAX - 2; i >= 0; --i) invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    int t; scanf("%d", &t);
    while (t--) printf("%lld\n", solve());
}