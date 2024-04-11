#include <cstdio>

const int p = 998244353;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x >= 0 ? x : x + p; }
inline int getInv(int x, int hsh) {
    static int res, inv[6001]; res = inv[hsh];
    if (res) { return res; } res = 1;
    for (int y = p - 2; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } }
    return inv[hsh] = res;
}

const int N = 200005, M = 3005;

int n, m, x, y, inv, sum[2], a[N], w[N], f[2][M][M];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); }
    for (int i = 1; i <= n; i++) { scanf("%d", &w[i]); sum[a[i]] = add(sum[a[i]], w[i]); }
    for (int i = m; i >= 0; i--) {
        x = add(sum[1], i); f[0][i][m - i] = f[1][i][m - i] = 1;
        for (int j = m - i - 1; j >= 0; j--) {
            y = sub(sum[0], j); inv = getInv(add(x, y), i + m - j);
            f[0][i][j] = (f[0][i][j] + 1ll * f[0][i + 1][j] * x + 1ll * f[0][i][j + 1] * sub(y, 1)) % p * inv % p;
            f[1][i][j] = (f[1][i][j] + 1ll * f[1][i][j + 1] * y + 1ll * f[1][i + 1][j] * add(x, 1)) % p * inv % p;
        }
    }
    for (int i = 1; i <= n; i++) { printf("%I64d\n", 1ll * w[i] * f[a[i]][0][0] % p); }
    return 0;
}