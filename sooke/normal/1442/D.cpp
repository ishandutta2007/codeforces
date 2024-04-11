#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 3e3 + 5;

int n, m, len[N];
long long ans;
std::vector<long long> a[N];

void solve(int l, int r, std::vector<long long> f) {
    if (l + 1 >= r) {
        int i = l;
        for (int j = 0; j <= m && j <= len[i]; j++) {
            ans = std::max(ans, a[i][j] + f[m - j]);
        }
        return;
    }
    std::vector<long long> g;
    int mid = l + r >> 1;
    g = f;
    for (int i = mid; i < r; i++) {
        for (int j = m; j >= len[i]; j--) {
            g[j] = std::max(g[j], g[j - len[i]] + a[i][len[i]]);
        }
    }
    solve(l, mid, g);
    g = f;
    for (int i = l; i < mid; i++) {
        for (int j = m; j >= len[i]; j--) {
            g[j] = std::max(g[j], g[j - len[i]] + a[i][len[i]]);
        }
    }
    solve(mid, r, g);
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; i++) {
        len[i] = read();
        a[i].resize(len[i] + 1);
        for (int j = 1; j <= len[i]; j++) {
            a[i][j] = read(); a[i][j] += a[i][j - 1];
            if (j <= m) { ans = std::max(ans, a[i][j]); }
        }
    }
    std::vector<long long> f;
    f.resize(m + 1);
    solve(0, n, f);
    printf("%lld\n", ans);
    return 0;
}