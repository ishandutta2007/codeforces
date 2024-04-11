#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e16;
ll cost[105][105], dp[105][105][105]; // pref, final color, num
int n, m, k, col[105];

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> col[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> cost[i][j];
        }
    }
    for(int i = 0; i < 105; i++) {
        for(int j = 0; j < 105; j++) {
            for(int t = 0; t < 105; t++) {
                dp[i][j][t] = INF;
            }
        }
    }
    for(int i = 0; i < 105; i++)
        dp[0][i][0] = 0;
    for(int pos = 1; pos <= n; pos++) {
        for(int num = 1; num <= k; num++) {
            if(col[pos] > 0) {
                dp[pos][col[pos]][num] = dp[pos - 1][col[pos]][num];
                for(int c = 1; c <= m; c++) {
                    if(pos > 1 && c == col[pos])
                        continue;
                    dp[pos][col[pos]][num] = min(dp[pos][col[pos]][num], dp[pos - 1][c][num - 1]);
                }
            }
            else {
                for(int c = 1; c <= m; c++) {
                    dp[pos][c][num] = dp[pos - 1][c][num] + cost[pos][c];
                    for(int c2 = 1; c2 <= m; c2++) {
                        if(pos > 1 && c2 == c)
                            continue;
                        dp[pos][c][num] = min(dp[pos][c][num], dp[pos - 1][c2][num - 1] + cost[pos][c]);
                    }
                }
            }
        }
    }
    ll mn = INF;
    for(int c = 1; c <= m; c++)
        mn = min(mn, dp[n][c][k]);
    cout << (mn == INF ? -1 : mn) << endl;
}