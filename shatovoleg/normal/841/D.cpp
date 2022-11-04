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

double f(int n, int k) {
	int sm = 0, cnt = 0;
	for (int msk = 0; msk < (1 << n); ++msk) {
		if (__builtin_popcount(msk) != k)
			continue;
		int mx = 1e9 + 7;
		for (int i = 0; i < n; ++i)
			if (msk & (1 << i))
				cmin(mx, i);
		sm += mx;
		++cnt;
	}
	return (ld)sm / cnt;
}

vector<int> used;
vector<vector<pii>> g;
vector<int> d;

pair<int, int> dfs1(int v) {
	pii ans = {-1, max(d[v], 0LL)};
	if (d[v] == -1) {
		ans.first = v;
		d[v] = 0;
	}
	used[v] = 1;
	for (auto &x : g[v]) {
		if (used[x.first])
			continue;
		auto a = dfs1(x.first);
		ans.second ^= a.second;
		if (a.first != -1)
			ans.first = a.first;
	}
	return ans;
}

vector<int> ans;
int dfs2(int v) {
	int ret = d[v];
	used[v] = 2;
	for (auto &x : g[v]) {
		if (used[x.first] == 2)
			continue;
		int a = dfs2(x.first);
		ret ^= a;
		if (a)
			ans.pb(x.second);
	}
	return ret;
}

void run() {
	int n, m;
	cin >> n >> m;
	used.resize(n, 0);
	g.resize(n);
	d.resize(n);
	for (auto &x : d)
		cin >> x;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb({v, i});
		g[v].pb({u, i});
	}
	for (int i = 0; i < n; ++i) {
		if (used[i])
			continue;
		auto asdf = dfs1(i);
		if (asdf.first != -1) {
			d[asdf.first] = asdf.second;
		} else if (asdf.second) {
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (used[i] == 2)
			continue;
		dfs2(i);
	}
	cout << len(ans) << endl;
	for (auto &x : ans)
		cout << x + 1 << " ";
	cout << endl;
}