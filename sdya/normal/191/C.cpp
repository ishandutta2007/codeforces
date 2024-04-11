#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;
const int maxN = 110000;

void add(long long &x, long long delta) {
	if (delta != 0) {
		x = (x + delta) % P;
	}
}

struct CleverSegmentsTree {
	long long *t;
	long long *add;
	int length;

	CleverSegmentsTree(int n) {
		length = n;
		t = new long long [4 * n];
		add = new long long [4 * n];
		for (int i = 0; i < 4 * n; ++i) {
			t[i] = 0;
			add[i] = 0;
		}
	}

	void update(int i, int l, int r, int cl, int cr, long long delta) {
		if (l == cl && r == cr) {
			t[i] += (long long)(r - l + 1) * delta;
			add[i] += delta;
			return ;
		}
		if (cl > (l + r) / 2) {
			update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, delta);
		} else if (cr <= (l + r) / 2) {
			update(2 * i, l, (l + r) / 2, cl, cr, delta);
		} else {
			update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, delta);
			update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, delta);
		}

		long long added = (long long)(r - l + 1) * add[i];
		t[i] = t[2 * i] + t[2 * i + 1] + added;
	}

	long long get(int i, int l, int r, int k) {
		if (l == r) {
			return t[i];
		}

		if (k > (l + r) / 2) {
			return get(2 * i + 1, (l + r) / 2 + 1, r, k) + add[i];
		} else {
			return get(2 * i, l, (l + r) / 2, k) + add[i];
		}
	}
};

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
		dfs(0, 0);
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

struct HeavyLightDecomposition {
	vector < vector < int > > g, id;
	vector < int > s, d, p;
	vector < bool > used;
	vector < vector < int > > paths;
	vector < CleverSegmentsTree > t;
	vector < pair < int, int > > pos;
	map < pair < int, int >, long long > M;

	HeavyLightDecomposition(int n) {
		g.clear();
		g.resize(n);
		id.resize(n);
		s.resize(n);
		d.assign(n, 0);
		p.assign(n, -1);
		pos.resize(n);
		used.assign(n, false);
	}

	void dfs(int v, int depth = 0) {
		s[v] = 1;
		d[v] = depth;
		used[v] = true;
		for (int i = 0; i < g[v].size(); ++i) {
			if (!used[g[v][i]]) {
				p[g[v][i]] = v;
				dfs(g[v][i], depth + 1);
				s[v] += s[g[v][i]];
			}
		}
	}

	void addEdge(int u, int v, int index) {
		g[u].push_back(v);
		id[u].push_back(index);
		g[v].push_back(u);
		id[v].push_back(index);
	}

	void init() {
		dfs(0);
		for (int i = 0; i < g.size(); ++i) {
			bool hasHeavy = false;
			for (int j = 0; j < g[i].size(); ++j) {
				if (d[g[i][j]] == d[i] + 1) {
					if (2 * s[g[i][j]] >= s[i]) {
						hasHeavy = true;
					}
				}
			}
			if (hasHeavy) {
				continue;
			}
			vector < int > path;
			int v = i;
			while (true) {
				pos[v] = make_pair(paths.size(), path.size());
				path.push_back(v);
				int u = p[v];
				if (u < 0) {
					break;
				}
				if (2 * s[v] < s[u]) {
					break;
				}
				v = u;
			}
			paths.push_back(path);
			CleverSegmentsTree CST(path.size());
			t.emplace_back(CST);
		}
	}
	
	void update(int u, int v) {
		if (u == v) {
			return ;
		}
		if (pos[u].first == pos[v].first) {
			int l = min(pos[u].second, pos[v].second);
			int r = max(pos[u].second, pos[v].second);
			t[pos[u].first].update(1, 0, t[pos[u].first].length - 1, l, r - 1, 1);
			return ;
		}
		if (d[u] > d[v]) {
			int w = paths[pos[u].first].back();
			update(u, w);
			update(p[w], v);
			++M[make_pair(w, p[w])];
		} else {
			int w = paths[pos[v].first].back();
			update(v, w);
			update(p[w], u);
			++M[make_pair(w, p[w])];
		}
	}

	long long get(int u, int v) {
		if (pos[u].first != pos[v].first) {
			return M[make_pair(u, v)] + M[make_pair(v, u)];
		}
		int l = min(pos[u].second, pos[v].second);
		return t[pos[u].first].get(1, 0, t[pos[u].first].length - 1, l);
	}
};

int n, r;
vector < int > g[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	LCAFinder L(n);
	HeavyLightDecomposition H(n);
	vector < pair < int, int > > edges;
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		L.addEdge(u, v);
		H.addEdge(u, v, i);
		edges.push_back(make_pair(u, v));
	}
	H.init();

	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		int w = L.lca(u, v);
		H.update(u, w);
		H.update(v, w);
	}

	for (int i = 0; i < edges.size(); ++i) {
		int u = edges[i].first;
		int v = edges[i].second;
		printf("%I64d ", H.get(u, v));
	}
	printf("\n");

	return 0;
}