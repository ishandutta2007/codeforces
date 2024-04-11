#include <iostream>
using namespace std;
const int N = 5002;
const int MOD = 1000000007;

int n, dp[N][N], sm[N][N];
char s[N], op[2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", op+1); s[i] = op[1];
    }

    dp[1][1] = 1;
    for (int i=1;i<=n;i++) 
        sm[1][i] = 1;
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (s[i] == 'f') {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
            if (s[i] == 's') {
                dp[i+1][j] += sm[i][n] - sm[i][j-1];
                dp[i+1][j] = (dp[i+1][j] + MOD) % MOD;
            }
        }
        for (int j = 1; j <= n; j ++) {
            sm[i+1][j] = (sm[i+1][j-1] + dp[i+1][j]) % MOD;
        }
    }
    //

    //
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = (ans + dp[n][i]) % MOD;
    }
    printf("%d\n", ans);
}