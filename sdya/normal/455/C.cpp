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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 310000;
int n, m, q;
int parent[maxN], t[maxN];
int used[maxN];
int c[maxN], d[maxN];

vector < int > g[maxN];

int findSet(int v) {
	if (parent[v] == v) {
		return v;
	} else {
		return parent[v] = findSet(parent[v]);
	}
}

void mergeSet(int u, int v) {
	int x = t[u];
	int y = t[v];
	int nlen = ((x + 1) / 2) + ((y + 1) / 2) + 1;
	nlen = max(nlen, x);
	nlen = max(nlen, y);

	if (rand() % 2) {
		parent[v] = u;
		t[u] = nlen;
	} else {
		parent[u] = v;
		t[v] = nlen;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	memset(d, -1, sizeof(d));
	memset(c, -1, sizeof(c));

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (used[i]) {
			continue;
		}
		queue < int > q;
		++cnt;

		d[i] = 0;
		q.push(i);

		int best = 0, v = i;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int j = 0; j < g[u].size(); ++j) {
				if (d[g[u][j]] == -1) {
					d[g[u][j]] = d[u] + 1;
					if (d[g[u][j]] > best) {
						best = d[g[u][j]];
						v = g[u][j];
					}
					q.push(g[u][j]);
				}
			}
		}

		vector < int > buf;
		c[v] = 0;
		q.push(v);

		int diam = 0;
		while (!q.empty()) {
			int u = q.front();
			buf.push_back(u);
			q.pop();

			for (int j = 0; j < g[u].size(); ++j) {
				if (c[g[u][j]] == -1) {
					c[g[u][j]] = c[u] + 1;
					if (c[g[u][j]] > diam) {
						diam = c[g[u][j]];
					}
					q.push(g[u][j]);
				}
			}
		}

		for (int j = 0; j < buf.size(); ++j) {
			parent[buf[j]] = buf[0];
			used[buf[j]] = true;
		}
		t[buf[0]] = diam;
	}

	for (int i = 0; i < q; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1) {
			int v;
			scanf("%d", &v);
			printf("%d\n", t[findSet(v)]);
		} else {
			int u, v;
			scanf("%d%d", &u, &v);
			int x = findSet(u);
			int y = findSet(v);
			if (x != y) {
				mergeSet(x, y);
			}
		}
	}

	return 0;
}