#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	int mx = 0, mn = 2e9;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		if (i) ans += abs(a[i] - a[i - 1]);
	}
	if (mn > 1) {
		int tmp = min(a[0], a[n - 1]) - 1;
		for (int i = 0; i < n - 1; ++i) {
			tmp = min(tmp, 2 * (min(a[i], a[i + 1]) - 1));
		}
		ans += tmp;
	}
	if (mx < x) {
		int tmp = x - max(a[0], a[n - 1]);
		for (int i = 0; i < n - 1; ++i) {
			tmp = min(tmp, 2 * (x - max(a[i], a[i + 1])));
		}
		ans += tmp;
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