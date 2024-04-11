#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[42];
int x[1 << 10], y[1 << 10], c[1 << 10];
long long dp[1 << 18][18];
long long add[42][42];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i] >> c[i];
        y[i]--;
        x[i]--;
        add[x[i]][y[i]] = c[i];
    }
    for (int i = 0; i < (1 << 18); ++i) {
        for (int j = 0; j < 18; ++j)
            dp[i][j] = -(long long)1e18;
    }
    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = a[i];
    long long ans = -(long long)1e18;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int bits = 0;
        for (int last = 0; last < n; ++last) {
            if (mask & (1 << last)) {
                ++bits;
                for (int nlast = 0; nlast < n; ++nlast) {
                    if (~mask & (1 << nlast)) {
                        dp[mask | (1 << nlast)][nlast] = max(dp[mask | (1 << nlast)][nlast], dp[mask][last] + a[nlast] + add[last][nlast]);
                    }
                }
            }
        }
        for (int last = 0; last < n; ++last) {
            if (mask & (1 << last)) {
                if (bits == m) {
                    ans = max(ans, dp[mask][last]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}