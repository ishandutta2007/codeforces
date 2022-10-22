#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <int> pval;
vector <int> num;

vector <pair <int, int> > edges; 
vector <vector <int>> gr;

struct Query {
	int type;
	int i;
	int ind;
};

vector <int> res;

struct DSU {
	int n;
	vector <int> p, r;
	DSU(int n) : p(n, 0), r(n, 0) {
		iota(all(p), 0);
	}
	int get(int v) {
		return (p[v] == v ? p[v] : get(p[v]));
	}
	bool uni(int v, int u) {
		v = get(v), u = get(u);
		if (v == u) return false;
		if (r[v] == r[u]) ++r[u];
		if (r[v] > r[u]) swap(v, u);
		p[v] = u;
		return true;
	}
};

vector <int> order;
vector <int> values;
vector <int> lt, rt;
vector <int> pos;

void dfs(int v, int p = -1) {
	order.pb(v);
	values.pb(pval[v]);
	lt[v] = order.size() - 1;
	rt[v] = order.size() - 1;
	pos[v] = order.size() - 1;
	for (int u : gr[v]) {
		if (u == p) continue;
		dfs(u, v);
		rt[v] = max(rt[v], rt[u]);
	}
}

struct Tree {

	int n;
	vector <int> t, val;

	Tree() = default;
	
	void relax(int v) {
		t[v] = max(t[2 * v], t[2 * v + 1]);
	}
	void add_val(int v, int x) {
		if (x) {
			t[v] = 0;
		}
		val[v] = max(val[v], x);
	}
	void push(int v) {
		add_val(2 * v, val[v]);
		add_val(2 * v + 1, val[v]);
	}
	void build(int v, int l, int r, vector <int> &a) {
		if (r - l == 1) {
			t[v] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(2 * v, l, m, a);
		build(2 * v + 1, m, r, a);
		relax(v);
	}
	Tree(vector <int> a) : val(4 * a.size(), 0), t(4 * a.size(), 0) {
		n = a.size();
		build(1, 0, n, a);
	}
	void add_seg(int l, int r, int vt, int lt, int rt) {
		if (l >= rt || lt >= r) {
			return;
		}
		if (l <= lt && rt <= r) {
			add_val(vt, 1);
			return;
		}
		push(vt);
		int mt = (lt + rt) / 2;
		add_seg(l, r, 2 * vt, lt, mt);
		add_seg(l, r, 2 * vt + 1, mt, rt);
		relax(vt);
	}
	void add_seg(int l, int r) {
		add_seg(l, r, 1, 0, n);
	}
	int get_max(int l, int r, int vt, int lt, int rt) {
		if (l >= rt || lt >= r) {
			return 0;
		}
		if (l <= lt && rt <= r) {
			return t[vt];
		}
		push(vt);
		int mt = (lt + rt) / 2;
		int a = get_max(l, r, 2 * vt, lt, mt);
		int b = get_max(l, r, 2 * vt + 1, mt, rt);
		relax(vt);
		return max(a, b);
	}
	int get_max(int l, int r) {
		return get_max(l, r, 1, 0, n);
	}
};

Tree tree;

vector <vector <Query>> v_qs;

void answer(int v) {
	for (auto q : v_qs[v]) {
		if (q.type == 2) {
			int u = q.i;
			answer(u);
			tree.add_seg(lt[u], rt[u] + 1);
		} else {
			int val = tree.get_max(lt[v], rt[v] + 1);
			res[q.ind] = val;
			if (val > 0) {
				int vv = num[val];
				tree.add_seg(lt[vv], lt[vv] + 1);
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	pval.resize(n, 0);
	pos.resize(n, 0);
	num.resize(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> pval[i];
		num[pval[i]] = i;
	}
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		edges.pb({v, u});
	}
	vector <int> deleted(m, false);
	vector <Query> queries;
	for (int i = 0; i < q; ++i) {
		int type;
		int x;
		cin >> type >> x;
		--x;
		queries.pb({type, x, i});
		if (type == 2) {
			deleted[x] = true;
		}
	}
	reverse(all(queries));

	DSU dsu(n);
	gr.resize(n);
	for (int i = 0; i < m; ++i) {
		if (deleted[i]) continue;
		int v = edges[i].x, u = edges[i].y;
		v = dsu.get(v), u = dsu.get(u);
		if (dsu.uni(v, u)) {
			if (dsu.p[v] == u) swap(v, u);
			gr[v].pb(u);
		}
	}

	v_qs.resize(n);

	for (int i = 0; i < q; ++i) {
		int type = queries[i].type, x = queries[i].i;
		if (type == 2) {
			int v = edges[x].x, u = edges[x].y;
			v = dsu.get(v), u = dsu.get(u);
			if (dsu.uni(v, u)) {
				if (dsu.p[v] == u) swap(v, u);
				gr[v].pb(u);
				auto q = queries[i];
				q.i = u;
				v_qs[v].pb(q);
			}
		} else {
			v_qs[dsu.get(x)].pb(queries[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		reverse(all(v_qs[i]));
	}

	reverse(all(queries));

	lt.resize(n, -1), rt.resize(n, -1);

	for (int i = 0; i < n; ++i) {
		if (dsu.p[i] != i) continue;
		dfs(i);
	}

	tree = Tree(values);

	res.resize(q, -1);

	for (int i = 0; i < n; ++i) {
		if (dsu.p[i] != i) continue;
		answer(i);
	}

	for (int i = 0; i < q; ++i) {
		if (queries[i].type == 1) {
			cout << res[i] << "\n";
		}
	}


}