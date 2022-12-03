#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll x; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

vector<edge> G[200000];
int parent[21][200000];
int depth[200000];
ll x[200000];
 
void dfs(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i].v != p) {
			x[G[v][i].v] = G[v][i].x;
			dfs(G[v][i].v, v, d + 1);
		}
}
 
void init(int V) {
	dfs(0, -1, 0);
	for (int k = 0; k + 1 < 21; k++)
		for (int v = 0; v < V; v++)
			if (parent[k][v] < 0) parent[k + 1][v] = -1;
			else parent[k + 1][v] = parent[k][parent[k][v]];
}
 
int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	for (int k = 0; k < 21; k++)
		if ((depth[v] - depth[u]) >> k & 1)
			v = parent[k][v];
	if (u == v) return u;
	for (int k = 21 - 1; k >= 0; k--)
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	return parent[0][u];
}

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return (v[x] < 0) ? x : (v[x] = find(v[x])); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (depth[x] > depth[y]) swap(x, y);
			v[x] += v[y]; v[y] = x;
		}
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	int n, m; cin >> n >> m;
	vector<int> U(n - 1), V(n - 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v; ll x; scanf("%d%d%I64d", &u, &v, &x);
		u--; v--;
		G[u].push_back(edge{v, x});
		G[v].push_back(edge{u, x});
		U[i] = u; V[i] = v;
	}
	init(n);
	union_find uf(n);
	for (int u = 0; u < n; u++)
		if (x[u] == 1)
			uf.unite(u, parent[0][u]);
	while (m--) {
		int q; scanf("%d", &q);
		if (q == 1) {
			int a, b; ll y; scanf("%d%d%I64d", &a, &b, &y);
			a--; b--;
			int z = lca(a, b);
			while (y && depth[a] > depth[z])
				if (uf.find(a) == a) {
					y /= x[a];
					a = parent[0][a];
				}
				else a = uf.find(a);
			while (y && depth[b] > depth[z])
				if (uf.find(b) == b) {
					y /= x[b];
					b = parent[0][b];
				}
				else b = uf.find(b);
			printf("%I64d\n", y);
		}
		if (q == 2) {
			int p; ll c; scanf("%d%I64d", &p, &c);
			p--;
			int u = U[p], v = V[p];
			if (depth[u] < depth[v]) swap(u, v);
			x[u] = c;
			if (x[u] == 1) uf.unite(u, parent[0][u]);
		}
	}
}