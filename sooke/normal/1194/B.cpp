#include <bits/stdc++.h>

inline int read() {
    char c; for (c = getchar(); c != '.' && c != '*'; c = getchar()); return c;
}

const int N = 1e6;

int T, n, m, ans, f[N], g[N];
std::vector<char> c[N];

int main() {
    for (scanf("%d", &T); T; T--) {
        scanf("%d%d", &n, &m); ans = 1e9;
        for (int i = 0; i < n; i++) {
            c[i].resize(m);
            for (int j = 0; j < m; j++) { c[i][j] = read(); }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i] = g[j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '.') { f[i]++; g[j]++; }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '.') { ans = std::min(ans, f[i] + g[j] - 1); }
                else { ans = std::min(ans, f[i] + g[j]); }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}