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

const int maxN = 210000;
vector < int > g[maxN];
int n;

int d[maxN][2];
int s[maxN];
int dp[maxN];

void dfs(int v) {
	if (g[v].size() == 0) {
		s[v] = 1;
	}
	for (int i = 0; i < g[v].size(); ++i) {
		dp[g[v][i]] = dp[v] + 1;
		dfs(g[v][i]);
		s[v] += s[g[v][i]];
	}
}

void dfs2(int v) {
	d[v][0] = n;
	d[v][1] = 0;
	if (g[v].size() == 0) {
		d[v][0] = d[v][1] = 1;
		return ;
	}
	for (int i = 0; i < g[v].size(); ++i) {
		dfs2(g[v][i]);
	}

	if (dp[v] % 2 == 0) {
		d[v][0] = 0;
		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];

			int minV = d[u][0], maxV = d[u][1];
			d[v][1] = max(d[v][1], s[v] - s[u] + maxV);
			d[v][0] += minV;
		}
	} else {
		d[v][1] = s[v] - g[v].size() + 1;
		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];

			int minV = d[u][0], maxV = d[u][1];
			d[v][0] = min(d[v][0], minV);
			d[v][1] -= s[u] - maxV;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}

	dfs(1);
	dfs2(1);

	printf("%d %d\n", d[1][1], d[1][0]);

	return 0;
}