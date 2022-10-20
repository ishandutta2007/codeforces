#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 300005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, c[MAXN], bcnt[MAXN], ans[MAXN];
int fa[MAXN], dfn[MAXN], out[MAXN], clk, vis[MAXN];
vector<int> tree[MAXN];

void DFS(int u) {
    dfn[u] = ++clk;
    for (auto v : tree[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        DFS(v);
    }
    out[u] = clk;
}

inline int countBlack(int u, int v) {
    if (u == fa[v]) {
        return bcnt[out[v]] - bcnt[dfn[v] - 1];
    } else {
        return bcnt[n] - (bcnt[out[u]] - bcnt[dfn[u] - 1]);
    }
}

inline void Cov(int l, int r, int d) {
    ans[l] += d;
    ans[r + 1] -= d;
}

inline void Update(int u, int v, int d) {
    if (u == fa[v]) {
        Cov(dfn[v], out[v], d);
    } else {
        Cov(1, n, d);
        Cov(dfn[u], out[u], -d);
    }
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(c[i]);
    }
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    DFS(1);
    for (int i = 1; i <= n; ++i) {
        if (c[i]) ++bcnt[dfn[i]];
    }
    for (int i = 1; i <= n; ++i) {
        bcnt[i] += bcnt[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i]) {
            for (auto v : tree[i]) {
                if (countBlack(i, v)) {
                    Update(i, v, -1);
                    Cov(1, n, 1);
                }
                if (c[v] == 0 && !vis[v]) {
                    vis[v] = 1;
                    int hb = 0, bp = 0;
                    for (auto u : tree[v]) {
                        if (u != i && countBlack(v, u)) {
                            ++hb;
                            bp = u;
                        }
                    }
                    if (hb >= 2) {
                        Update(v, i, -1);
                        Cov(1, n, 1);
                    } else if (hb == 1) {
                        Update(v, i, -1);
                        Update(v, bp, -1);
                        Cov(1, n, 1);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] += ans[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", c[i] || ans[dfn[i]]);
    }
    printf("\n");
}

int main() {
    solve();
	return 0;
}