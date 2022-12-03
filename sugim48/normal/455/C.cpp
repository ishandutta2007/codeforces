#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ll_i;
struct edge { int u, v; ll w; };

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return (v[x] < 0) ? x : (v[x] = find(v[x])); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (-v[x] < -v[y]) swap(x, y);
			v[x] += v[y]; v[y] = x;
		}
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

vector<int> adj[300000];
int a[300000];
bool vis[300000];
int maxu, maxl;

void hoge(int u, int l) {
	vis[u] = true;
	if (l > maxl) {
		maxl = l;
		maxu = u;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (vis[v]) continue;
		hoge(v, l + 1);
	}
	vis[u] = false;
}

int main() {
	int n, m, q; cin >> n >> m >> q;
	union_find uf(n);
	for (; m > 0; m--) {
		int a, b; scanf("%d%d", &a, &b);
		uf.unite(a - 1, b - 1);
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	fill(a, a + n, -1);
	for (int u = 0; u < n; u++) {
		int v = uf.find(u);
		if (a[v] >= 0) continue;
		maxl = -1;
		hoge(v, 0);
		maxl = -1;
		hoge(maxu, 0);
		a[v] = maxl;
	}
	for (; q > 0; q--) {
		int z, x, y; scanf("%d", &z);
		if (z == 1) {
			scanf("%d", &x);
			int u = uf.find(x - 1);
			printf("%d\n", a[u]);
		}
		else if (z == 2) {
			scanf("%d%d", &x, &y);
			if (uf.same(x - 1, y - 1)) continue;
			int u = uf.find(x - 1);
			int v = uf.find(y - 1);
			uf.unite(x - 1, y - 1);
			int t = uf.find(x - 1);
			a[t] = max((a[u] + 1) / 2 + (a[v] + 1) / 2 + 1, max(a[u], a[v]));
		}
	}
}