#include <iostream>
using namespace std;
const int N = 202;
const int INF = 100000007;

int n, a, b;
int h[N], sum[N];
int dp[N][40000+10][2]; // i, R, s

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i ++) 
        scanf("%d", &h[i]), sum[i] = sum[i-1] + h[i];

    for (int i = 1; i < N; i ++)
        for (int j = 0; j < 40000+10; j ++)
            dp[i][j][0] = dp[i][j][1] = INF;

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= sum[i]; j ++) {
            if (j > a || sum[i]-j > b)
                continue;

            for (int k = 1; k <= 1; k ++) {
                int t = (sum[i]-sum[i-k]);  
                if (j >= t) { 
                    dp[i][j][0] = min(dp[i][j][0], dp[i-k][j-t][1] + min(h[i-k], h[i-k+1]));
                    dp[i][j][0] = min(dp[i][j][0], dp[i-k][j-t][0]);
                }
                if (sum[i]-j >= t) {
                    dp[i][j][1] = min(dp[i][j][1], dp[i-k][j][0] + min(h[i-k], h[i-k+1]));
                    dp[i][j][1] = min(dp[i][j][1], dp[i-k][j][1]);
                }
            } 
        }
    }
    int ans = INF;
    for (int i = 0; i <= a; i ++)
        ans = min(ans, dp[n][i][0]), ans = min(ans, dp[n][i][1]);
    if (ans == INF) ans = -1;
    printf("%d\n", ans);

}