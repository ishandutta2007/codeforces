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
#include <complex>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;

int p[maxN];
int n, m;
vector < pair < int, int > > a, b;

int findSet(int v) {
	if (v == p[v]) {
		return v;
	}
	return p[v] = findSet(p[v]);
}

void merge(int u, int v) {
	u = findSet(u);
	v = findSet(v);
	if (rand() % 2) {
		p[u] = v;
	} else {
		p[v] = u;
	}
}

vector < int > g[maxN];

int color[maxN];

void dfs(int v, int &p, int c = 1) {
	color[v] = c;
	++p;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (color[u] != 0 && color[u] + color[v] != 3) {
			printf("0\n");
			exit(0);
		}
		if (color[u] == 0) {
			dfs(u, p, 3 - c);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		p[i] = i;
	}

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u;
		--v;
		if (w == 1) {
			merge(u, v);
		} else {
			a.push_back(make_pair(u, v));
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		if (findSet(a[i].first) == findSet(a[i].second)) {
			printf("0\n");
			return 0;
		}
	}

	vector < int > v;
	for (int i = 0; i < n; ++i) {
		if (findSet(i) == i) {
			v.push_back(i);
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		int x = findSet(a[i].first);
		int y = findSet(a[i].second);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int x = 0, y = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (color[v[i]] == 0) {
			int cnt = 0;
			dfs(v[i], cnt);
			if (cnt > 1) {
				++x;
			} else {
				++y;
			}
		}
	}

	long long res = 1;
	for (int i = 1; i < x + y; ++i) {
		res = (res + res) % 1000000007LL;
	}
	cout << res << endl;

	return 0;
}