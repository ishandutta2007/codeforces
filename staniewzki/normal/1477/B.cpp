#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

using T = int;
struct Node {
	T val = 0, lazy = -1;
	int sz = 1;
};

struct Tree {
	vector<Node> tree;
	int sz = 1;

	void add_val(int v, T val) {
		tree[v].val = tree[v].sz * val;
		tree[v].lazy = val;
	}

	T f(T a, T b) { return a + b; }

	Tree(int n) {
		while(sz < n) sz *= 2;
		tree.resize(sz * 2);
		for(int i = sz - 1; i >= 1; i--)
			tree[i].sz = tree[i * 2].sz * 2;
	}

	void propagate(int v) {
		if(tree[v].lazy == -1)
			return;
		REP(i, 2)
			add_val(v * 2 + i, tree[v].lazy);
		tree[v].lazy = -1;
	}

	T query(int l, int r, int v = 1) {
		if(l == 0 && r == tree[v].sz - 1)
			return tree[v].val;
		propagate(v);	
		int m = tree[v].sz / 2;
		if(r < m)
			return query(l, r, v * 2);
		else if(m <= l)
			return query(l - m, r - m, v * 2 + 1);
		else
			return f(query(l, m - 1, v * 2), query(0, r - m, v * 2 + 1));
	}

	void add(int l, int r, T val, int v = 1) {
		if(l == 0 && r == tree[v].sz - 1) {
			add_val(v, val);
			return;
		}
		propagate(v);
		int m = tree[v].sz / 2;
		if(r < m)
			add(l, r, val, v * 2);
		else if(m <= l)
			add(l - m, r - m, val, v * 2 + 1);
		else
			add(l, m - 1, val, v * 2), add(0, r - m, val, v * 2 + 1);

		tree[v].val = f(tree[v * 2].val, tree[v * 2 + 1].val);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	REP(_t, t) {
		int n, q;
		cin >> n >> q;
		string s, f;
		cin >> s >> f;
		vector<int> l(q), r(q);
		REP(i, q)
			cin >> l[i] >> r[i];

		Tree tree(n);
		REP(i, n)
			tree.add(i, i, f[i] - '0');

		bool fail = false;
		for(int i = q - 1; i >= 0; i--) {
			l[i]--, r[i]--;
			int cnt = tree.query(l[i], r[i]);
			int len = r[i] - l[i] + 1;
			if(2 * cnt > len)
				tree.add(l[i], r[i], 1);
			else if(2 * cnt < len)
				tree.add(l[i], r[i], 0);
			else {
				fail = true;
				break;
			}
		}

		REP(i, n)
			if(tree.query(i, i) != s[i] - '0')
				fail = true;

		cout << (fail ? "NO" : "YES") << "\n";
	}
}