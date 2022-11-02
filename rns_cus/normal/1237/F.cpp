#include <bits/stdc++.h>
using namespace std;

#define N 4040

int h, w, n, dp[N][N], ep[N][N], fac[N], ri[N], rfac[N];
const int mod = 998244353;
bool vis_r[N], vis_c[N];

inline void add(int &x, int y) {
    if ((x += y) >= mod) x -= mod;
}

void solve(int n, int dp[N][N], bool vis[N]) {
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        memcpy(dp[i], dp[i-1], sizeof dp[i]);
        if (vis[i] && vis[i-1]) {
            for (int j = 1; j < N; j ++) add(dp[i][j], dp[i-2][j-1]);
        }
    }
}

inline int C(int n, int m) {
    if (n < m) return 0;
    return 1ll * rfac[m] * rfac[n-m] % mod * fac[n] % mod;
}

int main() {
    fac[0] = rfac[0] = ri[1] = 1;
    for (int i = 1; i < N; i ++) {
        fac[i] = 1ll * i * fac[i-1] % mod;
        if (i > 1) ri[i] = 1ll * (mod - mod / i) * ri[mod%i] % mod;
        rfac[i] = 1ll * ri[i] * rfac[i-1] % mod;
    }
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 1; i <= h; i ++) vis_r[i] = 1;
    for (int i = 1; i <= w; i ++) vis_c[i] = 1;
    while (n --) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        vis_r[a] = vis_r[c] = 0;
        vis_c[b] = vis_c[d] = 0;
    }
    solve(h, dp, vis_r), solve(w, ep, vis_c);
    int gh = 0, gw = 0;
    for (int i = 1; i <= h; i ++) if (vis_r[i]) gh ++;
    for (int i = 1; i <= w; i ++) if (vis_c[i]) gw ++;
    int rlt = 0;
    for (int a = 0; a <= h; a ++) {
        for (int b = 0; b <= w; b ++) {
            rlt = (rlt + 1ll * dp[h][a] * ep[w][b] % mod * C(gh - 2 * a, b) % mod * C(gw - 2 * b, a) % mod * fac[a] % mod * fac[b]) % mod;
        }
    }
    printf("%d", rlt);
}