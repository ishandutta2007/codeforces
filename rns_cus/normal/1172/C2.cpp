#include <bits/stdc++.h>
using namespace std;

#define N 200200
#define M 3030

int n, m, a[N], w[N], dp[M][M], ep[M][M], X, Y, Z, ans[N], Inv[2*M+5];
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
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i ++) {
        if (a[i]) X += w[i];
        else Y += w[i];
    }
    Z = X + Y; dp[0][0] = 1;
    for (int i = -M; i <= M; i ++) Inv[i+M] = inv(i + Z);
    for (int i = 0; i <= m; i ++) {
        for (int j = 0; j <= m - i; j ++) {
            int s = 0;
            if (i) {
                add(dp[i][j], 1ll * dp[i-1][j] * (i - 1 + X) % mod * Inv[i-1-j+M]);
                add(ep[i][j], 1ll * ep[i-1][j] * (i - 1 + X) % mod * Inv[i-1-j+M]);
                add(s, 1ll * dp[i-1][j] * Inv[i-1-j+M]);
                add(s, 1ll * ep[i-1][j] * Inv[i-1-j+M]);
            }
            if (j) {
                add(dp[i][j], 1ll * dp[i][j-1] * (Y - j) % mod * Inv[i-j+1+M]);
                add(ep[i][j], 1ll * ep[i][j-1] * (Y - j) % mod * Inv[i-j+1+M]);
                add(s, 1ll * dp[i][j-1] * Inv[i-j+1+M]);
                add(s, 1ll * ep[i][j-1] * Inv[i-j+1+M]);
            }
            add(ep[i][j], s);
        }
    }
    int L = 0, R = 0;
    for (int i = 0; i <= m; i ++) add(L, dp[i][m-i]), add(R, ep[i][m-i]);
    for (int k = 1; k <= n; k ++) {
        printf("%d\n", (1ll * w[k] * (L + a[k] * R) % mod + mod) % mod);
    }


    return 0;
}