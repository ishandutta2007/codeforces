#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, m;
vector<int> a, p, b;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	p.resize(n);
	for (auto &i : p)
		cin >> i;
	cin >> m;
	b.resize(m);
	for (auto &i : b)
		cin >> i;
}

void check() {
	int now = 0;
	for (auto i : a) {
		if (i == b[now]) now++;
		if (now == m) return;
	}
	cout << "NO\n";
	exit(0);
}

const int INF = 1e18;
int ans;

struct segment_tree{
	vector<int> tree, mod;
	int n;
	segment_tree() {}

	segment_tree(int _n) {
		n = _n;
		tree.assign(4 * n, 0);
		mod.assign(4 * n, 0);
	}

	void push(int v) {
		mod[v * 2] += mod[v];
		mod[v * 2 + 1] += mod[v];
		tree[v] += mod[v];
		mod[v] = 0;
	}

	int get_val(int v) {
		return tree[v] + mod[v];
	}

	void upd(int v, int tl, int tr, int l, int r, int val) {
		if (tl >= r || tr <= l) return;
		if (tl >= l && tr <= r) {
			mod[v] += val;
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		upd(v * 2, tl, tm, l, r, val);
		upd(v * 2 + 1, tm, tr, l, r, val);
	}

	void upd(int l, int r, int val) {
		if (r < l) return;
		upd(1, 0, n, l, r + 1, val);
	}


	void upd(int r, int val) {
		upd(0, r, val);
	}

	int get(int v, int tl, int tr, int pos) {
		if (tl >= pos + 1 || tr <= pos) return INF;
		if (tl == tr - 1) {
			return get_val(v);
		}
		push(v);
		int tm = (tl + tr) / 2;
		return min(get(v * 2, tl, tm, pos), get(v * 2 + 1, tm, tr, pos));
	}

	int get(int pos) {
		if (pos < 0 || pos > n) return INF;
		return get(1, 0, n, pos);
	}

	bool set_val(int pos, int val) {
		if (pos < 0 || pos > n) return false;
		int have = get(pos);
		if (have <= val) return false;
		upd(pos, pos, -have);
		upd(pos, pos, val);
		return true;
	}
};

void solve() {
	segment_tree tree(m + 1);
	tree.upd(1, m, INF);
	int mx_val = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] <= 0) {
			int pos = lower_bound(all(b), a[i]) - b.begin();
			if (pos >= 0 && pos < m && b[pos] == a[i]) {
				if (mx_val >= pos) chkmax(mx_val, pos + 1);
				int have1 = tree.get(pos);
				int have2 = tree.get(pos + 1) + p[i];
				tree.set_val(pos + 1, min(have1, have2));
				tree.upd(0, min(pos, mx_val), p[i]);
				if (pos + 2 <= mx_val) {
					tree.upd(pos + 2, min(m, mx_val), p[i]);
				}
			} else {
				tree.upd(min(m, mx_val), p[i]);
			}
		} else {
			int pos = lower_bound(all(b), a[i]) - b.begin();
			if (pos >= 0 && pos < m && b[pos] == a[i]) {
				if (mx_val >= pos) chkmax(mx_val, pos + 1);
				int have = tree.get(pos);
				tree.set_val(pos + 1, have);
				tree.upd(min(pos, mx_val), p[i]);
			} else {
				tree.upd(min(pos, mx_val), p[i]);
			}
		}
	}
	ans = tree.get(m);
	if (ans >= INF) {
		cout << "NO\n";
		exit(0);
	}
}

void run() {
	check();
	solve();
}

void write() {
	cout << "YES\n";
	cout << ans << "\n";
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