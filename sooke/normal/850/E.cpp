#include <cstdio>

const int maxM = 21, maxN = 1 << maxM, p = 1e9 + 7;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x >= 0 ? x : x + p; }
inline int dv2(int x) { return x & 1 ? (x + p) >> 1 : x >> 1; }

int m, n, ans, a[maxN], g[maxM];
char str[maxN];

void fwt(int f[], int sgn) {
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; j++) {
                int x = f[i + j], y = f[i + j + len];
                f[i + j] = sgn == 1 ? add(x, y) : dv2(add(x, y)); f[i + j + len] = sgn == 1 ? sub(x, y) : dv2(sub(x, y));
            }
        }
    }
}

int main() {
    scanf("%d%s", &m, str); n = 1 << m;
    for (int i = g[0] = 1; i <= m; i++) { g[i] = g[i - 1] * 2 % p; }
    for (int i = 0; i < n; i++) { a[i] = str[i] ^ 49; } fwt(a, 1);
    for (int i = 0; i < n; i++) { a[i] = (long long) a[i] * a[i] % p; } fwt(a, -1);
    for (int i = 0; i < n; i++) { ans = add(ans, (long long) a[i] * g[m - __builtin_popcount(i)] % p); }
    printf("%d\n", (long long) ans * 3 % p);
    return 0;
}