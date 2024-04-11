#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1e9;
	for (int i = 0; i < n - 1; ++i) {
		int x = min(a[i], a[i + 1]), y = max(a[i], a[i + 1]);
		if (x + x < y) ans = min(ans, (y + 1) / 2);
		else ans = min(ans, y - x + (x + x - y) / 3 * 2 + (x + x - y) % 3);
	}
	for (int i = 0; i < n - 2; ++i) {
		int x = min(a[i], a[i + 2]), y = max(a[i], a[i + 2]);
		ans = min(ans, (y - x + 1) / 2 + x);
	}
	sort(a.begin(), a.end());
	ans = min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}