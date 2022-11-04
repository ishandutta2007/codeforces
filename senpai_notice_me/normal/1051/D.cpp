#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 5;

const int Mod = 998244353;

int n, K;

int dp[MAXN][4][MAXN];

int dist[4][4] = {
{0, 1, 1, 1}, 
{0, 0, 2, 0}, 
{0, 2, 0, 0}, 
{1, 1, 1, 0}
};

int main() {
    cin >> n >> K;
    
    dp[1][0][1] = dp[1][1][2] = dp[1][2][2] = dp[1][3][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k) {
            int delta = dist[j][k];
            for (int t = delta; t <= K; ++t) {
                dp[i][k][t] = (dp[i][k][t] + dp[i - 1][j][t - delta]) % Mod;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 4; ++i)
        ans = (ans + dp[n][i][K]) % Mod;
    
    cout << ans << endl;
    
    return 0;
}