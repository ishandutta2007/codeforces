#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 20004;
const int MAXN = 400005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '0') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, m, k, ans[N];
int id[2][N][11], tot;
vector<int> g[MAXN];

int dfn[MAXN], low[MAXN], clk;
int stk[MAXN], top, instk[MAXN];
int scc, bel[MAXN];

void clear() {
    for (int i = 1; i <= tot; ++i) {
        g[i].clear();
        dfn[i] = low[i] = 0;
    }
    tot = clk = top = scc = 0;
}

inline void Add(int u, int v) {
//cerr << "add " << u << " " << v << endl;
    g[u].push_back(v);
}

void Tarjan(int u) {
    dfn[u] = low[u] = ++clk;
    instk[stk[++top] = u] = 1;
    for (auto v : g[u]) {
        if (!dfn[v]) {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        int x; do {
            instk[x = stk[top--]] = 0;
            bel[x] = scc;
        } while (x ^ u);
    }
}

void solve() {
    clear();
    read(n); read(m); read(k);
    for (int t = 0; t < 2; ++t) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                id[t][i][j] = ++tot;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        Add(id[0][i][1], id[1][i][1]);
        for (int j = 1; j < k; ++j) {
            Add(id[1][i][j + 1], id[1][i][j]);
            Add(id[0][i][j], id[0][i][j + 1]);
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            Add(id[1][i][j], id[1][i + 1][j]);
            Add(id[0][i + 1][j], id[0][i][j]);
        }
    }
    for (int i = 1, t, u, v, x; i <= m; ++i) {
        read(t);
        if (t == 1) {
            read(u); read(x);
            if (x == k) {
                Add(id[1][u][x], id[0][u][x]);
            } else {
                Add(id[1][u][x], id[1][u][x + 1]);
                Add(id[0][u][x + 1], id[0][u][x]);
            }
        } else if (t == 2) {
            read(u); read(v); read(x);
            for (int y = x; y <= k; ++y) {
                Add(id[1][u][y], id[0][u][y]);
                Add(id[1][v][y], id[0][v][y]);
            }
            for (int y = max(1, x + 1 - k); y <= min(k, x); ++y) {
                Add(id[1][u][y], id[0][v][x - y + 1]);
                Add(id[1][v][y], id[0][u][x - y + 1]);
            }
        } else if (t == 3) {
            read(u); read(v); read(x);
            for (int y = 1; y <= x - k; ++y) {
                Add(id[0][u][y], id[1][u][y]);
                Add(id[0][v][y], id[1][v][y]);
            }
            for (int y = max(0, x - k); y <= min(k - 1, x - 1); ++y) {
                Add(id[0][u][y + 1], id[1][v][x - y]);
                Add(id[0][v][y + 1], id[1][u][x - y]);
            }
        }
    }
    for (int i = 1; i <= tot; ++i) {
        if (!dfn[i]) {
            Tarjan(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = 1;
        for (int j = 2; j <= k; ++j) {
            if (bel[id[0][i][j]] == bel[id[1][i][j]]) {
                puts("-1");
                return;
            }
            if (bel[id[1][i][j]] < bel[id[0][i][j]]) {
                ans[i] = j;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}