#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MOD = 998244353;
const int N = 507;
const double EPS = 1e-8;

int dp[N][N][2];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k;
    cin >> n >> k;
    for (int mlen = 1; mlen <= n; mlen++) {
        dp[mlen][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int len = 1; len < mlen; len++) {
                if (i - len < 0) break;
                add(dp[mlen][i][0], dp[mlen][i - len][0]);
                add(dp[mlen][i][1], dp[mlen][i - len][1]);
            }
            if (i - mlen >= 0) {
                add(dp[mlen][i][1], dp[mlen][i - mlen][0]);
                add(dp[mlen][i][1], dp[mlen][i - mlen][1]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i * j >= k) break;
            add(res, (ll) dp[i][n][1] * (ll) dp[j][n][1] % MOD);
            //cout << i << " " << j << " " << dp[i][n][1] * dp[j][n][1] << "\n";
        }
    }
    cout << 2 * res % MOD;
}