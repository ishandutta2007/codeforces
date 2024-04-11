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
const int maxM = 210000;
int n, m, q;
pair < int, int > g[maxM];
int l[maxM], r[maxM], s[maxM], t[maxM];
vector < int > p[maxM];

int res[maxM];
int d[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &g[i].first, &g[i].second);
	}
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d%d", &l[i], &r[i], &s[i], &t[i]);
		p[l[i]].push_back(i);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[i][j] = m + 1;
		}
		d[i][i] = 0;
	}

	for (int i = q; i >= 1; --i) {
		int u = g[i].first;
		int v = g[i].second;
		for (int j = 1; j <= n; ++j) {
			d[u][j] = min(d[u][j], d[v][j]);
			d[v][j] = min(d[v][j], d[u][j]);
		}
		d[u][v] = d[v][u] = i;

		for (int j = 0; j < p[i].size(); ++j) {
			res[p[i][j]] = d[s[p[i][j]]][t[p[i][j]]];
		}
	}

	for (int i = 1; i <= q; ++i) {
		if (res[i] <= r[i]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}