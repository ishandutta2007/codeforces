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

const int maxN = 5100;
int n, m, cnt[maxN];
bool used[maxN];
vector < int > g[maxN], gr[maxN];
int r[maxN][maxN], len[maxN], olen[maxN], c[maxN];
int d[maxN][maxN];
int q[maxN], lq, rq;

void build(int v) {
	for (int i = 0; i < n; ++i) {
		d[v][i] = -1;
	}
	lq = 0, rq = 0;
	d[v][v] = 0;
	q[rq++] = v;
	while (lq < rq) {
		int u = q[lq++];

		for (int i = 0; i < g[u].size(); ++i) {
			if (d[v][g[u][i]] == -1) {
				d[v][g[u][i]] = d[v][u] + 1;
				q[rq++] = g[u][i];
			}
		}
	}
}

void gen() {
	int n = 5000, m = 5000;
	printf("%d %d\n", n, m);
	for (int i = 0; i < m / 2; ++i) {
		printf("%d %d\n", i + 1, (i + 1) % (m / 2) + 1);
		printf("%d %d\n", n / 2 + i + 1, n / 2 + (i + 1) % (m / 2) + 1);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	//return 0;


	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u - 1].push_back(v - 1);
		gr[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < n; ++i) {
		build(i);
	}
	//cerr << clock() << endl;
	for (int i = 0; i < n; ++i) {
		c[i] = n + 1;
		for (int j = 0; j < n; ++j) {
			if (i != j && d[i][j] != -1 && d[j][i] != -1) {
				c[i] = min(c[i], d[i][j] + d[j][i]);
			}
		}
		if (c[i] == n + 1) {
			c[i] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (d[i][j] != -1) {
				r[j][len[j]++] = i;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		olen[i] = len[i];
	}

	//cerr << clock() << endl;

	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}

	int ans = 0;
	while (true) {
		int index = -1;
		int best = 0;
		int mincycle = n;
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			}
			if (len[i] > best) {
				best = len[i];
				index = i;
				mincycle = c[i];
			} else if (len[i] == best && c[i] < mincycle) {
				mincycle = c[i];
				index = i;
			}
		}
		if (index == -1) {
			break;
		}

		if (mincycle > 1) {
			ans += 998 * mincycle + 1 + best;
		} else {
			ans += best;
		}

		for (int i = 0; i < olen[index]; ++i) {
			int u = r[index][i];
			if (used[u]) {
				continue;
			}
			used[u] = true;
			for (int j = 0; j < n; ++j) {
				if (d[u][j] != -1) {
					--len[j];
				}
			}
		}
	}

	printf("%d\n", ans);

	cerr << clock() << endl;


	return 0;
}