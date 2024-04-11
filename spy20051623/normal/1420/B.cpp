#include <bits/stdc++.h>

using namespace std;

long long ans;

void dfs(const vector<int> &v, int p) {
	if (v.empty()) return;
	vector<int> l, r;
	for (int i: v) {
		if (i >> p & 1) l.push_back(i);
		else r.push_back(i);
	}
	ans += 1ll * (int) l.size() * ((int) l.size() - 1) / 2;
	if (p) dfs(r, p - 1);
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	ans = 0;
	dfs(v, 30);
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}