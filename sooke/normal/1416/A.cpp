#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, a[N], f[N];
std::vector<int> p[N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int k = 0; k <= n; k++) {
            f[k] = 1e9; p[k].clear();
        }
        for (int x = 1; x <= n; x++) {
            p[x].push_back(0);
        }
        for (int i = 1; i <= n; i++) {
            a[i] = read();
            p[a[i]].push_back(i);
        }
        for (int x = 1; x <= n; x++) {
            p[x].push_back(n + 1);
        }
        for (int x = 1; x <= n; x++) {
            int k = 1;
            for (int i = 1; i < p[x].size(); i++) {
                k = std::max(k, p[x][i] - p[x][i - 1]);
            }
            f[k] = std::min(f[k], x);
        }
        int ans = 1e9;
        for (int k = 1; k <= n; k++) {
            ans = std::min(ans, f[k]);
            printf("%d ", ans == 1e9 ? -1: ans);
        }
        printf("\n");
    }
    return 0;
}