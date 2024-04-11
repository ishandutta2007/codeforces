#include <bits/stdc++.h>
using namespace std;

#define N 55

int n, m, a[N], w[N], dp[N][N][N], ep[N][N], X, Y, Z, ans[N];
const int mod = 998244353;

int expmod(int x, int n) {
    int rlt = 1;
    while (n) {
        if (n & 1) rlt = 1ll * rlt * x % mod;
        x = 1ll * x * x % mod, n >>= 1;
    }
    return rlt;
}

inline int inv(int x) {
    return expmod(x, mod - 2);
}

inline void add(int &x, long long y) {
    x = (x + y) % mod;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]), dp[0][0][i] = w[i];
    for (int i = 1; i <= n; i ++) {
        if (a[i]) X += w[i];
        else Y += w[i];
    }
    Z = X + Y; dp[0][0][0] = 1;
    for (int i = 0; i <= m; i ++) {
        for (int j = 0; j <= m - i; j ++) {
            for (int k = 0; k <= n; k ++) {
//                cerr << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
                add(dp[i+1][j][k], 1ll * dp[i][j][k] * (i + X) % mod * inv(i - j + Z));
                add(dp[i][j+1][k], 1ll * dp[i][j][k] * (Y - j) % mod * inv(i - j + Z));
                if (k) {
                    if (a[k]) add(dp[i+1][j][k], 1ll * dp[i][j][k] * inv(i - j + Z));
                    else add(dp[i][j+1][k], 1ll * (mod - dp[i][j][k]) * inv(i - j + Z));
                }
            }
        }
    }
    for (int k = 1; k <= n; k ++) {
        for (int i = 0; i <= m; i ++) add(ans[k], dp[i][m-i][k]);
        printf("%d\n", ans[k]);
    }


    return 0;
}