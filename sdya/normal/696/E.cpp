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

const long long inf = 1000000000000000000LL;
const int maxN = 110000;
int r[maxN];

pair < int, long long > cmin(pair < int, long long > a, pair < int, long long > b) {
	if (a.second < b.second) {
		return a;
	}
	if (b.second < a.second) {
		return b;
	}
	if (a.first == -1) {
		return a;
	}
	return r[a.first] < r[b.first] ? a : b;
}

struct CleverSegmentsTree {
	vector < pair < int, long long > > t;
	vector < vector < pair < int, long long > > > x;
	vector < int > index;
	vector < long long > add;
	int length;

	CleverSegmentsTree(int n) {
		length = n;
		t.assign(4 * n, make_pair(-1, inf));
		x.resize(4 * n);
		index.resize(4 * n);
		add.resize(4 * n);
	}

	void update(int i, int l, int r, int cl, int cr, long long added) {
		if (l == cl && r == cr) {
			add[i] += added;
			t[i].second += added;
			return;
		}

		if (cl > (l + r) / 2) {
			update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, added);
		} else if (cr <= (l + r) / 2) {
			update(2 * i, l, (l + r) / 2, cl, cr, added);
		} else {
			update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, added);
			update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, added);
		}

		t[i] = cmin(t[2 * i], t[2 * i + 1]);
		t[i].second += add[i];
	}

	void update(int l, int r, long long value) {
		update(1, 0, length - 1, l, r, value);
	}

	void addItem(int i, int l, int r, int k, int c, long long v) {
		if (l == r) {
			x[i].push_back(make_pair(v, c));
			t[i] = make_pair(v, c);
			t[i].second += add[i];
			return ;
		}
		if (k > (l + r) / 2) {
			addItem(2 * i + 1, (l + r) / 2 + 1, r, k, c, v);
		} else {
			addItem(2 * i, l, (l + r) / 2, k, c, v);
		}
		t[i] = cmin(t[2 * i], t[2 * i + 1]);
	}

	void addItem(int k, int c, long long v) {
		addItem(1, 0, length - 1, k, c, v);
	}

	void removeItem(int i, int l, int r, int k) {
		if (l == r) {
			x[i].pop_back();
			pair < int, long long > p(-1, inf);
			if (!x[i].empty()) {
				p = x[i].back();
				p.second += add[i];
			}
			t[i] = p;
			return;
		}
		if (k > (l + r) / 2) {
			removeItem(2 * i + 1, (l + r) / 2 + 1, r, k);
		} else {
			removeItem(2 * i, l, (l + r) / 2, k);
		}
		t[i] = cmin(t[2 * i], t[2 * i + 1]);
		t[i].second += add[i];
	}

	void removeItem(int k) {
		removeItem(1, 0, length - 1, k);
	}
	
	pair < int, long long > get(int i, int l, int r, int cl, int cr, long long added = 0) {
		if (l == cl && r == cr) {
			pair < int, long long > res = t[i];
			res.second += added;
			return res;
		}
		if (cl > (l + r) / 2) {
			return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, added + add[i]);
		}
		if (cr <= (l + r) / 2) {
			return get(2 * i, l, (l + r) / 2, cl, cr, added + add[i]);
		}

		pair < int, long long > x = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2, added + add[i]);
		pair < int, long long > y = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, added + add[i]);

		return cmin(x, y);
	}

	pair < int, long long > get(int l, int r) {
		return get(1, 0, length - 1, l, r);
	}
};

struct SegmentsTree {
	vector < long long > t;
	vector < long long > add;
	int length;

	SegmentsTree() {
	}

	void init(int n) {
		length = n;
		t.resize(4 * n);
		add.resize(4 * n);
	}

	SegmentsTree(int n) {
		init(n);
	}

	void update(int i, int l, int r, int cl, int cr, long long added) {
		if (l == cl && r == cr) {
			add[i] += added;
			t[i] += added;
			return;
		}

		if (cl > (l + r) / 2) {
			update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, added);
		} else if (cr <= (l + r) / 2) {
			update(2 * i, l, (l + r) / 2, cl, cr, added);
		} else {
			update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, added);
			update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, added);
		}

		t[i] = max(t[2 * i], t[2 * i + 1]) + add[i];
	}

	void update(int l, int r, long long value) {
		update(1, 0, length - 1, l, r, value);
	}

	long long get(int i, int l, int r, int cl, int cr, long long added = 0) {
		if (l == cl && r == cr) {
			return t[i] + added;
		}
		if (cl > (l + r) / 2) {
			return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, added + add[i]);
		}
		if (cr <= (l + r) / 2) {
			return get(2 * i, l, (l + r) / 2, cl, cr, added + add[i]);
		}

		long long x = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2, added + add[i]);
		long long y = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, added + add[i]);

		return max(x, y);
	}

	long long get(int l, int r) {
		return get(1, 0, length - 1, l, r);
	}
};

