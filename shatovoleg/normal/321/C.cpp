// #pragma GCC optimize("Ofast,unroll-all-loops")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

// template<class t>
// using oset = tree<t, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

#define int ll
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define mp make_pair

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int INF = 1e18 + 100;

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

void run();

signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

vector<vector<int>> g;

vector<int> used, sz;

vector<int> rnk, prv;
vector<vector<int>> pos;

int calc_sz_dfs(int v, int p = -1) {
	sz[v] = 1;
	for (auto &x : g[v]) {
		if (used[x] || x == p) {
			continue;
		}
		sz[v] += calc_sz_dfs(x, v);
	}
	return sz[v];
}

int find_centroid(int v, int s, int r = 0, int p = -1) {
	for (auto &x : g[v]) {
		if (!used[x] && x != p && (sz[x] << 1) >= s) {
			return find_centroid(x, s, r, v);
		}
	}
	rnk[v] = r;
	used[v] = 1;
	for (auto &x : g[v]) {
		if (used[x]) {
			continue;
		}
		int vv = find_centroid(x, calc_sz_dfs(x), r + 1);
		prv[vv] = v;
		pos[v].pb(vv);
	}
	return v;
}

void run() {
	int n;
	cin >> n;
	g.resize(n);
	used.resize(n);
	sz.resize(n);
	rnk.resize(n);
	prv.resize(n);
	pos.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	find_centroid(0, calc_sz_dfs(0));
	for (auto &x : rnk) {
		cout << (char)('A' + x) << " ";
	}
	cout << endl;
} // kek