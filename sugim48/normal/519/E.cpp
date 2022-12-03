#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <list>
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
struct edge { ll B, T, F, P; };

unsigned MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int UNKO = INT_MAX;

vector<int> G[100000];
int parent[20][100000];
int depth[100000];
int size[100000];

void dfs(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p) dfs(G[v][i], v, d + 1);
}

void init(int V) {
	dfs(0, -1, 0);
	for (int k = 0; k + 1 < 20; k++)
		for (int v = 0; v < V; v++)
			if (parent[k][v] < 0) parent[k + 1][v] = -1;
			else parent[k + 1][v] = parent[k][parent[k][v]];
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	for (int k = 0; k < 20; k++)
		if ((depth[v] - depth[u]) >> k & 1)
			v = parent[k][v];
	if (u == v) return u;
	for (int k = 20 - 1; k >= 0; k--)
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	return parent[0][u];
}

void mydfs(int v, int p) {
	size[v] = 1;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p) {
			mydfs(G[v][i], v);
			size[v] += size[G[v][i]];
		}
}

int f(int u, int x) {
	for (int k = 0; k < 20; k++) {
		if (x & 1) u = parent[k][u];
		x >>= 1;
	}
	return u;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	init(n);
	mydfs(0, -1);
	int m; cin >> m;
	while (m--) {
		int x, y; scanf("%d%d", &x, &y);
		x--; y--;
		if (x == y) {
			printf("%d\n", n);
			continue;
		}
		int z = lca(x, y);
		int d = depth[x] + depth[y] - depth[z] * 2;
		if (d % 2 == 1) {
			printf("0\n");
			continue;
		}
		int ans;
		if (depth[x] == depth[y]) {
			int a = f(x, d / 2 - 1), b = f(y, d / 2 - 1);
			ans = n - size[a] - size[b];
		}
		else {
			if (depth[x] < depth[y]) swap(x, y);
			int a = f(x, d / 2), b = f(x, d / 2 - 1);
			ans = size[a] - size[b];
		}
		printf("%d\n", ans);
	}
}