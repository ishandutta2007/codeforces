#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll NMAX = 1000050;

ll fact[NMAX], invfact[NMAX];

ll modexp(ll b, ll e = MOD - 2) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

ll binom(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < NMAX; ++i) fact[i] = (fact[i-1] * i) % MOD;
    invfact[NMAX-1] = modexp(fact[NMAX-1]);
    for (int i = NMAX-2; i >= 0; --i) invfact[i] = invfact[i+1] * (i+1) % MOD;
    int n; scanf("%d", &n);
    ll ans = 0;
    for (int blk = 0; blk <= n/2; ++blk) {
        ll sts = n-1-blk;
        if (sts % 2 == 0) continue;
        ans = (ans + binom(sts + 1, blk) * fact[sts]) % MOD;
    }
    ans = (ans * 2 * n) % MOD;
    printf("%lld\n", ans);
}