#include <cstdio>
#define Maxn 10001
#define Min(x, y) ((x) < (y) ? (x) : (y))

struct List {
	int len, fst[Maxn], nxt[Maxn], v[Maxn];
	inline void Init(int d) {
		for (int i = 1; i <= d; i++) {
			fst[i] = -1;
		}
		len = 0;
	}
	inline void Insert(int _u, int _v) {
		v[len] = _v;
		nxt[len] = fst[_u];
		fst[_u] = len++;
	}
};

List L, G;
int n, m, s, ans;
int t, vs, dfn[Maxn], low[Maxn], stc[Maxn], col[Maxn], deg[Maxn];
bool ins[Maxn], vis[Maxn];

void Tarjan(int u) {
	dfn[u] = low[u] = ++t;
	stc[++vs] = u;
	ins[u] = true;
	int vt = vs;
	for (int i = L.fst[u]; i != -1; i = L.nxt[i]) {
		int v = L.v[i];
		if (dfn[v] == 0) {
			Tarjan(v);
			low[u] = Min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = Min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		for (int i = vt; i <= vs; i++) {
			col[stc[i]] = u;
			ins[stc[i]] = false;
		}
		vs = vt - 1;
	}
}

void Dfs(int u) {
    vis[u] = true;
    for (int i = G.fst[u]; i != -1; i = G.nxt[i]){
        int v = G.v[i];
        if (!vis[v]) {
            Dfs(v);
        }
    }
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	L.Init(n);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		L.Insert(u, v);
	}
	for (int i = 1; i <= n; i++) {
		if (dfn[i] == 0) {
			Tarjan(i);
		}
	}
	G.Init(n);
	for (int u = 1; u <= n; u++) {
		for (int i = L.fst[u]; i != -1; i = L.nxt[i]) {
			int v = L.v[i];
			if (col[u] != col[v]) {
				G.Insert(col[u], col[v]);
				deg[col[v]]++;
			}
		}
	}
	Dfs(col[s]);
	for (int i = 1; i <= n; i++) {
		if (col[i] == i && deg[i] == 0 && !vis[i]) {
			ans++;
			Dfs(i);
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF999E Reachability from the Capital.