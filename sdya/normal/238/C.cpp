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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 3100;
vector < pair < int, int > > g[maxN];
int n;

int d[maxN][maxN];
int p[maxN][maxN];
int t[maxN];
int q[maxN];

void dfs(int v, int parent) {
	t[v] = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i].first == parent) {
			continue;
		}
		if (g[v][i].second != 1) {
			++t[v];
		}
		dfs(g[v][i].first, v);
		t[v] += t[g[v][i].first];
	}
}

void dfs(int v, int parent, int current, int &score) {
	score = min(score, current);
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i].first == parent) {
			continue;
		}

		int buffer = current;
		if (g[v][i].second != 1) {
			--buffer;
		}
		if (g[v][i].second == 1) {
			++buffer;
		}
		dfs(g[v][i].first, v, buffer, score);
	}
}

void calculate(int v, int parent) {
	memset(t, 0, sizeof(t));
	dfs(v, parent);
	memset(q, 0, sizeof(q));
	int score = t[v];
	dfs(v, parent, t[v], score);
	d[v][parent] = t[v];
	p[v][parent] = score;
}

bool used[maxN];

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i].first] && g[v][i].second == 1) {
			dfs(g[v][i].first);
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
		g[u].push_back(make_pair(v, 1));
		g[v].push_back(make_pair(u, -1));
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			calculate(i, g[i][j].first);
		}
	}

	int res = n - 1;
	for (int i = 1; i <= n; ++i) {
		memset(used, 0, sizeof(used));
		dfs(i);

		vector < pair < int, int > > rem;
		for (int j = 1; j <= n; ++j) {
			if (!used[j]) {
				continue;
			}
			for (int k = 0; k < g[j].size(); ++k) {
				if (!used[g[j][k].first] && g[j][k].second == -1) {
					rem.push_back(make_pair(g[j][k].first, j));
				}
			}
		}

		int added = 0;
		for (int j = 0; j < rem.size(); ++j) {
			added += d[rem[j].first][rem[j].second] + 1;
		}

		res = min(res, added);
		for (int j = 0; j < rem.size(); ++j) {
			int score = added;
			score -= d[rem[j].first][rem[j].second] + 1;
			score += p[rem[j].first][rem[j].second];
			res = min(res, score);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			res = min(res, p[i][g[i][j].first] + p[g[i][j].first][i]);
		}
	}
	printf("%d\n", res);

	return 0;
}