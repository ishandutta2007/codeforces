#include <cstdio>

#define Maxn 1000005
#define Maxe 2000005

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
	int len, fst[Maxn], v[Maxe], nxt[Maxe];
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
int n, m, lg, dep[Maxn], f[20][Maxn];
bool used[Maxn];

void dfs(int u, int fth) {
	dep[u] = dep[fth] + 1;
	f[0][u] = fth;
	for (int i = 1; i <= lg; i++) {
		f[i][u] = f[i - 1][f[i - 1][u]];
	}
	for (int i = L.fst[u]; i != -1; i = L.nxt[i]) {
		int v = L.v[i];
		if (v != fth) {
			dfs(v, u);
		}
	}
}

inline int up(int d) {
	for (int i = lg; i >= 0; i--) {
		if (!used[f[i][d]]) {
			d = f[i][d];
		}
	}
	return d;
}

int main() {
	n = read(), m = read();
	m = n - m;
	L.init(n);
	for (int i = 2; i <= n; i++) {
		int u = read(), v = read();
		L.connect(u, v);
	}
	while ((1 << lg + 1) < n) {
		lg++;
	}
	dfs(n, 0);
	used[0] = true;
	for (int i = n ; i >= 1; i--) {
		if (used[i]) {
			continue;
		}
		int u = up(i);
		if (dep[i] - dep[u] + 1 <= m) {
			m -= dep[i] - dep[u] + 1;
			int t = i;
			while (true) {
				used[t] = true;
				if (t == u) {
					break;
				}
				t = f[0][t];
			}
		}
		if (m == 0) {
			break;
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			if (flag) {
				printf("%d", i);
				flag = false;
			} else {
				printf(" %d", i);
			}
		}
	}
	printf("\n");
	return 0;
}

// By Sooke.
// CF980E The Number Games.