#include <bits/stdc++.h>

using namespace std;

int a[2005][2005], vis[2005][2005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			vis[i][j] = 0;
		}
	}
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!vis[i - 1][j]) {
				ans ^= a[i - 1][j];
				vis[i - 1][j] ^= 1;
				if (j > 0) vis[i][j - 1] ^= 1;
				if (j < n - 1) vis[i][j + 1] ^= 1;
				if (i < n - 1) vis[i + 1][j] ^= 1;
			}
		}
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