#include <bits/stdc++.h>

using namespace std;

int vis[200005];

void solve() {
	int n;
	cin >> n;
	memset(vis, 0, (n + 5) << 2);
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		if (p <= n && !vis[p]) vis[p] = 1;
		else v.push_back(p);
	}
	sort(v.begin(), v.end());
	int ans = n;
	for (int i = 1, j = 0; i <= n; ++i) {
		if (vis[i]) --ans;
		else if (v[j] <= i + i) {
			cout << -1 << '\n';
			return;
		} else ++j;
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