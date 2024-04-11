#include <bits/stdc++.h>

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}

const int N = 25005, C = 10;

int n, m, ans, f[N][2][2][2], g[N][2][2][2];
char str[N], a[N], b[N];

struct AcAutomaton {
    int tot, son[N][C], fail[N];
    bool end[N];

    AcAutomaton() { tot = 1; memset(son[0], -1, C * 4); }

    void insert(int x) {
        static int u = 1;
        if (x == -1) { end[u] = true; u = 1; return; }
        if (son[u][x] == 0) { son[u][x] = ++tot; }
        u = son[u][x];
    }
    
    void build() {
        std::queue<int> que;
        for (int x = 0; x < C; x++) {
            if (son[1][x] > 0) {
                que.push(son[1][x]); fail[son[1][x]] = 1;
            } else {
                son[1][x] = 1;
            }
        }
        for (; !que.empty(); que.pop()) {
            int u = que.front();
            for (int x = 0; x < C; x++) {
                int v = son[u][x], w;
                if (v > 0) {
                    que.push(v); fail[v] = son[fail[u]][x];
                } else {
                    son[u][x] = son[fail[u]][x];
                }
            }
        }
    }
} aam;

int main() {
    scanf("%s%s%s", str, a, b);
    n = strlen(str); m = strlen(a);
    for (int i = m / 2; i <= n; i++) {
        for (int j = i - m / 2; j < i; j++) {
            aam.insert(str[j] - '0');
        }
        aam.insert(-1);
    }
    aam.build();
    f[1][0][1][1] = 1;
    for (int i = 0; i < m; i++) {
        memcpy(g, f, sizeof(f));
        memset(f, 0, sizeof(f));
        int l = a[i] - '0', r = b[i] - '0';
        for (int x = 0; x < C; x++) {
            for (int u = 1; u <= aam.tot; u++) {
                for (int o = 0; o < 2; o++) {
                    int v = aam.son[u][x];
                    int _o = o || aam.end[v];
                    for (int p = 0; p < 2; p++) {
                        for (int q = 0; q < 2; q++) {
                            if (p == 1 && x < l) { continue; }
                            if (q == 1 && x > r) { continue; }
                            int _p = p && x == l;
                            int _q = q && x == r;
                            f[v][_o][_p][_q] = add(f[v][_o][_p][_q], g[u][o][p][q]);
                        }
                    }
                }
            }
        }
    }
    for (int u = 1; u <= aam.tot; u++) {
        for (int p = 0; p < 2; p++) {
            for (int q = 0; q < 2; q++) {
                ans = add(ans, f[u][1][p][q]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}