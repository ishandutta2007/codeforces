#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1005;
const int INF = 1e9;
const int B = 200;

int dp[N][N][22];
int n, m, len;

int main() {
    init();
    string s, t;
    cin >> n >> m >> len;
    cin >> s >> t;
    s.push_back('!');
    t.push_back('@');

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 22; k++)
                dp[i][j][k] = -INF;

    dp[0][0][11] = 0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k < 22; k++) {
                if (dp[i][j][k] == -INF) continue;
                if (k < 11) {
                    if (s[i] == t[j]) {
                        dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + 1);
                        if (k < 10) dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k] + 1);
                    }
                    dp[i + 1][j][k + 11] = max(dp[i + 1][j][k + 11], dp[i][j][k]);
                    dp[i][j + 1][k + 11] = max(dp[i][j + 1][k + 11], dp[i][j][k]);
                } else {
                    if (s[i] == t[j]) {
                        if (k < 21) dp[i + 1][j + 1][k - 10] = max(dp[i + 1][j + 1][k - 10], dp[i][j][k] + 1);
                    }
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                    dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
                }
            }

    cout << max(dp[n][m][len], dp[n][m][len + 11]);

    return 0;
}