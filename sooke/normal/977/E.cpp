#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 200005
#define Maxe 400005

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

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
int n, m, ans, deg[Maxn];
bool vis[Maxn];

void dfs(int u, int f, int st) {
	if (vis[u] && u == st) {
		ans++;
		return;
	}
	vis[u] = true;
	for (int i = L.fst[u]; i != -1; i = L.nxt[i]) {
		int v = L.v[i];
		if (f != v && deg[v] == 2) {
			dfs(v, u, st);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	L.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		L.connect(u, v);
		deg[u]++;
		deg[v]++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 2 && !vis[i]) {
			dfs(i, 0, i);
		}
	}
	printf("%d\n", ans / 2);
	return 0;
}

// By Sooke.
// CF977E Cyclic Components.