#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 105;

int n, c[N], cnt[N], anc[N], d[N][N];
char str[N];
bool can, ned, f[N][N][N], vis[N];
std::vector<int> e[N], _e[N];

bool check() {
    for (int i = 1; i <= n; i++) {
        for (int u = 1; u <= n; u++) {
            for (int v = u + 1; v <= n; v++) {
                bool ok = d[i][u] == d[i][v];
                if (f[i][u][v] != ok) { return false; }
            }
        }
    }
    return true;
}

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

void solve(int u, int fa) {
    if (!can) { return; }
    if (vis[u]) { can = false; return; }
    vis[u] = true;
    _e[u].push_back(fa); _e[fa].push_back(u);
    for (int v = 1; v <= n; v++) {
        if (!can) { return; }
        if (f[u][fa][v] || f[u][v][fa]) {
            solve(v, u);
        }
    }
}

void dfs(int u, int fa, int s, int dd) {
    d[s][u] = dd;
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dfs(v, u, s, dd + 1);
    }
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int u = 1; u <= n; u++) {
            e[u].clear();
            for (int v = u + 1; v <= n; v++) {
                scanf("%s", str + 1);
                for (int i = 1; i <= n; i++) {
                    f[i][u][v] = str[i] == '1';
                }
            }
        }
        if (n == 2) {
            if (f[1][1][2] == 0 && f[2][1][2] == 0) {
                printf("Yes\n1 2\n");
            } else {
                printf("No\n");
            }
            continue;
        } else {
            ned = true;
            int rt = -1;
            for (int s = 1; s <= n; s++) {
                for (int u = 1; u <= n; u++) {
                    for (int v = u + 1; v <= n; v++) {
                        if (f[s][u][v]) { rt = s; break; }
                    }
                }
            }
            if (rt == -1) {
                ned = false;
            } else {
                rt = 1;
                for (int s = 1; s <= n; s++) {
                    cnt[s] = 0;
                    for (int u = 1; u <= n; u++) { anc[u] = u; c[u] = 0; }
                    for (int u = 1; u <= n; u++) {
                        for (int v = u + 1; v <= n; v++) {
                            if (f[s][u][v] && find(u) != find(v)) {
                                anc[find(u)] = find(v);
                            }
                        }
                    }
                    for (int u = 1; u <= n; u++) {
                        c[find(u)]++;
                    }
                    for (int u = 1; u <= n; u++) {
                        cnt[s] = std::max(cnt[s], c[u]);
                    }
                    if (cnt[s] > cnt[rt]) { rt = s; }
                }
                if (ned) {
                    ned = false;
                    int t = cnt[rt];
                    for (int i = 1; i <= n; i++) {
                        if (ned) { break; }
                        if (cnt[i] != t) { continue; }
                        rt = i;
                        for (int u = 1; u <= n; u++) { anc[u] = u; }
                        for (int u = 1; u <= n; u++) {
                            for (int v = u + 1; v <= n; v++) {
                                if (f[rt][u][v] && find(u) != find(v)) {
                                    anc[find(u)] = find(v);
                                }
                            }
                        }
                        for (int s = 1; s <= n; s++) {
                            std::vector<int> son;
                            for (int u = 1; u <= n; u++) {
                                if (find(u) == s) { son.push_back(u); }
                            }
                            if (son.size() <= 1) { continue; }
                            can = true;
                            for (int u = 1; u <= n; u++) {
                                vis[u] = false;
                                _e[u].clear();
                            }
                            vis[rt] = true;
                            for (auto u : son) { solve(u, rt); }
                            for (int u = 1; u <= n; u++) {
                                if (!vis[u]) { can = false; break; }
                            }
                            if (can) {
                                for (int u = 1; u <= n; u++) {
                                    e[u] = _e[u];
                                }
                                for (int s = 1; s <= n; s++) {
                                    dfs(s, 0, s, 0);
                                }
                                if (!check()) { continue; }
                                ned = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (ned) {
                printf("Yes\n");
                for (int u = 1; u <= n; u++) {
                    for (auto v : e[u]) {
                        if (v > u) { printf("%d %d\n", u, v); }
                    }
                }
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}