#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1 << 19;
const LL inf = 1e18;

int n, a[N], cnt, b[N];
LL dp[(1<<18)+ 1][19];
int f[30], s[30];

int main() {
    f[1] = 1; 
    for (int i = 2; i <= 18; i ++) f[i] = f[i-1] * 2;
    for (int i = 1; i <= 18; i ++) s[i] = s[i-1] + f[i];

    scanf("%d", &n);
    int r = 0, tmp = n; 
    while (tmp) {
        tmp /= 2; r ++;
    }

    bool fg = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (a[i] == -1) fg = 1;
        if (fg == 0) a[i] = 0;
        if (a[i] != -1) b[++cnt] = a[i];
    }
    // printf("cnt = %d\n", cnt);
    // for (int i = 1; i <= cnt; i ++) printf("%d\n", b[i]);
    for (int i = 0; i <= (1<<18); i ++) for (int j = 0; j <= 18; j ++) dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= cnt; i ++) {
        for (int j = 0; j <= 18; j ++) {
            if (i < s[j]) continue;
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + b[i]);
            // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    cout << dp[cnt][r - 1] << endl;
}