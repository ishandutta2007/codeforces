#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define fadd fadd228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll
const int INF = 1e18;

struct segment_tree{
	vector<int> tree;
	vector<int> pos;
	int n;
	segment_tree() {}

	void build(int v, int tl, int tr) {
		if (tl == tr - 1) {
			pos[tl] = v;
			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm, tr);
	}

	segment_tree(int _n) {
		n = _n;
		tree.assign(n * 4, INF);
		pos.assign(n, 0);
		build(1, 0, n);
	}

	int get(int v, int tl, int tr, int l, int r) {
		if (tl >= r || tr <= l) return INF;
		if (tl >= l && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return min(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
	}

	int get(int l, int r) {
		if (r < l) return 0;
		return get(1, 0, n, l, r + 1);
		int ans = INF;
		for (int i = l; i <= r; i++) {
			chkmin(ans, tree[i]);
		}
		return ans;
	}

	void upd(int v, int val) {
		v = pos[v];
		chkmin(tree[v], val);
		v /= 2;
		while (v) {
			tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
			v /= 2;
		}
	}

	void wr() {
		cout << "tree = " << endl;
		for (auto i : tree)
			cout << i << " ";
		cout << endl;
	}
};

int n, k;
string s;

void solve() {
	cin >> n >> k;
	cin >> s;
	segment_tree dp(n + 1);
	dp.upd(0, 0);
	//dp.wr();
	for (int i = 1; i <= n; i++) {
		int val;
		val = dp.get(max(0LL, i - 1), i - 1);
		dp.upd(i, val + i);
		if (s[i - 1] == '1') {
			val = dp.get(max(0LL, i - k - 1), i - 1);
			dp.upd(min(n, i + k), val + i);
			dp.upd(i, val + i);
		}
		//dp.wr();
	}
	cout << dp.get(n, n) << endl;
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