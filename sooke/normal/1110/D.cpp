#include <cstdio>
#include <cstring>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int maxN = 1000007;

int n, m, ans, max, pre, cur = 1, a[maxN], f[2][9][9];

int main() {
    n = read(); m = read() + 3;
    for (int i = 1; i <= n; i++) { a[read()]++; }
    memset(f[0], 128, sizeof(f[0])); f[0][0][0] = 0;
    for (int i = 1; i <= m; i++, std::swap(pre, cur)) {
        if (a[i] > 8) { ans += (a[i] - 6) / 3; a[i] -= (a[i] - 6) / 3 * 3; }
        memset(f[cur], 128, sizeof(f[cur]));
        for (int j = 0; j <= 8; j++) {
            for (int k = 0; k <= 8; k++) {
                int lim = std::min(std::min(a[i], j), k);
                for (int used = 0; used <= lim; used++) { f[cur][k - used][a[i] - used] = std::max(f[cur][k - used][a[i] - used], f[pre][j][k] + used + (j - used) / 3); }
            }
        }
    }
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) { max = std::max(max, f[pre][i][j]); }
    }
    printf("%d\n", ans + max);
    return 0;
} // Sooke