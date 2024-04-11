#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a1, a2, a3, a;

void read() {
	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	n = k1 + k2 + k3;
	a1.resize(k1);
	for (auto &i : a1)
		cin >> i, i--;
	sort(all(a1));
	for (auto i : a1)
		a.push_back(i);
	a1.resize(k2);
	for (auto &i : a1)
		cin >> i, i--;
	sort(all(a1));
	for (auto i : a1)
		a.push_back(i);
	a1.resize(k3);
	for (auto &i : a1)
		cin >> i, i--;
	sort(all(a1));
	for (auto i : a1)
		a.push_back(i);
}

struct segment_tree{
	vector<int> tree;
	int n;
	segment_tree() {}
	segment_tree(int sz) {
		n = sz;
		tree.resize(4 * n, 0);
	}

	void upd(int v, int tl, int tr, int l, int r, int val) {
		if (tl >= r || tr <= l) return;
		if (tl >= l && tr <= r) {
			tree[v] = val;
			return;
		} 
		int tm = (tl + tr) / 2;
		upd(v * 2, tl, tm, l, r, val);
		upd(v * 2 + 1, tm, tr, l, r, val);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}

	void upd(int pos, int val) {
		upd(1, 0, n, pos, pos + 1, val);
		//tree[pos] = val;
	}

	int get(int v, int tl, int tr, int l, int r) {
		if (tl >= r || tr <= l) return 0;
		if (tl >= l && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));

	}

	int get(int l, int r) {
		return get(1, 0, n, l, r + 1);
		int ans = 0;
		for (int i = l; i <= r; i++)
			ans = max(ans, tree[i]);
		return ans;
	}
};

int ans;

void run() {
	segment_tree dp(n);
	for (int i = 0; i < n; i++) {
		int fans = dp.get(0, a[i] - 1);
		dp.upd(a[i], fans + 1);
	}
	ans = n - dp.get(0, n - 1);
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}