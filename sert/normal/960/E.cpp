#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator << (ostream &fo, vector<T> v) {
	fo << "[";
	for (int i = 0; i < (int)v.size(); i++) {
		if (i) fo << " ";
		fo << v[i];
	}
	fo << "]";
	return fo;
}

typedef long long ll;
const ll MD = (ll)1e9 + 7;

ll ans;
vector<int> sz;
vector<int> par;
int gl_col;

int dfs_sz(int v, int pr, const vector<unordered_set<int>> &es) {
	sz[v] = 1;
	for (int w : es[v]) {
		if (w == pr) continue;
		sz[v] += dfs_sz(w, v, es);
		par[w] = v;
	}
	return sz[v];
}

int dfs_bst(int v, int pr, const vector<unordered_set<int>> &es, int tot) {
	for (int w : es[v]) {
		if (w == pr) continue;
		if (sz[w] * 2 > tot) return dfs_bst(w, v, es, tot);
	}
	return v;
}

vector<ll> dfs_cnt(int v, int pr, const vector<unordered_set<int>> &es, const vector<ll> &a) {
	vector<ll> ans = {0, 1, 0, 0};
	for (int w : es[v]) {
		if (w == pr) continue;
		auto kk = dfs_cnt(w, v, es, a);
		ans[0] += kk[1];
		ans[1] += kk[0];
		ans[2] += kk[3];
		ans[3] += kk[2];
	}
	ans[2] += MD * MD - ans[0] * a[v];
	ans[3] += ans[1] * a[v];
	for (ll &x : ans) x %= MD;
	return ans;
}


// n_even, n_odd, s_even, s_odd
vector<ll> solve(int v, const vector<ll> &a, vector<unordered_set<int>> &es) {
	// cout << "solve: " << v << " " << col[v] << " " << col << endl;
	dfs_sz(v, -1, es);
	par[v] = -1;
	if (sz[v] == 1) {
		ans = (ans + a[v]) % MD;
		return {0, 1, 0, a[v]};
	}
	auto res = dfs_cnt(v, -1, es, a);
	int bst = dfs_bst(v, -1, es, sz[v]);

	// cout << bst << endl;
	ans = (ans + a[bst]) % MD;
	vector<vector<ll>> b;
	vector<ll> sum(4, 0);
	for (int w : es[bst]) {
		es[w].erase(bst);
		b.push_back(solve(w, a, es));
		for (int i = 0; i < 4; i++) sum[i] += b.back()[i];
	}
	for (ll &s : sum) s %= MD;

	ll nw = 0;
	// cout << sum << endl;
	for (int i = 0; i < (int)b.size(); i++) {
		// cout << "b: " << b[i] << endl;
		nw += (b[i][2] + b[i][0] * a[bst]) * 2;
		ll n_e = (MD + sum[0] - b[i][0]) % MD;
		ll n_o = (MD + sum[1] - b[i][1]) % MD;
		ll s_e = (MD + sum[2] - b[i][2]) % MD;
		ll s_o = (MD + sum[3] - b[i][3]) % MD;
		ll x1 = (MD * MD + b[i][0] * n_e - b[i][1] * n_o) % MD * a[bst];
		nw = (nw + x1) % MD;
		ll x2 = b[i][0] * s_e + b[i][2] * n_e + b[i][1] * s_o + b[i][3] * n_o;
		nw = (nw + x2) % MD;
		// cout << "x12: " << x1 % MD << " " << x2 % MD << endl;
	}

	// cout << "nw: " << bst << " " << nw << endl;

	ans = (ans + nw) % MD;
	// cout << "res: " << v << " " << res << endl;
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x : a) {
		cin >> x;
		x = (x + MD) % MD;
	}
	vector<unordered_set<int>> es(n);
	sz.resize(n);
	par.resize(n);
	gl_col = 1;
	for (int i = 1; i < n; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].insert(v2);
		es[v2].insert(v1);
	}

	ans = 0;
	solve(0, a, es);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 1;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}