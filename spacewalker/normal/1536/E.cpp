#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int NMAX = 2010;

ll solve() {
    static char grid[NMAX][NMAX];
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
    int zc = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == '0') ++zc;
    int uc = n * m - zc;
    ll ans = 1;
    for (int i = 0; i < uc; ++i) ans = (2 * ans) % MOD;
    if (zc == 0) ans = (ans + MOD - 1) % MOD;
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%lld\n", solve());
    }
    return 0;
}