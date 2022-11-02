#include <bits/stdc++.h>

using namespace std;
#define int long long

struct segment_tree_sum {
	vector <int> tree;
	int n;

	void build(int v, int l, int r, const vector <int> & a) {
		if (l == r - 1) {
			tree[v] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(v * 2, l, m, a);
		build(v * 2 + 1, m, r, a);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}

	segment_tree_sum() {
		n = 0;
		tree = {};
	}

	segment_tree_sum(vector <int> a) {
		n = a.size();
		tree.assign(n * 4, 0);
		build(1, 0, n, a);
	}

	void upd(int v, int tl, int tr, int l, int r, int val) {
		if (tl >= r || tr <= l)
			return;
		if (tl == l && tr == r) {
			tree[v] = val;
			return;
		}
		int tm = (tl + tr) / 2;
		upd(v * 2, tl, tm, l, r, val);
		upd(v * 2 + 1, tm, tr, l, r, val);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}

	int get(int v, int tl, int tr, int l, int r) {
		if (tl >= r || tr <= l)
			return 0;
		if (tl >= l && tr <= r)
			return tree[v];
		int tm = (tl + tr) / 2;
		int ans = get(v * 2, tl, tm, l, r) + get(v * 2 + 1, tm, tr, l, r);
		return ans;
	}

	void upd(int pos, int val) {
		upd(1, 0, n, pos, pos + 1, val);
	}

	int get(int l, int r) {
		return get(1, 0, n, l, r + 1);
	}

	int get_next(int v, int tl, int tr, int sum) {
		if (tl == tr - 1)
			return tl;
		int tm = (tl + tr) / 2;
		if (tree[v * 2] >= sum)
			return get_next(v * 2, tl, tm, sum);
		else
			return get_next(v * 2 + 1, tm, tr, sum - tree[v * 2]);
	}

	int get_next(int sum) {
		if (get(1, 0, n, 0, n) < sum)
			return -1;
		return get_next(1, 0, n, sum);
	}
};


int n, q;
vector <int> a;
void read() {
	cin >> n >> q;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

segment_tree_sum tree_sum;

int solve() {
	int pos = -1;
	while (pos < n - 1) {
		int sum = tree_sum.get(0, pos);

		int new_pos = tree_sum.get_next(sum * 2);
		if (new_pos == -1)
			return -1;
		sum = tree_sum.get(0, new_pos - 1);
		int have = a[new_pos];
		if (sum == have)
			return new_pos + 1;
		pos = new_pos;
	}
	return -1;
}

vector <int> ans;

void run() {
	tree_sum = segment_tree_sum(a);

	for (int test = 0; test < q; test++) {
		int pos, val;
		cin >> pos >> val;
		pos--;
		tree_sum.upd(pos, val);
		a[pos] = val;
		int fans = solve();
		ans.push_back(fans);
	}
}

void write() {
	for (auto i : ans)
		cout << i << '\n';
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