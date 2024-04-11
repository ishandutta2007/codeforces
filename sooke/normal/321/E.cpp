#include <cstdio>
#include <cstring>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int N = 4005, M = 805;

int n, m, a[N][N], w[N][N], f[M][N], s[M][N];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { a[i][j] = read(); }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1]; }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) { w[i - 1][j] = (a[j][j] + a[i - 1][i - 1] - a[i - 1][j] - a[j][i - 1]) >> 1; }
    }
    memset(f, 66, sizeof(f)); f[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        s[i][n + 1] = n;
        for (int j = n; j >= i; j--) {
            for (int k = s[i - 1][j]; k <= s[i][j + 1]; k++) {
                if (f[i][j] > f[i - 1][k] + w[k][j]) { f[i][j] = f[i - 1][k] + w[k][j]; s[i][j] = k; }
            }
        }
    }
    printf("%d\n", f[m][n]);
    return 0;
}