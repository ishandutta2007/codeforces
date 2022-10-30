#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
int n, m, w;
vector < int > g[maxN];

int a[maxN], b[maxN];

bool used[maxN];

void dfs(int v, vector < int > &c) {
	used[v] = true;
	c.push_back(v);
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], c);
		}
	}
}

long long d[maxN][maxN];

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &w);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector < vector < int > > c;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			vector < int > cur;
			dfs(i, cur);
			c.push_back(cur);
		}
	}

	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			d[i][j] = -1;
		}
	}

	d[0][0] = 0;

	for (int i = 0; i < c.size(); ++i) {
		sort(c[i].begin(), c[i].end());
		int tw = 0, tp = 0;
		for (int j = 0; j < c[i].size(); ++j) {
			tw += a[c[i][j]];
			tp += b[c[i][j]];
		}

		for (int j = 0; j <= w; ++j) {
			if (d[i][j] == -1) {
				continue;
			}

			d[i + 1][j] = max(d[i + 1][j], d[i][j]);
			if (j + tw <= w) {
				d[i + 1][j + tw] = max(d[i + 1][j + tw], d[i][j] + tp);
			}
			for (int k = 0; k < c[i].size(); ++k) {
				if (j + a[c[i][k]] <= w) {
					d[i + 1][j + a[c[i][k]]] = max(d[i + 1][j + a[c[i][k]]], d[i][j] + b[c[i][k]]);
				}
			}
		}
	}

	long long res = 0;
	for (int i = 0; i <= w; ++i) {
		res = max(res, d[c.size()][i]);
	}

	cout << res << endl;



	return 0;
}