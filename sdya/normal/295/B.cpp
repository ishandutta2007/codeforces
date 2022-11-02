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

const int maxN = 600;
const int inf = 1000000000;
int a[maxN][maxN];
int n, order[maxN];

bool used[maxN];
long long res[maxN];

int d[maxN][maxN];
int g[maxN], h[maxN], visited[maxN];

void solve(int v, int g[], bool rev = false) {
	for (int i = 0; i < n; ++i) {
		g[i] = inf;
		visited[i] = used[i];
	}

	g[v] = 0;
	while (true) {
		int u = -1, best = inf;
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && g[i] < best) {
				best = g[i];
				u = i;
			}
		}
		if (u == -1) {
			break;
		}
		visited[u] = true;
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && g[i] > g[u] + (rev ? a[i][u] : a[u][i])) {
				g[i] = g[u] + (rev ? a[i][u] : a[u][i]);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
			d[i][j] = inf;
		}
		d[i][i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &order[i]);
		--order[i];
		used[order[i]] = true;
	}

	for (int i = n - 1; i >= 0; --i) {
		used[order[i]] = false;
		solve(order[i], g, false);
		solve(order[i], h, true);
		for (int j = 0; j < n; ++j) {
			if (!used[j]) {
				d[order[i]][j] = g[j];
				d[j][order[i]] = h[j];
			}
		}
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (j == order[i] || k == order[i] || used[j] || used[k]) {
					continue;
				}
				d[j][k] = min(d[j][k], d[j][order[i]] + d[order[i]][k]);
			}
		}

		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (!used[j] && !used[k]) {
					res[i] += d[j][k];
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%I64d ", res[i]);
	}
	printf("\n");


	return 0;
}