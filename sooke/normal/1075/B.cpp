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

const int maxN = 200005;

int n, m, num, a[maxN], f[maxN], dis[maxN], x[maxN], ans[maxN];

int main() {
    std::cin >> n >> m; x[0] = -1e9; x[m + 1] = 2e9;
    for (int i = 1; i <= n + m; i++) { a[i] = read(); }
    for (int i = 1; i <= n + m; i++) { f[i] = read(); }
    for (int i = 1, j = 0; i <= n + m; i++) {
        if (f[i] == 0) { dis[i] = j; }
        else { x[++j] = a[i]; }
    }
    for (int i = n + m, j = m + 1; i >= 1; i--) {
        if (f[i] == 0) {
            if (a[i] - x[dis[i]] > x[j] - a[i]) { dis[i] = j; }
        } else { j--; }
    }
    for (int i = 1; i <= n + m; i++) {
        if (f[i] == 0) { ans[dis[i]]++; }
    }
    for (int i = 1; i <= m; i++) { printf("%d ", ans[i]); }
    return 0;
} //