#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807
#define INF MAXINT
#define lol long long

inline char letter() {
	char c = getchar();
	while (c < 'A' || c > 'Z') {
		c = getchar();
	}
	return c;
}
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

#define MAXN 1000005

int n, m, id[MAXN], ls[MAXN], rs[MAXN], val[MAXN], ans[MAXN];
char opt[MAXN];
bool lef[MAXN];

void dfs1(int u) {
	if (id[u] > 0) {
		return;
	}
	if (opt[u] == 'N') {
		dfs1(ls[u]);
		val[u] = !val[ls[u]];
	} else if (opt[u] == 'A') {
		dfs1(ls[u]), dfs1(rs[u]);
		val[u] = val[ls[u]] & val[rs[u]];
	} else if (opt[u] == 'O') {
		dfs1(ls[u]), dfs1(rs[u]);
		val[u] = val[ls[u]] | val[rs[u]];
	} else if (opt[u] == 'X') {
		dfs1(ls[u]), dfs1(rs[u]);
		val[u] = val[ls[u]] ^ val[rs[u]];
	}
}
void dfs2(int u, int w, int res) {
	if (id[u] > 0) {
		if (val[u] != w) {
			ans[id[u]] = res;
		}
		return;
	}
	if (w == 0) {
		if (opt[u] == 'N') {
			dfs2(ls[u], 1, res);
		} else if (opt[u] == 'A') {
			if (val[rs[u]] == 0) {
				dfs2(ls[u], 0, res);
				dfs2(ls[u], 1, res);
			} else {
				dfs2(ls[u], 0, res);
			}
			if (val[ls[u]] == 0) {
				dfs2(rs[u], 0, res);
				dfs2(rs[u], 1, res);
			} else {
				dfs2(rs[u], 0, res);
			}
		} else if (opt[u] == 'O') {
			if (val[rs[u]] == 0) {
				dfs2(ls[u], 0, res);
			}
			if (val[ls[u]] == 0) {
				dfs2(rs[u], 0, res);
			}
		} else if (opt[u] == 'X') {
			if (val[rs[u]] == 0) {
				dfs2(ls[u], 0, res);
			} else {
				dfs2(ls[u], 1, res);
			}
			if (val[ls[u]] == 0) {
				dfs2(rs[u], 0, res);
			} else {
				dfs2(rs[u], 1, res);
			}
		}
	} else {
		if (opt[u] == 'N') {
			dfs2(ls[u], 0, res);
		} else if (opt[u] == 'A') {
			if (val[rs[u]] == 1) {
				dfs2(ls[u], 1, res);
			}
			if (val[ls[u]] == 1) {
				dfs2(rs[u], 1, res);
			}
		} else if (opt[u] == 'O') {
			if (val[rs[u]] == 0) {
				dfs2(ls[u], 1, res);
			} else {
				dfs2(ls[u], 0, res);
				dfs2(ls[u], 1, res);
			}
			if (val[ls[u]] == 0) {
				dfs2(rs[u], 1, res);
			} else {
				dfs2(rs[u], 0, res);
				dfs2(rs[u], 1, res);
			}
		} else if (opt[u] == 'X') {
			if (val[rs[u]] == 0) {
				dfs2(ls[u], 1, res);
			} else {
				dfs2(ls[u], 0, res);
			}
			if (val[ls[u]] == 0) {
				dfs2(rs[u], 1, res);
			} else {
				dfs2(rs[u], 0, res);
			}
		}
	}
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		opt[i] = letter();
		if (opt[i] == 'I') {
			id[i] = ++m;
			val[i] = read();
		} else if (opt[i] == 'N') {
			ls[i] = read();
		} else if (opt[i] == 'A') {
			ls[i] = read(), rs[i] = read();
		} else if (opt[i] == 'O') {
			ls[i] = read(), rs[i] = read();
		} else if (opt[i] == 'X') {
			ls[i] = read(), rs[i] = read();
		}
	}
	dfs1(1);
	dfs2(1, 0, 0);
	dfs2(1, 1, 1);
	for (int i = 1; i <= m; i++) {
		printf("%d", ans[i]);
	}
	return 0;
}

// By Sooke.