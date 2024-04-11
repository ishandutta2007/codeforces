#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int NMAX = 2001000;

ll POW10[NMAX];

ll getBlockCount(int n, int len) {
    if (n == len) return 10;
    ll edge = 10 * 9 * POW10[n - len - 1] % MOD;
    ll center = n - len - 2 >= 0 ? 10 * 9 * 9 * POW10[n - len - 2] % MOD : 0;
    return (2 * edge + max(0, n - len - 1) * center) % MOD;
}

int main() {
    POW10[0] = 1;
    for (int i = 1; i < NMAX; ++i) POW10[i] = (POW10[i-1] * 10) % MOD;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) printf("%lld%c", getBlockCount(n, i), (i == n ? '\n' : ' '));
}