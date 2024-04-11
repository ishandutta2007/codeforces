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

const int maxM = 1100 * 1100;
const int maxN = 1100;
int n, m, q;
int order[maxM];
int u[maxM], v[maxM], w[maxM];
int p[maxN], s[maxN], color[maxN];
vector < int > g[maxN];

int findSet(int v) {
	if (p[v] == v) {
		return v;
	}
	return p[v] = findSet(p[v]);
}

bool comp(int x, int y) {
	return w[x] > w[y];
}

void invert(int v) {
	color[v] = 3 - color[v];
	for (int i = 0; i < g[v].size(); ++i) {
		invert(g[v][i]);
	}
}

void solve(int l, int r) {
	for (int i = 0; i < n; ++i) {
		g[i].clear();
		p[i] = i;
		color[i] = 1;
		s[i] = 1;
	}

	for (int i = 0; i < m; ++i) {
		if (order[i] < l || order[i] > r) {
			continue;
		}
		int u = ::u[order[i]];
		int v = ::v[order[i]];

		int pu = findSet(u);
		int pv = findSet(v);
		if (pu == pv) {
			if (color[u] == color[v]) {
				printf("%d\n", w[order[i]]);
				return;
			}
			continue;
		}

		if (color[u] == color[v]) {
			if (s[pu] < s[pv]) {
				invert(pu);
			} else {
				invert(pv);
			}
		}

		if (rand() % 2) {
			p[pu] = pv;
			s[pv] += s[pu];
			g[pv].push_back(pu);
		} else {
			p[pv] = pu;
			s[pu] += s[pv];
			g[pu].push_back(pv);
		}
	}

	printf("-1\n");
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		--u[i];
		--v[i];
		order[i] = i;
	}
	sort(order, order + m, comp);

	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		solve(l - 1, r - 1);
	}

	return 0;
}