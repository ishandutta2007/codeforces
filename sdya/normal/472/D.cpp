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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;
int d[maxN][maxN];
vector < pair < int, int > > g[maxN];
int p[maxN];
int n;

int findSet(int v) {
	if (p[v] == v) {
		return v;
	}
	return p[v] = findSet(p[v]);
}

void mergeSets(int u, int v) {
	if (rand() % 2 == 0) {
		p[u] = v;
	} else {
		p[v] = u;
	}
}

pair < int, pair < int, int > > a[maxN * maxN];
int m;

bool used[maxN];
int c[maxN];

void dfs(int v, int d[]) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (used[g[v][i].first]) {
			continue;
		}
		d[g[v][i].first] = d[v] + g[v][i].second;
		dfs(g[v][i].first, d);
	}
}

bool check() {
	for (int i = 0; i < n; ++i) {
		memset(used, false, sizeof(used));
		for (int j = 0; j < n; ++j) {
			c[j] = 1000000001;
		}
		c[i] = 0;
		dfs(i, c);	
		for (int j = 0; j < n; ++j) {
			if (c[j] != d[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &d[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		p[i] = i;
	}

	m = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (d[i][j] > 0) {
				a[m++] = make_pair(d[i][j], make_pair(i, j));
			}
		}
	}

	sort(a, a + m);
	for (int i = 0; i < m; ++i) {
		int x = a[i].second.first;
		int y = a[i].second.second;
		if (findSet(x) != findSet(y)) {
			g[x].push_back(make_pair(y, a[i].first));
			g[y].push_back(make_pair(x, a[i].first));
			mergeSets(findSet(x), findSet(y));
		}
	}

	if (check()) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}


	return 0;
}