struct WeightGetter {
	vector < vector < int > > g;
	vector < int > p;
	vector < int > l, r;
	SegmentsTree T;

	WeightGetter() {}

	WeightGetter(int n) {
		g.clear();
		g.resize(n);
		p.assign(n, -1);

		l.assign(n, -1);
		r.assign(n, -1);
		T.init(n);
	}

	void addEdge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector < int > order;

	void dfs(int v, int parent = -1) {
		p[v] = parent;
		l[v] = order.size();
		order.push_back(v);
		for (int i = 0; i < g[v].size(); ++i) {
			if (g[v][i] != parent) {
				dfs(g[v][i], v);
			}
		}
		r[v] = order.size() - 1;
	}

	void init() {
		order.clear();
		dfs(0);
	}

	void update(int v, long long value) {
		T.update(l[v], r[v], value);
	}

	long long get(int v) {
		if (p[v] < 0) {
			return 0;
		}
		return T.get(l[p[v]], l[p[v]]);
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

WeightGetter W;

struct HeavyLightDecomposition {
	vector < vector < int > > g;
	vector < int > s, d, p;
	vector < bool > used;
	vector < vector < int > > paths;
	vector < CleverSegmentsTree > t;
	vector < pair < int, int > > pos;

	HeavyLightDecomposition(int n) {
		g.clear();
		g.resize(n);
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

	void addEdge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
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

	void addItem(int u, int index, long long value) {
		t[pos[u].first].addItem(pos[u].second, index, value);
	}

	void removeItem(int u) {
		t[pos[u].first].removeItem(pos[u].second);
	}

	pair < int, long long > getE(int u, int v) {
		pair < int, long long > res = t[pos[u].first].get(min(pos[u].second, pos[v].second), max(pos[u].second, pos[v].second));
		res.second += W.get(paths[pos[u].first].back());
		return res;
	}

	pair < int, long long > get(int u, int v) {
		if (pos[u].first == pos[v].first) {
			return getE(u, v);
		}
		if (d[u] > d[v]) {
			int w = paths[pos[u].first].back();
			pair < int, long long > x = getE(u, w);
			pair < int, long long > y = get(p[w], v);
			return cmin(x, y);
		} else {
			int w = paths[pos[v].first].back();
			pair < int, long long > x = getE(v, w);
			pair < int, long long > y = get(p[w], u);
			return cmin(x, y);
		}
	}
};

vector < int > g[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	LCAFinder L(n);
	W = WeightGetter(n);
	HeavyLightDecomposition H(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		L.addEdge(u, v);
		H.addEdge(u, v);
		W.addEdge(u, v);
	}

	for (int i = 0; i < m; ++i) {
		scanf("%d", &r[i]);
		--r[i];
	}

	L.init();
	H.init();
	W.init();

	for (int i = m - 1; i >= 0; --i) {
		H.addItem(r[i], i, i);
	}

	for (int i = 0; i < q; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1) {
			int u, v, k;
			scanf("%d%d%d", &u, &v, &k);
			--u;
			--v;
			int w = L.lca(u, v);

			vector < pair < int, long long > > res;
			for (int j = 0; j < k; ++j) {
				pair < int, long long > a = H.get(u, w);
				pair < int, long long > b = H.get(v, w);
				pair < int, long long > c = cmin(a, b);
				if (c.first == -1) {
					break;
				}
				res.push_back(c);
				H.removeItem(r[c.first]);
			}

			printf("%d", res.size());
			for (int j = 0; j < res.size(); ++j) {
				printf(" %d", res[j].first + 1);
			}
			printf("\n");
		} else {
			int v, k;
			scanf("%d%d", &v, &k);
			--v;
			W.update(v, k);

			H.t[H.pos[v].first].update(0, H.pos[v].second, k);
		}
	}

	return 0;
}