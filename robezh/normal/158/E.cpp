#include <bits/stdc++.h>
using namespace std;

const int N = (int)4e3 + 50, INF = (int)1e9;

int n, k;
int dp[N][N];
int t[N], d[N];

int get_time(int now, int i) {
    return max(now, t[i]) + d[i];
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> t[i] >> d[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 1;
    int res = k == n ? 86400 : (k == 0 ? 0 : t[k] - 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j >= 1 && dp[i-1][j-1] < INF) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            if(dp[i-1][j] < INF) dp[i][j] = min(dp[i][j], get_time(dp[i-1][j], i));
            if(dp[i][j] != INF) {
                int nxt = k - j + i + 1;
                if(nxt >= n + 1) res = max(res, 86400 - dp[i][j] + 1);
                else res = max(res, t[nxt] - dp[i][j]);
            }
//            cout << dp[i][j] << " ";
        }
//        cout << endl;
    }
    cout << res << endl;
}