#include <cstdio>

const int p = 998244353;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x >= 0 ? x : x + p; }
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } }
    return res;
}

const int N = 2005;

int n, m, num, ans, f[2][N << 1][N];

int main() {
    scanf("%d%d%d", &n, &m, &f[0][0][0]); num = n << 1 | 1;
    for (int i = 1; i <= num; i++) {
        for (int j = 0; j <= n; j++) {
            if (j) {
                f[0][i][j] = f[0][i - 1][j - 1];
                f[1][i][j] = f[1][i - 1][j - 1];
            }
            if (j >= m) { f[1][i][j] = add(f[1][i][j], f[0][i - 1][j]); }
            if (j < n) {
                f[0][i][j] = add(f[0][i][j], (j + 1ll) * f[0][i - 1][j + 1] % p);
                f[1][i][j] = add(f[1][i][j], (j + 1ll) * f[1][i - 1][j + 1] % p);
            }
        }
    }
    ans = 1ll * f[1][num][0] * power(2, n) % p;
    for (int i = n + 1; i <= num; i++) { ans = 1ll * ans * power(i, p - 2) % p; }
    printf("%d\n", ans);
    return 0;
}