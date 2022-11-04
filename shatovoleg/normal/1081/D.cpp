#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

#define int ll
#define all(v) v.begin(), v.end()
#define len(v) (int)(v).size()
#define pii pair<int, int>
#define pb push_back
#define kek pop_back

// template<class t>
// using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

void UseFiles(const string &s) {
#ifndef LOCAL
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
#endif
}

void run();

signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

struct dsu {
	vector<int> l, h, cnt;

	dsu(int n, vector<int> x) {
		l.resize(n);
		h.resize(n, 0);
		cnt.resize(n, 0);
		iota(all(l), 0);
		for (auto &x : x)
			++cnt[x];
	}

	int get_root(int v) {
		if (l[v] == v)
			return v;
		return l[v] = get_root(l[v]);
	}

	bool Union(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v)
			return false;
		if (h[u] > h[v])
			swap(u, v);
		cnt[v] += cnt[u];
		l[u] = v;
		if (h[u] == h[v])
			++h[v];
		return true;
	}
};

void run() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(k);
	for (auto &x : a) {
		cin >> x;
		--x;
	}
	vector<vector<int>> e(m, vector<int>(3));
	for (auto &x : e) {
		cin >> x[1] >> x[2] >> x[0];
		--x[1], --x[2];
	}
	sort(all(e));
	dsu d(n, a);
	int ans = 0;
	for (auto &x : e) {
		if (d.cnt[d.get_root(a[0])] != k && d.Union(x[1], x[2]))
			ans = x[0];
	}
	for (int i = 0; i < k; ++i)
		cout << ans << " ";
	cout << endl;
}