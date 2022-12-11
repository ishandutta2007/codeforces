#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 420;
ll MOD;

ll binom[NMAX][NMAX], eqp[NMAX][NMAX];

ll pascal(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return binom[n][r];
}

ll sterlingish(int n, int k) {
    if (n == 0) return (k == 0 ? 1 : 0);
    if (n < 0 || k <= 0 || k > n) return 0;
    return eqp[n][k];
}

ll pow2[NMAX];

void init() {
    pow2[0] = 1;
    for (int i = 1; i < NMAX; ++i) pow2[i] = (pow2[i-1] * 2) % MOD;
    for (int n = 0; n < NMAX; ++n) {
        binom[n][0] = binom[n][n] = 1;
        for (int r = 1; r < n; ++r) binom[n][r] = (binom[n-1][r-1] + binom[n-1][r]) % MOD;
    }
    eqp[0][0] = 1;
    for (int n = 1; n < NMAX; ++n) {
        for (int k = 1; k <= n; ++k) {
            for (int pm = 0; pm < n; ++pm) {
                eqp[n][k] = (sterlingish(n, k) + pascal(n-1, pm) * sterlingish(n - (pm + 1), k - 1) % MOD) % MOD;        
            }
            eqp[n][k] = sterlingish(n, k) * k % MOD;
        }
    }
}

int main() {
    int n; scanf("%d %lld", &n, &MOD);
    init();
    ll ans = 0;
    for (int h = 0; h <= n; ++h) {
        int twoe = n - 2 * h - 1;
        if (twoe < 0) continue;
        ans = (ans + pow2[twoe] * sterlingish(n-h, h+1)) % MOD;
    }
    printf("%lld\n", ans);
}