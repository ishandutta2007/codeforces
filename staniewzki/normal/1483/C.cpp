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

using PII = pair<int, int>;

struct Tree {
	using T = PII;
	T f(T a, T b) { return min(a, b); }
	vector<T> tree;
	int sz = 1;

	Tree(int n) {
		while(sz < n) sz *= 2;
		tree.resize(sz * 2);
	}

	void update(int pos, T val) {
		tree[pos += sz] = val;
		while(pos /= 2)
			tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
	}

	T query(int l, int r) {
		l += sz, r += sz;
		T ret = (l != r ? f(tree[l], tree[r]) : tree[l]);
		while(l + 1 < r) {
			if(l % 2 == 0)
				ret = f(ret, tree[l + 1]);
			if(r % 2 == 1)
				ret = f(ret, tree[r - 1]);
			l /= 2, r /= 2;
		}
		return ret;
	}
};

Tree tree(0);
vector<int> h, bt;

LL solve(int l, int r, bool fixed_l, bool fixed_r) {
	if(l > r) return 0;
	int m = tree.query(l, r).second;
	LL a = solve(l, m - 1, fixed_l, false);
	LL b = solve(m + 1, r, false, fixed_r);

	LL ret = a + bt[m] + b;
	if(!fixed_l)
		ret = max(ret, b);
	if(!fixed_r)
		ret = max(ret, a);
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	h = bt = vector<int>(n);
	REP(i, n)
		cin >> h[i];
	REP(i, n)
		cin >> bt[i];

	tree = Tree(n);
	REP(i, n)
		tree.update(i, {h[i], i});

	cout << solve(0, n - 1, true, true) << "\n";
}