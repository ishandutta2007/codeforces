#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int LOGN = 20;
const int K = 12;
//const int M = 1e9 + 7;
const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
2 1 1
ab
a
*/

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dp[N][N][K][2];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    string a, b;
    cin >> a >> b;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int l = 0; l <= k; l++) {
                if(l > 0) {
                    dp[i][j][l][0] = max(dp[i][j][l][0], dp[i][j][l - 1][1]);
                }

//                cout << i << ' ' << j << ' ' << l << ' ' << dp[i][j][l][0] << ' ' << dp[i][j][l][1] << endl;
                dp[i + 1][j][l][0] = max(dp[i + 1][j][l][0], dp[i][j][l][0]);
                dp[i][j + 1][l][0] = max(dp[i][j + 1][l][0], dp[i][j][l][0]);

//                if(l > 0) {
//                    dp[i + 1][j][l][0] = max(dp[i + 1][j][l][0], dp[i][j][l - 1][1]);
//                    dp[i][j + 1][l][0] = max(dp[i][j + 1][l][0], dp[i][j][l - 1][1]);
//                }

                if(l < k && a[i] == b[j]) {
                    dp[i + 1][j + 1][l][1] = max(dp[i + 1][j + 1][l][1], dp[i][j][l][1] + 1);
                    dp[i + 1][j + 1][l][1] = max(dp[i + 1][j + 1][l][1], dp[i][j][l][0] + 1);
                    dp[i + 1][j + 1][l + 1][1] = max(dp[i + 1][j + 1][l + 1][1], dp[i][j][l][1] + 1);
                    dp[i + 1][j + 1][l + 1][1] = max(dp[i + 1][j + 1][l + 1][1], dp[i][j][l][0] + 1);
//                    if(l > 0)

                }
            }
        }
    }

    int ans = dp[n][m][k][0];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            for(int l = 0; l <= k; l++)
                for(int x = 0; x < 2; x++)
                    ans = max(ans, dp[i][j][l][x]);
    cout << ans << endl;
}