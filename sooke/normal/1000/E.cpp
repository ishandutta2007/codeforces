#include <cstdio>
#include <cstring>

#define Maxn 300005 
#define Maxe 600005

#define Abs(x) ((x) < 0 ? -(x) : (x))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))

inline int read() {
	char c = getchar();
	int n = 0;
	while (c < '0' || c > '9') {
		c = getchar();;
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return n;
}

struct List {
	int len, fst[Maxn], nxt[Maxe], v[Maxe];
	inline void init(int d) {
		for (int i = 1; i <= d; i++) {
			fst[i] = -1;
		}
		len = 0;
	}
	inline void insert(int _u, int _v) {
		v[len] = _v;
		nxt[len] = fst[_u];
		fst[_u] = len++;
	}
};

List L, G;
int n, m;
int t, vs, dfn[Maxn], low[Maxn], stc[Maxn], col[Maxn];
int ans, q[Maxn], dep[Maxn];
bool ins[Maxn];

void Tarjan(int u, int fth) {
	dfn[u] = low[u] = ++t;
	ins[u] = true;
	stc[++vs] = u;
	int vt = vs;
	for (int i = L.fst[u]; i != -1; i = L.nxt[i]) {
		int v = L.v[i];
		if (v != fth) {
			if (dfn[v] == 0) {
				Tarjan(v, u);
				low[u] = Min(low[u], low[v]);
			} else if (ins[v]) {
				low[u] = Min(low[u], dfn[v]);
			}
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

void Bfs(int d) {
	ans = 0;
	memset(dep, 0, sizeof(dep));
	dep[0] = -1;
	dep[d] = 1;
	q[1] = d;
	for (int l = 1, r = 1; l <= r; l++) {
		int u = q[l];
		if (dep[ans] < dep[u]) {
			ans = u;
		}
		for (int i = G.fst[u]; i != -1; i = G.nxt[i]) {
			int v = G.v[i];
			if (dep[v] == 0) {
				dep[v] = dep[u] + 1;
				q[++r] = v;
			}
		}
	}
}

int main() {
	n = read(), m = read();
	L.init(n);
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		L.insert(u, v);
		L.insert(v, u);
	}
	for (int i = 1; i <= n; i++) {
		if (dfn[i] == 0) {
			Tarjan(i, 0);
		}
	}
	G.init(n);
	for (int u = 1; u <= n; u++) {
		for (int i = L.fst[u]; i != -1; i = L.nxt[i]) {
			int v = L.v[i];
			if (col[u] != col[v]) {
				G.insert(col[u], col[v]);
			}
		}
	}
	Bfs(col[1]);
	Bfs(ans);
	printf("%d\n", dep[ans] - 1);
	return 0;
}

// By Sooke.
// CF1000E We Need More Bosses.