#include <bits/stdc++.h>

using namespace std;

int vis[55];

void solve() {
	int n;
	cin >> n;
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < n + n; ++i) {
		int p;
		cin >> p;
		if (!vis[p]) cout << p << ' ', vis[p] = 1;
	}
	cout << '\n';
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