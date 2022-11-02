#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, m;
vector<int> a;

void read() {
	cin >> n >> m;
	a.resize(m);
	for (auto &i : a)
		cin >> i, i--;
}

vector<int> ans_min, ans_max;

void calc_min() {
	ans_min.resize(n);
	iota(all(ans_min), 0);
	for (auto i : a) {
		ans_min[i] = 0;
	}
}

struct fenvik{
	int n;
	vector<int> tree;
	fenvik() {}
	fenvik(int sz) {
		n = sz;
		tree.assign(n, 0);
	}

	int get(int r) {
		int ans = 0;
//		for (int i = 0; i <= r; i++)
//			ans += tree[i];
		r = min(r, n - 1);
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ans += tree[r];
		return ans;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}

	void upd(int pos, int val) {
		//tree[pos] += val;
		for (; pos < n; pos |= pos + 1)
			tree[pos] += val;
	}
};

struct event{
	int l, r, ind;
	event() {}
	event(int a, int b, int c) {
		l = a, r = b, ind = c;
	}
};	

bool operator<(const event & a, const event & b) {
	return a.r < b.r;
}

void calc_max() {
	ans_max.resize(n);
	iota(all(ans_max), 0);
	vector<bool> used(n, 0);
	fenvik tree(n);
	for (auto i : a) {
		if (used[i]) continue;
		chkmax(ans_max[i], tree.get(i, n - 1) + i);
		tree.upd(i, 1);
		used[i] = true;
	}
	/*cout << "tree = " << endl;
	for (auto i : tree.tree)
		cout << i << " ";
	cout << endl;*/
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			//cout << tree.get(i, n - 1) << " " << i << endl;
			chkmax(ans_max[i], tree.get(i, n - 1) + i);
		}
	}
	/*cout << "used = " << endl;
	for (auto i : used)
		cout << i << " ";
	cout << endl;
	cout << "ans = " << endl;
	for (auto i : ans_max)
		cout << i << " ";
	cout << endl;*/

	vector<int> last(n, -1);
	vector<event> have;
	for (int i = 0; i < m; i++) {
		if (last[a[i]] != -1) {
			have.push_back({last[a[i]] + 1, i - 1, a[i]});
		}
		last[a[i]] = i;
	}	
	for (int i = 0; i < m; i++) {
		if (last[a[i]] != -1 && last[a[i]] != m - 1) {
			have.push_back({last[a[i]] + 1, m - 1, a[i]});
		}
	}
	last.assign(n, -1);
	sort(all(have));
	int pos = 0;
	tree = fenvik(m);
	for (int i = 0; i < m; i++) {
		if (last[a[i]] != -1) {
			tree.upd(last[a[i]], -1);
		}
		last[a[i]] = i;
		tree.upd(last[a[i]], 1);
		while (pos < have.size() && have[pos].r < i)
			pos++;
		while (pos < have.size() && have[pos].r == i) {
			chkmax(ans_max[have[pos].ind], tree.get(have[pos].l, have[pos].r));
			pos++;
		}
	}
}

void run() {
	calc_min();
	calc_max();
}

void write() {
	for (int i = 0; i < n; i++) {
		cout << ans_min[i] + 1 << " " << ans_max[i] + 1 << "\n";
	}
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