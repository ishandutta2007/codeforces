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

const int inf = 1e9;
const int N = 405;

int n, m, f[N], g[N][N], e[N][N], dis[N][N];
std::vector<int> edg[N];

int main() {
    n = read(); m = read();
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            dis[u][v] = u == v ? 0 : inf;
        }
    }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e[u][v] = e[v][u] = 1;
        dis[u][v] = dis[v][u] = 1;
        edg[u].push_back(v); edg[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                dis[u][v] = std::min(dis[u][v], dis[u][i] + dis[i][v]);
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            int ans = 1;
            if (u == v) {
                for (int i = 1; i <= n; i++) {
                    if (dis[u][i] == 0) { continue; }
                    int res = 0;
                    for (int j = 1; j <= n; j++) {
                        if (e[i][j] && dis[u][j] == dis[u][i] - 1) { res++; }
                    }
                    ans = 1ll * ans * res % mod;
                }
            } else {
                int tmp = 0;
                for (int i = 1; i <= n; i++) {
                    if (dis[u][i] == 0 || dis[v][i] == 0) { continue; }
                    int res = 0;
                    if (dis[u][v] != dis[u][i] + dis[v][i]) {
                        for (auto j : edg[i]) {
                            if (dis[u][j] == dis[u][i] - 1 && dis[v][j] == dis[v][i] - 1) {
                                res++;
                            }
                        }
                        ans = 1ll * ans * res % mod;
                    } else {
                        tmp++;
                    }
                }
                if (tmp != dis[u][v] - 1) { ans = 0; }
            }
            printf("%d ", ans);
        }
        printf("\n");
    }
    return 0;
}