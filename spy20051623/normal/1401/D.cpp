#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> g[N];
long long w[N], sz[N];

long long dfs(int p, int f) {
	sz[p] = 1;
	for (int i: g[p]) {
		if (i == f) continue;
		sz[p] += dfs(i, p);
	}
	return sz[p];
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 2; i <= n; ++i) {
		w[i] = sz[i] * (n - sz[i]);
	}
	sort(w + 2, w + n + 1, greater<long long>());
	for (int i = 2; i <= n; ++i) {
		w[i] %= mod;
	}
	vector<long long> v;
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		long long p;
		cin >> p;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	while (v.size() > n - 1) v[v.size() - 2] = v[v.size() - 2] * v.back() % mod, v.pop_back();
	reverse(v.begin(), v.end());
	while (v.size() < n - 1) v.push_back(1);
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		ans = (ans + w[i + 2] * v[i]) % mod;
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}