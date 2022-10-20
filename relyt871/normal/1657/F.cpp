#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 400005;
const int MAXM = MAXN * 10;

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

//2SAT
inline int other(int id) {
    if (id & 1) return id + 1;
    else return id - 1;
}

int tot;
vector<int> g[MAXM];
int dfn[MAXM], low[MAXM], clk;
int stk[MAXM], top, instk[MAXM];
int scc, bel[MAXM];

inline void AddEdge(int u, int v) {
//cerr << "add " << u << " " <<v <<endl;
    g[u].push_back(v);
}

void Tarjan(int u) {
	dfn[u] = low[u] = ++clk;
	stk[++top] = u; instk[u] = 1;
	for (auto v : g[u]) {
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (instk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++scc; int x;
		do {
			x = stk[top--];
			instk[x] = 0;
			bel[x] = scc;
		} while (x != u);
	}
}

/*************************************************/

char s[MAXN], ans[MAXN];
int n, q, U[MAXN], V[MAXN], fa[MAXN], dep[MAXN], ok[MAXN << 1];
vector<int> tree[MAXN];
vector<pii> con[MAXN];

void DFS(int u) {
    for (auto v : tree[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        DFS(v);
    }
}

void Run(int id, int u, int v) {
    int len = strlen(s + 1);
    int su = 0, sv = 0;
    while (u != v) {
        if (dep[u] > dep[v]) {
            con[u].push_back(make_pair(s[1 + su], id * 2 - 1));
            con[u].push_back(make_pair(s[len - su], id * 2));
            u = fa[u];
            ++su;
        } else {
            con[v].push_back(make_pair(s[len - sv], id * 2 - 1));
            con[v].push_back(make_pair(s[1 + sv], id * 2));
            v = fa[v];
            ++sv;
        }
    }
    con[u].push_back(make_pair(s[1 + su], id * 2 - 1));
    con[u].push_back(make_pair(s[len - su], id * 2));
}

inline int id(int x, int y) {
    return (x - 1) * 3 + y;
}

void Build(vector<pii> &vec) {
    sort(vec.begin(), vec.end());
    int tmp = 0;
    for (int i = 0, j; i < vec.size(); i = j + 1) {
        for (j = i; j < vec.size() - 1 && vec[j + 1].fi == vec[i].fi; ++j);
        ++tmp;
        for (int k = i; k <= j; ++k) {
            AddEdge(vec[k].se, tot + id(tmp, 1));
            AddEdge(tot + id(tmp, 2), other(vec[k].se));
            AddEdge(tot + id(tmp, 3), other(vec[k].se));
        }
    }
    for (int i = 1; i <= tmp; ++i) {
        if (i > 1) {
            AddEdge(tot + id(i, 1), tot + id(i - 1, 2));
            AddEdge(tot + id(i, 2), tot + id(i - 1, 2));
        }
        if (i < tmp) {
            AddEdge(tot + id(i, 1), tot + id(i + 1, 3));
            AddEdge(tot + id(i, 3), tot + id(i + 1, 3));
        }
    }
    tot += tmp * 3;
}

void solve() {
    read(n); read(q);
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    DFS(1);
    for (int i = 1, x, y; i <= q; ++i) {
        read(x); read(y);
        scanf("%s", s + 1);
        Run(i, x, y);
    }
    tot = q * 2;
    for (int i = 1; i <= n; ++i) {
        if (con[i].size()) {
            Build(con[i]);
        }
    }
    for (int i = 1; i <= tot; ++i) {
        if (!dfn[i]) {
            Tarjan(i);
        }
    }
    for (int i = 1; i <= q; ++i) {
        if (bel[i * 2 - 1] == bel[i * 2]) {
            puts("NO");
            return;
        }
        int rev = (bel[i * 2 - 1] > bel[i * 2]);
        if (rev) ok[i * 2] = 1;
        else ok[i * 2 - 1] = 1;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
        if (!con[i].size()) {
            ans[i] = 't';
        } else {
            for (auto pr : con[i]) {
                if (ok[pr.se]) {
                    ans[i] = pr.fi;
                    break;
                }
            }
        }
        putchar(ans[i]);
    }
    puts("");
}

int main() {
    solve();
    return 0;
}