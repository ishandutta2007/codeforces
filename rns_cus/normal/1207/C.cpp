#include <bits/stdc++.h>
using namespace std;

#define N 200200
typedef long long ll;
int n, a, b;
ll dp[N][2];
const ll inf = 1e18;
char s[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d %s", &n, &a, &b, s);
        for (int i = 0; i <= n; i ++) dp[i][0] = dp[i][1] = inf;
        dp[0][0] = b;
        for (int i = 1; i <= n; i ++) {
            if (s[i-1] == '0') {
                dp[i][0] = b + min(dp[i-1][1] + 2 * a, dp[i-1][0] + a);
                dp[i][1] = 2 * b + min(dp[i-1][1] + a, dp[i-1][0] + 2 * a);
            }
            else dp[i][1] = 2 * b + dp[i-1][1] + a;
        }
        printf("%I64d\n", dp[n][0]);
    }

    return 0;
}