#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int maxN = 1005;

int n, m, a[maxN], b[maxN], r[maxN][maxN], s[maxN][maxN], c[maxN][maxN], t[maxN][maxN];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { r[i][j] = s[i][j] = c[j][i] = t[j][i] = read(); }
    }
    for (int i = 1; i <= n; i++) {
        std::sort(r[i] + 1, r[i] + m + 1); a[i] = std::unique(r[i] + 1, r[i] + m + 1) - r[i] - 1;
        for (int j = 1; j <= m; j++) { s[i][j] = std::lower_bound(r[i] + 1, r[i] + a[i] + 1, s[i][j]) - r[i]; }
    }
    for (int i = 1; i <= m; i++) {
        std::sort(c[i] + 1, c[i] + n + 1); b[i] = std::unique(c[i] + 1, c[i] + n + 1) - c[i] - 1;
        for (int j = 1; j <= n; j++) { t[i][j] = std::lower_bound(c[i] + 1, c[i] + b[i] + 1, t[i][j]) - c[i]; }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] - t[j][i] >= 0) { printf("%d ", std::max(a[i], - t[j][i] + s[i][j] + b[j])); }
            else { printf("%d ", std::max(b[j], - s[i][j] + t[j][i] + a[i])); }
        }
        printf("\n");
    }
    return 0;
} //