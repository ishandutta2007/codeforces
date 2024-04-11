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

const int maxN = 3100;
const int inf = 1000000000;
vector < int > g[maxN];
int d[maxN][maxN];
int n, m;

int s[2][2], l[2];

void calculate(int v, int d[]) {
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
	}
	d[v] = 0;
	queue < int > q;
	q.push(v);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			if (d[v] == inf) {
				d[v] = d[u] + 1;
				q.push(v);
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
	scanf("%d%d%d", &s[0][0], &s[0][1], &l[0]);
	scanf("%d%d%d", &s[1][0], &s[1][1], &l[1]);
	for (int i = 1; i <= n; ++i) {
		calculate(i, d[i]);
	}

	int res = inf;
	if (d[s[0][0]][s[0][1]] <= l[0] && d[s[1][0]][s[1][1]] <= l[1]) {
		res = min(res, d[s[0][0]][s[0][1]] + d[s[1][0]][s[1][1]]);
	}
	if (res == inf) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (d[i][j] == inf) {
				continue;
			}
			int len = d[i][j];
			if (len >= res) {
				continue;
			}

			for (int x = 0; x < 2; ++x) {
				for (int y = 0; y < 2; ++y) {
					int A = d[i][s[0][x]] + d[i][s[1][y]];
					int B = d[j][s[0][1 - x]] + d[j][s[1][1 - y]];
					if (A >= inf || B >= inf || A >= res || B >= res) {
						continue;
					}
					if (d[i][s[0][x]] + d[j][s[0][1 - x]] + len > l[0]) {
						continue;
					}
					if (d[i][s[1][y]] + d[j][s[1][1 - y]] + len > l[1]) {
						continue;
					}
					res = min(res, len + A + B);
				}
			}
		}
	}

	

	if (res == inf) {
		printf("-1\n");
	} else {
		printf("%d\n", m - res);
	}

	return 0;
}