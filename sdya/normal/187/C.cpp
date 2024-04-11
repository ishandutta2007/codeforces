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

const int maxN = 110000;
vector < int > g[maxN];
int n, m, k;
int p[maxN];
int s, t;

int f[maxN];
int visited[maxN];

set < int > r[maxN];

int findSet(int v) {
	if (f[v] == v) {
		return v;
	}
	return f[v] = findSet(f[v]);
}

void merge(int x, int y) {
	x = findSet(x);
	y = findSet(y);
	if (x == y) {
		return;
	}
	if (r[x].size() > r[y].size()) {
		for (set < int > ::iterator it = r[y].begin(); it != r[y].end(); ++it) {
			r[x].insert(*it);
		}
		f[y] = x;
	} else {
		for (set < int > ::iterator it = r[x].begin(); it != r[x].end(); ++it) {
			r[y].insert(*it);
		}
		f[x] = y;
	}
	/*if (rand() % 2) {
		f[x] = y;
	} else {
		f[y] = x;
	}*/
}

bool used[maxN];

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; ++i) {
		int t;
		scanf("%d", &t);
		p[t] = 1;
	}

	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	scanf("%d%d", &s, &t);
	if (!p[t]) {
		p[t] = 1;
		++k;
	}

	dfs(s);
	if (!used[t]) {
		printf("-1\n");
		return 0;
	}

	vector < pair < int, int > > q;
	for (int i = 1; i <= n; ++i) {
		if (p[i]) {
			q.push_back(make_pair(i, i));
			r[i].insert(i);
			f[i] = i;
		}
	}

	int length = 0;
	while (findSet(f[s]) != findSet(f[t])) {
		++length;
		vector < pair < int, int > > nq;
		for (int i = 0; i < q.size(); ++i) {
			int v = q[i].first;
			int t = findSet(q[i].second);
			for (int j = 0; j < g[v].size(); ++j) {
				if (p[g[v][j]]) {
					merge(t, g[v][j]);
				} else {
					if (r[t].count(g[v][j]) == 0) {
						nq.push_back(make_pair(g[v][j], t));
						r[t].insert(g[v][j]);
					}
				}
			}
		}
		q = nq;
	}

	printf("%d\n", length);

	return 0;
}