#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, m;
vector < pair < int, int > > g[maxN];
int k;
bool portals[maxN];

long long d[maxN];
int p[maxN];

int parent[maxN];

int find_set(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

void merge(int x, int y) {
	int u = find_set(x), v = find_set(y);
	if (u != v) {
		parent[u] = v;
	}
}

struct Edge {
	int u, v;
	long long w;
	Edge() {
	}
	Edge(int u, int v, long long w) : u(u), v(v), w(w) {
	}
	bool operator < (const Edge &other) const {
		return w < other.w;
	}
};

set < pair < long long, int > > S;
vector < Edge > edges;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int v;
		scanf("%d", &v);
		portals[v] = true;
	}

	for (int i = 1; i <= n; ++i) {
		d[i] = 1000000000000000000LL;
		p[i] = -1;
		if (portals[i]) {
			d[i] = 0;
			p[i] = parent[i] = i;
		}
		S.insert(make_pair(d[i], i));
	}

	while (!S.empty()) {
		int v = S.begin()->second;
		S.erase(S.begin());
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i].first;
			long long len = d[v] + (long long)(g[v][i].second);
			if (d[to] > len) {
				S.erase(make_pair(d[to], to));
				d[to] = len;
				p[to] = p[v];
				S.insert(make_pair(d[to], to));
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			int u = i, v = g[i][j].first;
			long long len = g[i][j].second;
			if (p[u] != p[v]) {
				edges.push_back(Edge(u, v, d[u] + d[v] + len));
			}
		}
	}

	sort(edges.begin(), edges.end());
	long long res = d[1];
	for (int i = 0; i < edges.size(); ++i) {
		int u = edges[i].u, v = edges[i].v;
		long long len = edges[i].w;

		if (find_set(p[u]) != find_set(p[v])) {
			res += len;
			merge(p[u], p[v]);
		}
	}

	cout << res << endl;

	return 0;
}