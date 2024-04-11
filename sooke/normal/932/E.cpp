#include <cstdio>

const int maxN = 5005, p = 1e9 + 7;

int n, m, now = 1, ans, s[maxN][maxN], fac[maxN], inv[maxN];

inline int power(int x, int y) { int res = 1; for (; y; y >>= 1, x = (long long) x * x % p) { if (y & 1) { res = (long long) res * x % p; } } return res; }

int main() {
    scanf("%d%d", &n, &m); s[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) { s[i][j] = ((long long) s[i - 1][j] * j + s[i - 1][j - 1]) % p; }
    }
    for (int i = 0; i <= m; i++) {
        ans = (ans + (long long) s[m][i] * power(2, n - i) % p * now) % p;
        if (n - i > 0) { now = (long long) now * (n - i) % p; } else { break; }
    }
    printf("%d\n", ans);
    return 0;
}