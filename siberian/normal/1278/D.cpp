#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 5e5 + 10;

struct segment{
	int l, r, ind;
	segment() {}
	segment(int a, int b, int c) {
		l = a, r = b, ind = c;
	}
};

bool operator<(const segment & a, const segment & b) {
	return a.r < b.r;
}

vector<int> g[MAXN];

struct ftree{
	int val, ind;
	ftree() {}
	ftree(int a, int b) {
		val = a, ind = b;
	}
};

bool operator<(const ftree & a, const ftree & b) {
	return tie(a.val, a.ind) < tie(b.val, b.ind);
}

int n;
ftree r[MAXN * 2];
vector<ftree> tree[MAXN * 8];

void build(int v, int tl, int tr) {
	if (tl == tr - 1) {
		if (r[tl].ind != -1)
			tree[v] = {r[tl]};
		else
			tree[v] = {};
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	tree[v].resize(tree[v * 2].size() + tree[v * 2 + 1].size());
	merge(all(tree[v * 2]), all(tree[v * 2 + 1]), tree[v].begin());
}

vector<int> get(int v, int tl, int tr, int l, int r, int X) {
	if (tl >= r || tr <= l) return {};
	if (tl >= l && tr <= r) {
		vector<int> ans;
		for (auto i : tree[v])
			if (i.val >= X) break;
			else ans.push_back(i.ind);
		return ans;
	}
	int tm = (tl + tr) / 2;
	vector<int> ans1 = get(v * 2, tl, tm, l, r, X);
	vector<int> ans2 = get(v * 2 + 1, tm, tr, l, r, X);
	for (auto i : ans2)
		ans1.push_back(i);
	return ans1;
}

vector<segment> a;

void no() {
	cout << "NO\n";
	exit(0);
}

bool used[MAXN];

void dfs(int v, int p) {
	used[v] = true;
	for (auto i : g[v]) {
		if (i == p) continue;
		if (used[i]) no();
		dfs(i, v);
	}
}

void solve() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].l--;
		a[i].r--;
		a[i].ind = i;
	}

	for (int i = 0; i < 2 * n; i++)
		r[i] = {-1, -1};

	sort(all(a));
	for (auto i : a) {
		r[i.r] = {i.l, i.ind};
	}

	/*cout << "a = " << endl;
	for (auto i : a)
		cout << i.l << " " << i.r << " " << i.ind << endl; 
 	*/

	build(1, 0, 2 * n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		vector<int> help = get(1, 0, 2 * n, a[i].l, a[i].r, a[i].l);
		/*cout << "i = " << i << endl;
		cout << "help = " << endl;
		for (auto j : help)
			cout << j << " ";
		cout << endl;*/
		if (cnt + help.size() >= n) no();
		for (auto j : help)
			g[a[i].ind].push_back(j), g[j].push_back(a[i].ind);
		cnt += help.size();
	}
	//cout << cnt << endl;
	if (cnt != n - 1) no();
	//cout << "puh" << endl;
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i, -1);
	cout << "YES\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	//cin >> t;
	t = 1;
	while (t--)
		solve();
	return 0;
}