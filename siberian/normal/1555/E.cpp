#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

struct SegmentTree{
	int n;
	vector<int> tree;
	vector<int> mod;
	SegmentTree() {}
	SegmentTree(int _n) {
		n = _n;
		tree.assign(4 * n, 0);
		mod.assign(4 * n, 0);
	}
	void push(int v) {
		mod[v * 2] += mod[v];
		mod[v * 2 + 1] += mod[v];
		mod[v] = 0;
	}
	int getVal(int v) {
		return tree[v] + mod[v];
	}
	void upd(int v, int tl, int tr, int l, int r, int x) {
		if (tl >= r || tr <= l) return;
		if (tl >= l && tr <= r) {
			mod[v] += x;
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		upd(v * 2, tl, tm, l, r, x);
		upd(v * 2 + 1, tm, tr, l, r, x);
		tree[v] = min(getVal(v * 2), getVal(v * 2 + 1));
	}
	void upd(int l, int r, int x) {
		// for (int i = l; i <= r; ++i) {
		// 	tree[i] += x;
		// }
		upd(1, 0, n, l, r + 1, x);
	}
	int get() {
		return getVal(1);
		// return *min_element(tree.begin(), tree.begin() + n);
	}
	void print() {
		for (int i = 0; i < n; ++i) {
			cerr << tree[i] << " ";
		}
		cerr << endl;
	}
};

struct Segment{
	int l, r, w;
};

bool operator<(const Segment& a, const Segment& b) {
	return a.w < b.w;
}

int n, m;
vector<Segment> a;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	cin >> n >> m;
	a.resize(n);
	for(auto& i : a) {
		cin >> i.l >> i.r >> i.w;
		--i.l;
		i.r--;
		if (i.r != m - 1) --i.r;
		i.w;
	}
	sort(all(a));
	SegmentTree tree(m);
	int r = 0;
	int ans = INT_MAX;
	for (int l = 0; l < n; ++l) {
		while (r < n && tree.get() == 0) {
			tree.upd(a[r].l, a[r].r, 1);
			++r;
		}
		// tree.print();
		// cerr << "l = " << l << " r = " << r << endl;
		if (tree.get() == 0) break;
		chkmin(ans, a[r - 1].w - a[l].w);
		tree.upd(a[l].l, a[l].r, -1);
	}

	cout << ans << endl;
	return 0;
}