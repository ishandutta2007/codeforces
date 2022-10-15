#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}
inline int readDigit() {
    char c; for (c = getchar(); !isdigit(c); c = getchar()); return c & 15;
}

const int N = 1e2 + 5, M = 1e6 + 5;

int n, m, a[M], f[M], g[M], lst[N], dis[N][N];

void print(int u) {
    if (u) { print(g[u]); }
    printf("%d ", a[u] + 1);
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) { dis[i][i] = 0; }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = readDigit() ? 1 : 1e8;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    m = read();
    for (int i = 0; i < m; i++) {
        a[i] = read(); a[i]--;
    }
    for (int i = 0; i < n; i++) { lst[i] = -1; }
    for (int i = 0; i < m; i++) {
        if (i) {
            f[i] = 1e9;
            for (int j = 0; j < n; j++) {
                if (a[i] != j && lst[j] != -1 && dis[j][a[i]] == i - lst[j]) {
                    f[i] = std::min(f[i], f[lst[j]] + 1);
                    if (f[i] == f[lst[j]] + 1) { g[i] = lst[j]; }
                }
            }
        } else {
            f[i] = 1;
        }
        lst[a[i]] = i;
    }
    printf("%d\n", f[m - 1]); print(m - 1);
    return 0;
}