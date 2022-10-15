#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 1e6 + 5;

int n, m, ans0, a[N], c, col[N], b[N], siz[N], anc[N], bel[N], eu[N], ev[N];
bool used[N];
std::vector<int> ans, p, e[N];

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

void dfs(int u) {
    if (col[u]) { return; }
    col[u] = c; b[c] |= a[u]; siz[c]++;
    for (auto v : e[u]) { dfs(v); }
}

int main() {
    n = read(); m = read();
    for (int u = 1; u <= m * 2; u++) {
        anc[u] = u;
    }
    for (int i = 0; i < n; i++) {
        int k = read();
        if (k == 1) {
            int u = read(); eu[i] = u; ev[i] = -1;
            a[u] = 1; bel[u] = std::min(bel[u], i + 1);
        } else {
            int u = read(), v = read(); eu[i] = u; ev[i] = v;
            e[u].push_back(v); e[v].push_back(u);
        }
    }
    ans0 = 1;
    for (int u = 1; u <= m; u++) {
        if (col[u]) { continue; }
        c++; dfs(u);
        if (b[c]) {
            ans0 = 1ll * ans0 * power(2, siz[c]) % mod;
        } else {
            ans0 = 1ll * ans0 * power(2, siz[c] - 1) % mod;
            anc[find(m + c)] = find(u);
        }
    }
    for (int i = 0; i < n; i++) {
        if (ev[i] == -1) {
            int u = eu[i], v = m + col[u];
            if (find(u) != find(v)) {
                anc[find(u)] = find(v);
                ans.push_back(i + 1);
            }
        } else {
            int u = eu[i], v = ev[i];
            if (find(u) != find(v)) {
                anc[find(u)] = find(v);
                ans.push_back(i + 1);
            }
        }
    }
    printf("%d %d\n", ans0, ans.size());
    std::sort(ans.begin(), ans.end());
    for (auto u : ans) { printf("%d ", u); }
    return 0;
}