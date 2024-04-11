#include <bits/stdc++.h>

using namespace std;

int a[300005];

void solve() {
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	long long ans = 1e18;
	for (int i = 0; i < 10; ++i) {
		long long ans1, x = 0, y = 0, sum = 0;
		for (int j = 0; j < n; ++j) {
			int d = mx + i - a[j];
			sum += d;
			if (d & 1) ++x;
			y += d >> 1;
			if (x <= y) ans1 = sum / 3 * 2 + sum % 3;
			else ans1 = x * 2 - 1;
		}
		ans = min(ans, ans1);
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