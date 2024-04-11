#include <cstdio>

#define Maxn 100005
#define Maxe 200005

#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))

inline int read() {
	char c = getchar();
	int n = 0;
	while (c < '0' || c > '9') {
		c = getchar();
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
	inline void connect(int _u, int _v) {
		insert(_u, _v);
		insert(_v, _u);
	}
};

List L;
int n, m, lg, ans, dep[Maxn], siz[Maxn], f[17][Maxn];

void dfs(int u, int fth) {
	dep[u] = dep[fth] + 1;
	siz[u] = 1;
	f[0][u] = fth;
	for (int i = 1; i <= lg; i++) {
		f[i][u] = f[i - 1][f[i - 1][u]];
	}
	for (int i = L.fst[u]; i != -1; i = L.nxt[i]) {
		int v = L.v[i];
		if (v != fth) {
			dfs(v, u);
			siz[u] += siz[v];
		}
	}
}

inline int up(int d, int dec) {
	for (int i = lg; i >= 0; i--) {
		if ((1 << i) <= dec) {
			dec -= 1 << i;
			d = f[i][d];
		}
	}
	return d;
}

inline int getLca(int u, int v, int &us, int &vs) {
	u = up(u, dep[u] - dep[v]);
	if (u == v) {
		return u;
	}
	for (int i = lg; i >= 0; i--) {
		if (f[i][u] != f[i][v]) {
			u = f[i][u];
			v = f[i][v];
		}
	}
	us = u;
	vs = v;
	return f[0][u];
}

int main() {
	n = read();
	L.init(n);
	for (int i = 2; i <= n; i++) {
		int u = read(), v = read();
		L.connect(u, v);
	}
	while ((1 << lg + 1) < n) {
		lg++;
	}
	dfs(1, 0);
	m = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), lca, dis, us = 0, vs = 0;
		if (dep[u] < dep[v]) {
			Swap(u, v);
		}
		lca = getLca(u, v, us, vs);
		dis = dep[u] + dep[v] - dep[lca] - dep[lca];
		if (dis & 1) {
			ans = 0;
		} else {
			if (dep[u] == dep[v]) {
				ans = siz[1] - siz[us] - siz[vs];
			} else {
				int mid = up(u, dis / 2), midf = up(u, dis / 2 - 1);
				ans = siz[mid] - siz[midf];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

// By Sooke.
// CF519E A and B and Lecture Rooms.