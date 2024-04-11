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

const int maxN = 310000;
int n, m;
vector < int > g[maxN];
int d[maxN], s[maxN];
int p[20][maxN];

bool comp(int u, int v) {
	return s[u] > s[v];
}

void dfs(int v, int depth = 0) {
	d[v] = depth;
	s[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		dfs(g[v][i], depth + 1);
		s[v] += s[g[v][i]];
	}
}

int res[maxN];

inline int getV(int v, int n) {
	for (int i = 0; i < 19; ++i) {
		if (n & (1 << i)) {
			v = p[i][v];
		}
	}
	return v;
}

int calc(int v) {
	if (res[v] != -1) {
		return res[v];
	}
	int l = 0, r = n - d[v];
	int bound = s[v] / 2;
	while (r - l > 1) {
		int m = (l + r) / 2;
		int u = getV(v, m);
		if (s[u] == 1 || s[g[u][0]] <= bound) {
			r = m;
		} else {
			l = m;
		}
	}

	int u = getV(v, l);
	if (s[u] == 1 || s[g[u][0]] <= bound) {
		return res[v] = u + 1;
	}
	return res[v] = p[0][u] + 1;
}

void solve(int v) {
	printf("%d\n", calc(v));
}

void gen() {
	int n = 300000;
	printf("%d %d\n", n, n);
	for (int i = 2; i <= n; ++i) {
		printf("%d\n", i - 1);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", i);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	//return 0;

	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		g[p - 1].push_back(i - 1);
	}

	dfs(0);
	for (int i = 0; i < n; ++i) {
		res[i] = -1;
		sort(g[i].begin(), g[i].end(), comp);
	}

	for (int i = 0; i < n; ++i) {
		if (g[i].size() > 0) {
			p[0][i] = g[i][0];
		} else {
			p[0][i] = i;
		}
	}

	for (int i = 1; i < 19; ++i) {
		for (int j = 0; j < n; ++j) {
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}

	for (int i = 0; i < m; ++i) {
		int v;
		scanf("%d", &v);
		solve(v - 1);
	}

	cerr << clock() << endl;


	return 0;
}