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

const int maxN = 1100;
vector < int > g[maxN];
int n, m;

int color[maxN];
int compId[maxN], cnt;
int d[maxN][maxN];

int res[maxN];

void dfs(int v, int current, int id) {
	color[v] = current;
	compId[v] = id;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (color[u] != 0 && color[u] + color[v] != 3) {
			printf("-1\n");
			exit(0);
		}
		if (color[u] == 0) {
			dfs(u, 3 - current, id);
		}
	}
}

void bfs(int v) {
	queue < int > q;
	for (int i = 1; i <= n; ++i) {
		d[v][i] = -1;
	}
	d[v][v] = 0;
	q.push(v);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < g[u].size(); ++i) {
			if (d[v][g[u][i]] == -1) {
				d[v][g[u][i]] = d[v][u] + 1;
				q.push(g[u][i]);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0) {
			++cnt;
			dfs(i, 1, cnt);
		}
	}

	for (int i = 1; i <= n; ++i) {
		bfs(i);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (compId[i] == compId[j]) {
				res[compId[i]] = max(res[compId[i]], d[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= cnt; ++i) {
		ans += res[i];
	}
	printf("%d\n", ans);

	return 0;
}