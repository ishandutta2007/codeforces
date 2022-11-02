#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const int maxD = 18;

vector < int > p[maxD][maxN];
vector < int > v[maxN];
int n, m, q;
vector < int > g[maxN];
int par[maxD][maxN];

int tin[maxN], tout[maxN], t = 0;

void dfs(int v, int parent = -1) {
	tin[v] = t++;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			par[0][g[v][i]] = v;
			dfs(g[v][i], v);
		}
	}
	tout[v] = t++;
}

vector < int > mergeArrays(const vector < int > &a, const vector < int > &b) {
	int x = 0, y = 0;
	vector < int > res;
	while (x < a.size() && y < b.size() && res.size() < 10) {
		if (a[x] < b[y]) {
			res.push_back(a[x++]);
		} else {
			res.push_back(b[y++]);
		}
	}
	while (res.size() < 10 && x < a.size()) {
		res.push_back(a[x++]);
	}
	while (res.size() < 10 && y < b.size()) {
		res.push_back(b[y++]);
	}
	return res;
}

void precalc() {
	for (int i = 1; i <= n; ++i) {
		p[0][i] = v[i];
	}

	for (int i = 1; i < maxD; ++i) {
		for (int j = 1; j <= n; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
			if (par[i][j] > 0) {
				p[i][j] = mergeArrays(p[i - 1][j], p[i - 1][par[i - 1][j]]);
			}
		}
	}
}

int is_parent(int a, int b) {
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

vector < int >  lca(int a, int b) {
	if (a == b) {
		return v[a];
	}
	if (is_parent(a, b)) {
		vector < int > res;
		for (int i = 16; i >= 0; --i) {
			if (par[i][b] > 0 && is_parent(a, par[i][b])) {
				res = mergeArrays(res, p[i][b]);
				b = par[i][b];
			}
		}
		return mergeArrays(res, lca(a, b));
	}
	if (is_parent(b, a)) {
		vector < int > res;
		for (int i = 16; i >= 0; --i) {
			if (par[i][a] > 0 && is_parent(b, par[i][a])) {
				res = mergeArrays(res, p[i][a]);
				a = par[i][a];
			}
		}
		return mergeArrays(res, lca(a, b));
	}

	vector < int > res;
	for (int i = 16; i >= 0; --i) {
		if (par[i][a] > 0 && !is_parent(par[i][a], b)) {
			res = mergeArrays(res, p[i][a]);
			a = par[i][a];
		}
	}
	res = mergeArrays(res, p[0][a]);
	return mergeArrays(res, lca(par[0][a], b));
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);
	for (int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		if (v[x].size() == 10) {
			continue;
		}
		v[x].push_back(i);
	}
	precalc();

	for (int i = 1; i <= q; ++i) {
		int u, v, a;
		scanf("%d%d%d", &u, &v, &a);
		vector < int > res = lca(u, v);
		while (res.size() > a) {
			res.pop_back();
		}
		printf("%d", res.size());
		for (int j = 0; j < res.size(); ++j) {
			printf(" %d", res[j]);
		}
		printf("\n");
	}

	return 0;
}