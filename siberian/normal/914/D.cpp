#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct segment_tree{
	vector<int> tree;
	vector<int> pos;
	int n;
	segment_tree() {}

	void build(int v, int tl, int tr, const vector<int> & a) {
		if (tl == tr - 1) {
			tree[v] = a[tl];
			pos[tl] = v;
			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm, a);
		build(v * 2 + 1, tm, tr, a);
		tree[v] = __gcd(tree[v * 2], tree[v * 2 + 1]);
	}

	segment_tree(vector<int> a) {
		n = a.size();
		tree.assign(n * 4, 0);
		pos.assign(n, 0);
		build(1, 0, n, a);
	}

	int get(int v, int tl, int tr, int l, int r) {
		if (tl >= r || tr <= l) return 0;
		if (tl >= l && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return __gcd(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
	}

	int get_pos(int v, int tl, int tr, int l, int r, int x) {
		if (tree[v] % x == 0) return -1;
		if (tl >= r || tr <= l) return -1;
		if (tl == tr - 1) {
			return tl;
		}
		int tm = (tl + tr) / 2;
		int ans = get_pos(v * 2, tl, tm, l, r, x);
		if (ans == -1)
			ans = get_pos(v * 2 + 1, tm, tr, l, r, x);
		return ans;
	}

	int get_pos(int l, int r, int x) {
		return get_pos(1, 0, n, l, r + 1, x);
	}

	int get(int l, int r) {
		if (l > r) return 0; 
		return get(1, 0, n, l, r + 1);
	}

	void set_val(int p, int val) {
		int v = pos[p];
		tree[v] = val;
		v /= 2;
		while (v) {
			tree[v] = __gcd(tree[v * 2], tree[v * 2 + 1]);
			v /= 2;
		}
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	segment_tree tree(a);	
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			r--;
			if (r - l == 0) {
				cout << "YES\n";
				continue;
			}
			if (tree.get(l + 1, r) % x == 0) {
				cout << "YES\n";
				continue;
			}
			int tl = tree.get_pos(l, r, x) ;
			if (tl == -1) {
				cout << "YES\n";
				continue;
			}
			if (tree.get(tl + 1, r) % x == 0) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			int pos, val;
			cin >> pos >> val;
			pos--;
			tree.set_val(pos, val);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}