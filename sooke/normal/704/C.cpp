#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}

const int N = 1e5 + 5;

struct Edge {
    int v, p, q, i;
};

int n, m, ans[2], deg[N], sgn[N], f[2][2][2], g[2][2][2];
bool vis[N];
std::vector<Edge> e[N];

inline void update(int res0, int res1) {
    int ans0 = ans[0], ans1 = ans[1];
    ans[0] = (1ll * ans0 * res0 + 1ll * ans1 * res1) % mod;
    ans[1] = (1ll * ans0 * res1 + 1ll * ans1 * res0) % mod;
}

void solve(int s) {
    int res[2] = {0, 0};
    memset(f, 0, sizeof(f));
    for (int x = 0; x < 2; x++) {
        f[sgn[s] == -1 || deg[s] == 1 ? 0 : sgn[s] ^ x][x][x] = 1;
    }
    for (int u = s, v, w = -1; ; u = v) {
        memcpy(g, f, sizeof(g));
        memset(f, 0, sizeof(f));
        vis[u] = true;
        Edge e = (Edge) {0, 0, 0, -1};
        for (auto i : ::e[u]) {
            if (i.i != w) { e = i; break; }
        }
        v = e.v; w = e.i;
        if (w == -1) {
            for (int z = 0; z < 2; z++) {
                for (int x0 = 0; x0 < 2; x0++) {
                    for (int y = 0; y < 2; y++) {
                        int zz = z ^ (sgn[u] == -1 ? 0 : sgn[u] ^ y);
                        res[zz] = add(res[zz], g[z][x0][y]);
                    }
                }
            }
            break;
        }
        if (v == s) {
            for (int z = 0; z < 2; z++) {
                for (int x0 = 0; x0 < 2; x0++) {
                    for (int y = 0; y < 2; y++) {
                        int zz = z ^ ((y ^ e.p) | (x0 ^ e.q));
                        res[zz] = add(res[zz], g[z][x0][y]);
                    }
                }
            }
            break;
        }
        for (int z = 0; z < 2; z++) {
            for (int x0 = 0; x0 < 2; x0++) {
                for (int y = 0; y < 2; y++) {
                    for (int x = 0; x < 2; x++) {
                        int zz = z ^ ((y ^ e.p) | (x ^ e.q));
                        f[zz][x0][x] = add(f[zz][x0][x], g[z][x0][y]);
                    }
                }
            }
        }
    }
    update(res[0], res[1]);
}

int main() {
    m = read(); n = read(); ans[0] = 1;
    for (int u = 1; u <= n; u++) { sgn[u] = -1; }
    for (int i = 0; i < m; i++) {
        int k = read();
        if (k == 1) {
            int u = read(), p;
            p = u < 0; u = std::abs(u);
            deg[u]++;
            if (sgn[u] == -1) {
                sgn[u] = p;
            } else {
                vis[u] = true;
                if (sgn[u] == p) {
                    update(2, 0);
                } else {
                    update(0, 2);
                }
            }
        } else {
            int u = read(), v = read(), p, q;
            p = u < 0; u = std::abs(u);
            q = v < 0; v = std::abs(v);
            deg[u]++; deg[v]++;
            e[u].push_back((Edge) {v, p, q, i});
            e[v].push_back((Edge) {u, q, p, i});
        }
    }
    for (int u = 1; u <= n; u++) {
        if (vis[u]) { continue; }
        if (deg[u] == 2 && sgn[u] == -1) { continue; }
        solve(u);
    }
    for (int u = 1; u <= n; u++) {
        if (vis[u]) { continue; }
        solve(u);
    }
    printf("%d\n", ans[1]);
    return 0;
}