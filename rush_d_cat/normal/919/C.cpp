#include <iostream>
using namespace std;
const int N = 2002;
int n, m, k, dp[N], ans;
char mp[N][N];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) scanf("%s", mp[i] + 1);
    if (k == 1) {
        for (int i = 1; i <= n; i ++) 
            for (int j = 1; j <= m; j ++)
                if (mp[i][j] == '.') ans ++;
        printf("%d\n", ans);
        return 0;
    }
    for (int i = 1; i <= n; i ++) {
        dp[m+1] = 0;
        for (int j = m; j >= 1; j --) {
            if (mp[i][j] == '.') dp[j] = dp[j+1] + 1;
            else dp[j] = 0;
            if (dp[j] >= k) ans ++;
        }
    }
    for (int i = 1; i <= m; i ++) {
        dp[n+1] = 0;
        for (int j = n; j >= 1; j --) {
            if (mp[j][i] == '.') dp[j] = dp[j+1] + 1;
            else dp[j] = 0;
            if (dp[j] >= k) ans ++;
        }
    }
    printf("%d\n", ans);
}