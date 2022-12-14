#include <bits/stdc++.h>
using namespace std;
#define N 60
#define M 1010

const int mod = 1e9 + 7;

char s[N][M];
int a[N][M];
bool vis[M];
int rt[M], sz[M];
int b[M] = {1, 1}, fac[M] = {1, 1}, rfac[M] = {1, 1}, inv[M] = {1, 1};
vector <int> v;
int n, m;

int expmod(int a, int b, int mod) {
    int res = 1;
    for ( ; b; b >>= 1) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
    }
    return res;
}

int find_rt(int x) {
    if (rt[x] == x) return x;
    return rt[x] = find_rt(rt[x]);
}

void func(int x, int y) {
    int i;
    for (i = 1; i <= n; i ++) {
        if (a[i][x] != a[i][y]) break;
    }
    if (i <= n) return;
    int xx = find_rt(x), yy = find_rt(y);
    if (xx == yy) return;
    rt[xx] = yy; sz[yy] += sz[xx];
    return;
}

int C(int n, int m) {
    return 1ll * fac[n] * rfac[m] % mod * rfac[n - m] % mod;
}

void init() {
    for (int i = 2; i < M; i ++) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        inv[i] = 1ll * (mod / i) * (mod - inv[mod % i]) % mod;
        rfac[i] = 1ll * rfac[i - 1] * inv[i] % mod;
    }
    for (int i = 2; i < M; i ++) {
        for (int j = 0; j < i; j ++) {
            b[i] = (b[i] + 1ll * b[j] * C(i - 1, j)) % mod;
        }
    }
    return;
}

int main() {
    init();
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i ++) scanf("%s", s[i]);
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < m; j ++) a[i][j + 1] = s[i][j] - '0';
    }
    for (int i = 1; i <= m; i ++) rt[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (i == j) continue;
            func(i, j);
        }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= m; i ++) {
        int x = find_rt(i);
        vis[x] = 1;
    }
    int ans = 1;
    for (int i = 1; i <= m; i ++) if (vis[i]) {
        ans = 1ll * ans * b[sz[i]] % mod;
    }
    printf("%d\n", ans);
    return 0;
}