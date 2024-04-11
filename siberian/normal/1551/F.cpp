#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

const int MOD = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= MOD) return a - MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) return a + MOD;
	return a;
}

int mul(int a, int b) {
	return (ll)a * b % MOD;
}

const int N = 110;
int n, k;
vector<int> g[N];
vector<bool> used;

vector<vector<int>> cnt;

void dfs(int v, int p, int h, int id) {
	cnt[h][id]++;
	++h;
	for (auto i : g[v]) {
		if (i == p) continue;
		dfs(i, v, h, id);
	}
}

int calc(vector<int>& a) {
	sort(all(a));
	reverse(all(a));
	while (!a.empty() && a.back() == 0)	a.pop_back();
	if (a.size() < k) return 0;
	vector<int> dp(k + 1, 0);
	dp[0] = 1;
	for (auto i : a) {
		for (int x = k; x > 0; --x) {
			dp[x] = add(dp[x], mul(dp[x - 1], i));
		}
	}
	return dp[k];
}

int calc(int root) {
	if (g[root].size() < k) return 0;
	cnt.assign(n, vector<int>(g[root].size(), 0));
	for (int i = 0; i < g[root].size(); ++i) {
		dfs(g[root][i], root, 0, i);
	}
	int ans = 0;
	for (auto& i : cnt) {
		ans = add(ans, calc(i));
	}
	return ans;
}

void solve() {
	cin >> n >> k;
	fill(g, g + n, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	if (k == 2) {
		ans = n * (n - 1) / 2;
	} else {
		for (int root = 0; root < n; ++root) {
			ans = add(ans, calc(root));
		}
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}