#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> p;
vector<int> rp;

void read() {
	cin >> n;
	p.resize(n);
	for (auto &i : p)
		cin >> i, i--;
	rp.assign(n, 0);
	for (int i = 0; i < n; i++) {
		rp[p[i]] = i;
	}
}

struct segment_tree{
	vector<int> tree;
	vector<int> mod;
	int n;

	segment_tree() {}

	segment_tree(int sz) {
		n = sz;
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
		tree[v] = max(get_val(v * 2), get_val(v * 2 + 1));
	}

	void upd(int l, int r, int val) {
		upd(1, 0, n, l, r + 1, val);
		//for (int i = l; i <= r; i++)
		//	tree[i] += val;
	}

	void upd(int pos, int val) {
		upd(0, pos, val);
	}

	int get() {
		//int ans = 0;
		//for (auto i : tree)
		//	chkmax(ans, i);
		//return ans;
		return get_val(1);
	}

	void wr() {
		cout << "tree = " << endl;
		for (auto i : tree)
			cout << i << " ";
		cout << endl;
	}
};

segment_tree tree;
int now;

void build() {
	tree = segment_tree(n);
	now = n - 1;
	tree.upd(rp[now], 1);
}

void del(int pos) {
	tree.upd(pos, -1);
}

int get_ans() {
	while (tree.get() <= 0) {
		now--;
		assert(now >= 0);
		tree.upd(rp[now], 1);
	} 
	return now + 1;
}

vector<int> ans;

void run() {
	build();
	for (int i = 0; i < n; i++) {
		ans.push_back(get_ans());
		//tree.wr();
		int pos;
		cin >> pos;
		pos--;
		del(pos);
	}
}

void write() {
	for (auto i : ans)
		cout << i << " ";
	cout << endl; 
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