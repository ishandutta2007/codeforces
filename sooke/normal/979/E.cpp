#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int p = 1e9 + 7, maxN = 200005;

inline int power(int x, int y) { if (y < 0) { return 0; } int res = 1; for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } } return res; }

int n, m, c, k, ans, f[2][2][2][maxN];

int main() {
    n = read(); m = read(); f[0][0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        c = read();
        if (c == -1 || c == 0) {
            for (int j = 0; j <= 1; j++) {
                for (int x = 0; x <= 1; x++) {
                    for (int y = 0; y <= 1; y++) {
                        if (x) { k = 1ll * f[j][x][y][i] * power(2, i - 1) % p; (f[j][x][y][i + 1] += k) %= p; }
                        else { k = 1ll * f[j][x][y][i] * power(2, i) % p; }
                        (f[j ^ 1][x][1][i + 1] += k) %= p;
                    }
                }
            }
        }
        if (c == -1 || c == 1) {
            for (int j = 0; j <= 1; j++) {
                for (int x = 0; x <= 1; x++) {
                    for (int y = 0; y <= 1; y++) {
                        if (y) { k = 1ll * f[j][x][y][i] * power(2, i - 1) % p; (f[j][x][y][i + 1] += k) %= p; }
                        else { k = 1ll * f[j][x][y][i] * power(2, i) % p; }
                        (f[j ^ 1][1][y][i + 1] += k) %= p;
                    }
                }
            }
        }
    }
    for (int x = 0; x <= 1; x++) {
        for (int y = 0; y <= 1; y++) { (ans += f[m][x][y][n]) %= p; }
    }
    printf("%d\n", ans);
    return 0;
}