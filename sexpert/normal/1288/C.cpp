#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll dp[11][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    dp[0][0] = 1;
    for(int p = 0; p <= 9; p++) {
        for(int i = 0; i < 1005; i++) {
            for(int j = max(i, 1); j < 1005; j++) {
                dp[p + 1][j] += dp[p][i];
                if(dp[p + 1][j] >= MOD)
                    dp[p + 1][j] -= MOD;
            }
        }
    }
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n + 1 - x; y++) {
            ans += dp[m][x] * dp[m][y];
            ans %= MOD;
        }
    }
    cout << ans << '\n';
}