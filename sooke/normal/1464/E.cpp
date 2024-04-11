#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353;

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

const int N = 2e5 + 5;

int n, m, all, ans, sg[N], deg[N], f[N];
std::set<int> set[N]; 
std::vector<int> e[N];

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e[v].push_back(u); deg[u]++;
    }
    std::queue<int> que;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 0) { que.push(u); }
    }
    for (; !que.empty(); que.pop()) {
        int u = que.front();
        for (; set[u].count(sg[u]); sg[u]++);
        for (auto v : e[u]) {
            deg[v]--;
            if (deg[v] == 0) { que.push(v); }
            set[v].insert(sg[u]);
        }
    }
    all = 131072;
    int inv = power(n + 1, mod - 2);
    for (int u = 1; u <= n; u++) {
        f[sg[u]] = add(f[sg[u]], inv);
    }
    for (int len = 1; len < all; len *= 2) {
        for (int i = 0; i < all; i += len * 2) {
            for (int j = 0; j < len; j++) {
                int x = f[i + j], y = f[i + j + len];
                f[i + j] = add(x, y); f[i + j + len] = sub(x, y);
            }
        }
    }
    for (int i = 0; i < all; i++) {
        f[i] = power(sub(1, f[i]), mod - 2);
        ans = add(ans, f[i]);
    }
    ans = 1ll * ans * power(all, mod - 2) % mod;
    ans = 1ll * ans * inv % mod;
    ans = sub(1, ans);
    printf("%d\n", ans);
    return 0;
}