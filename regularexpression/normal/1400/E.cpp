#include<bits/stdc++.h>
using namespace std;

const int N = 5007, INF = 1e9 + 17;

inline void upd(int &x, int y) {
    if (y < x) x = y;
}

int a[N], dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int R = min(a[i], n);
        for (int j = 0; j < R; ++j) upd(dp[i][j + 1], dp[i][j] + 1);
        for (int j = 0; j <= R; ++j) {
            int nj = i + 1 == n ? j : min(j, a[i + 1]);
            upd(dp[i + 1][nj], dp[i][j] + !!(a[i] - j));
        }
    }
    int ans = INF;
    for (int i = 0; i <= n; ++i) upd(ans, dp[n][i]);
    cout << ans;
    return 0;
}