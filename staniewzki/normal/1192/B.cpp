#include<bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }

using LL = long long;
using PII = pair<LL, LL>;

using T = LL;
struct Node {
	T val, lazy;
	int size = 1;
};

struct Tree {
	vector<Node> tree;
	int size = 1;

	void add_val(int v, T val) {
		tree[v].val += val;
		tree[v].lazy += val;
	}

	T f(T a, T b) { return max(a, b); }

	Tree(int n) {
		while(size < n) size *= 2;
		tree.resize(size * 2);
		for(int i = size - 1; i >= 1; i--)
			tree[i].size = tree[i * 2].size * 2;
	}

	void propagate(int v) {
		REP(i, 2)
			add_val(v * 2 + i, tree[v].lazy);
		tree[v].lazy = 0;
	}

	T query(int l, int r, int v = 1) {
		if(l == 0 && r == tree[v].size - 1)
			return tree[v].val;
		propagate(v);	
		int m = tree[v].size / 2;
		if(r < m)
			return query(l, r, v * 2);
		else if(m <= l)
			return query(l - m, r - m, v * 2 + 1);
		else
			return f(query(l, m - 1, v * 2), query(0, r - m, v * 2 + 1));
	}

	void add(int l, int r, T val, int v = 1) {
		if(l == 0 && r == tree[v].size - 1) {
			add_val(v, val);
			return;
		}
		propagate(v);
		int m = tree[v].size / 2;
		if(r < m)
			add(l, r, val, v * 2);
		else if(m <= l)
			add(l - m, r - m, val, v * 2 + 1);
		else
			add(l, m - 1, val, v * 2), add(0, r - m, val, v * 2 + 1);

		tree[v].val = f(tree[v * 2].val, tree[v * 2 + 1].val);
	}
};

vector<vector<pair<int, LL>>> adj;
vector<int> del, sz, t;
vector<vector<int>> cen, pre, pos, par, sub;
vector<vector<LL>> dst;
vector<multiset<LL>> under;
multiset<LL> all;
vector<Tree> tree;

int dfs_count(int v, int p = -1) {
	sz[v] = 1;
	for(auto &[u, w] : adj[v]) {
		if(u != p && !del[u])
			sz[v] += dfs_count(u, v);
	}
	return sz[v];
}

int dfs_centro(int v, int tot, int p = -1) {
	bool is_centro = true;
	for(auto &[u, w] : adj[v]) {
		if(u != p && !del[u]) {
			int ret = dfs_centro(u, tot, v);
			if(ret != -1) return ret;
			if(sz[u] * 2 > tot)
				is_centro = false;
		}
	}
	if((tot - sz[v]) * 2 > tot) is_centro = false;
	if(is_centro) return v;
	return -1;
}

int get_centro(int v) {
	int tot = dfs_count(v);
	return dfs_centro(v, tot);
}

LL get_diameter(multiset<LL> &s) {
	LL diameter = 0;
	auto it = s.end();
	REP(i, 2) {
		if(it == s.begin()) break;
		it = prev(it);
		diameter += *it;
	}
	return diameter;
}

void delete_val(multiset<LL> &s, LL val) { 
	s.erase(s.find(val));
}

void dfs_decomp(int v, int d, int p = -1) {
	par[d][v] = p;
	pre[d][v] = ++t[d];
	tree[d].add(pre[d][v], pre[d][v], dst[d][v]);
	if(p == -1) cen[d][v] = v;
	for(auto &[u, w]: adj[v]) {
		if(u != p && !del[u]) {
			dst[d][u] = dst[d][v] + w;
			cen[d][u] = cen[d][v];
			sub[d][u] = (p == -1 ? u : sub[d][v]);
			dfs_decomp(u, d, v);
		}
	}
	pos[d][v] = t[d];
}

void decomp(int n, int v = 0, int d = 0) {
	int centro = get_centro(v);
	del[centro] = true;
	if(size(dst) <= d) {
		for(auto *p : {&pre, &pos, &par, &cen, &sub})
			p->emplace_back(n, -1);
		dst.emplace_back(n);
		tree.emplace_back(n);
		t.emplace_back(-1);
	}

	dfs_decomp(centro, d);
	for(auto &[u, w] : adj[centro]) if(!del[u]) {
		int l = pre[d][u], r = pos[d][u];
		under[centro].emplace(tree[d].query(l, r));
		decomp(n, u, d + 1);
	}

	debug(centro, d, under[centro]);

	all.emplace(get_diameter(under[centro]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	LL max_w;
	cin >> n >> q >> max_w;

	adj.resize(n);
	vector<int> a(n - 1), b(n - 1);
	vector<LL> w(n - 1);
	REP(i, n - 1) {
		cin >> a[i] >> b[i] >> w[i];
		a[i]--, b[i]--;
		adj[a[i]].emplace_back(b[i], w[i]);
		adj[b[i]].emplace_back(a[i], w[i]);
	}

	del.resize(n);
	sz.resize(n);
	under.resize(n);
	decomp(n);

	debug(all);

	LL last = 0;
	REP(i, q) {
		int d;
		LL e;
		cin >> d >> e;
		d = (d + last) % (n - 1);
		e = (e + last) % max_w;
		LL delta = e - w[d];
		w[d] = e;

		REP(j, size(dst)) {
			auto update = [&](int x, int y) {
				if(par[j][x] != y) return;
				int s = sub[j][x];
				int ls = pre[j][s], rs = pos[j][s];
				int lx = pre[j][x], rx = pos[j][x];
				int centro = cen[j][x];
				if(centro == -1) return;
				delete_val(all, get_diameter(under[centro]));
				delete_val(under[centro], tree[j].query(ls, rs));
				tree[j].add(lx, rx, delta);
				under[centro].emplace(tree[j].query(ls, rs));
				all.emplace(get_diameter(under[centro]));
			};

			update(a[d], b[d]);
			update(b[d], a[d]);
		}

		cout << (last = *all.rbegin()) << "\n";
	}
}