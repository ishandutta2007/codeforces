#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define lol long long

inline int read() {
	char c = getchar();
	int n = 0, f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -n : n;
}

#define MAXN 200005

int n, m, t, fth[MAXN], tt[MAXN], ord[MAXN], siz[MAXN];

struct List {
	int len, fst[MAXN], nxt[MAXN << 1], v[MAXN << 1];
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

List L;

void dfs(int u) {
	tt[u] = ++t;
	ord[t] = u;
	siz[u] = 1;
	for (int i = L.fst[u]; i != -1; i = L.nxt[i]) {
		int v = L.v[i];
		dfs(v);
		siz[u] += siz[v];
	}
}

int main() {
	n = read(), m = read();
	L.init(n);
	for (int i = 2; i <= n; i++) {
		fth[i] = read();
	}
	for (int i = n; i >= 2; i--) {
		L.insert(fth[i], i);
	}
	dfs(1);
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		if (y > siz[x]) {
			printf("-1\n");
		} else {
			printf("%d\n", ord[tt[x] + y - 1]);
		}
	}
	return 0;
}