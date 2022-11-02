#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
int n, m;
vector < int > g[maxN];
int c[maxN][maxN];
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

	scanf("%d%d", &n, &m);
	int total = 0;
	for (int i = 1; i <= n; ++i) {
		int t;
		scanf("%d", &t);
		for (int j = 1; j <= t; ++j) {
			int w;
			scanf("%d", &w);
			c[i][w] = true;
		}
		total += t;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= m; ++k) {
				if (c[i][k] && c[j][k]) {
					g[i].push_back(j);
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			++cnt;
			dfs(i);
		}
	}

	int res = cnt - 1;
	if (total == 0) {
		res = cnt;
	}

	printf("%d\n", res);

	return 0;
}