#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 2e6 + 10;
ll dp[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    dp[1][0] = dp[1][1] = 0;
    dp[2][0] = dp[2][1] = 0;

    for(int i = 3; i < MAXN; i++) {
        dp[i][1] = (4 + dp[i - 1][0] + 2 * dp[i - 2][0]) % MOD;
        dp[i][0] = (max(dp[i - 1][0], dp[i - 1][1]) + 2LL * max(dp[i - 2][0], dp[i - 2][1])) % MOD;
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << max(dp[n][0], dp[n][1]) << '\n';
    }
}