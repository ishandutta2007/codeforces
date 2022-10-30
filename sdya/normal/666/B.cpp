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

const int maxN = 3100;
vector < int > g[maxN];
int d[maxN][maxN];
pair < int, int > c[maxN][maxN], rc[maxN][maxN];
int n, m;

void bfs(int v, int d[], pair < int, int > c[]) {
	for (int i = 0; i < n; ++i) {
		d[i] = -1;
	}
	d[v] = 0;
	queue < int > q;
	q.push(v);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < g[v].size(); ++i) {
			if (d[g[v][i]] == -1) {
				d[g[v][i]] = d[v] + 1;
				q.push(g[v][i]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		c[i] = make_pair(d[i], i);
		rc[i][v] = make_pair(d[i], v);
	}
	sort(c, c + n);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
	}

	for (int i = 0; i < n; ++i) {
		bfs(i, d[i], c[i]);
	}
	for (int i = 0; i < n; ++i) {
		sort(rc[i], rc[i] + n);
	}

	int res = -1;
	int ans[4];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			if (d[i][j] == -1) {
				continue;
			}

			for (int u = 0; u < 4; ++u) {
				int l = rc[i][n - 1 - u].second;
				if (rc[i][n - 1 - u].first == -1 || l == j || l == i) {
					continue;
				}
				for (int v = 0; v < 4; ++v) {
					int r = c[j][n - 1 - v].second;
					if (c[j][n - 1 - v].first == -1 || l == r || r == i || r == j) {
						continue;
					}
					int len = d[i][j] + rc[i][n - 1 - u].first + c[j][n - 1 - v].first;
					if (len > res) {
						res = len;
						ans[0] = l;
						ans[1] = i;
						ans[2] = j;
						ans[3] = r;
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; ++i) {
		printf("%d ", ans[i] + 1);
	}
	printf("\n");


	return 0;
}