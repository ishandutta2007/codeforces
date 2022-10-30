#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;

struct LCAFinder {
	vector < vector < int > > g;
	vector < pair < int, int > > order;
	vector < int > pos;
	vector < bool > used;
	bool initialized;
	LCAFinder(int n) {
		g.clear();
		order.clear();
		pos.clear();
		g.resize(n);
		pos.resize(n);
		used.assign(n, false);
		initialized = false;
	}

	void addEdge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}

	void dfs(int v, int height) {
		pos[v] = order.size();
		order.push_back(make_pair(height, v));
		used[v] = true;
		for (int i = 0; i < g[v].size(); ++i) {
			if (!used[g[v][i]]) {
				dfs(g[v][i], height + 1);
				order.push_back(make_pair(height, v));
			}
		}
	}

	vector < pair < int, int > > t;
	void build(int i, int l, int r) {
		if (l == r) {
			t[i] = order[l];
			return;
		}
		build(2 * i, l, (l + r) / 2);
		build(2 * i + 1, (l + r) / 2 + 1, r);
		t[i] = min(t[2 * i], t[2 * i + 1]);
	}
	pair < int, int > get(int i, int l, int r, int cl, int cr) {
		if (l == cl && r == cr) {
			return t[i];
		}
		if (cl > (l + r) / 2) {
			return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
		}
		if (cr <= (l + r) / 2) {
			return get(2 * i, l, (l + r) / 2, cl, cr);
		}
		pair < int, int > A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
		pair < int, int > B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
		return min(A, B);
	}

	void init() {
		initialized = true;
		for (int i = 0; i < used.size(); ++i) {
			if (!used[i]) {
				dfs(i, 0);
			}
		}
		t.clear();
		t.resize(4 * order.size());
		build(1, 0, order.size() - 1);
	}

	int lca(int u, int v) {
		if (!initialized) {
			init();
		}
		int x = pos[u];
		int y = pos[v];
		if (x > y) {
			swap(x, y);
		}
		return get(1, 0, order.size() - 1, x, y).second;
	}
};

int n, m, q;
vector < pair < int, int > > g[maxN];

bool used[maxN];
int timerc, tin[maxN], fup[maxN];
int initialComp[maxN], initialCompCount;

set < pair < int, int > > bridges;

void dfs (int v, int c, int p = -1) {
	used[v] = true;
	initialComp[v] = c;
	tin[v] = fup[v] = timerc++;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i].first;
		if (g[v][i].second == p) {
			continue;
		}
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, c, g[v][i].second);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				bridges.insert(make_pair(to, v));
				bridges.insert(make_pair(v, to));
			}
		}
	}
}

void find_bridges() {
	timerc = 0;
	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}
	initialCompCount = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			++initialCompCount;
			dfs(i, initialCompCount - 1);
		}
	}
}

int comp[maxN], compCount;
vector < int > h[maxN];
int a[maxN], b[maxN], c[maxN];

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < h[v].size(); ++i) {
		if (used[h[v][i]]) {
			continue;
		}

		dfs(h[v][i]);
		a[v] += a[h[v][i]];
		b[v] += b[h[v][i]];
		c[v] += c[h[v][i]];
	}

	if (a[v] > c[v] && b[v] > c[v]) {
		printf("No\n");
		exit(0);
	}
}

void markComponents(int v, int currentComp) {
	used[v] = true;
	comp[v] = currentComp;
	for (int i = 0; i < g[v].size(); ++i) {
		if (used[g[v][i].first]) {
			continue;
		}

		if (bridges.count(make_pair(v, g[v][i].first))) {
			++compCount;
			markComponents(g[v][i].first, compCount - 1);
		} else {
			markComponents(g[v][i].first, currentComp);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(make_pair(v, i));
		g[v].push_back(make_pair(u, i));
	}

	find_bridges();
	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			++compCount;
			markComponents(i, compCount - 1);
		}
	}

	LCAFinder L(compCount);

	int edgesCount = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			int k = g[i][j].first;

			if (comp[i] != comp[k]) {
				h[comp[i]].push_back(comp[k]);
				if (comp[i] < comp[k]) {
					L.addEdge(comp[i], comp[k]);
				}
			}
		}
	}

	vector < pair < int, int > > queries;
	for (int i = 0; i < q; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		if (initialComp[u] != initialComp[v]) {
			printf("No\n");
			return 0;
		}

		if (comp[u] == comp[v]) {
			continue;
		}

		queries.push_back(make_pair(comp[u], comp[v]));
	}

	for (int i = 0; i < queries.size(); ++i) {
		int u = queries[i].first;
		int v = queries[i].second;
		int w = L.lca(u, v);
		++a[u];
		++b[v];
		++c[w];
	}

	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}
	for (int i = 0; i < compCount; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	printf("Yes\n");

	return 0;
}