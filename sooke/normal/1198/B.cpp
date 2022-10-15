#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, now, a[N], opt[N], u[N], x[N];
bool vis[N];

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    m = read();
    for (int i = 0; i < m; i++) {
        opt[i] = read();
        if (opt[i] == 1) {
            u[i] = read() - 1; x[i] = read();
            a[u[i]] = x[i];
        } else {
            x[i] = read();
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        if (opt[i] == 1) {
            if (!vis[u[i]]) {
                vis[u[i]] = true;
                a[u[i]] = std::max(a[u[i]], now);
            }
        } else {
            now = std::max(now, x[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", vis[i] ? a[i] : std::max(a[i], now));
    }
    return 0;
}