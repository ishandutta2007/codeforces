#include <bits/stdc++.h>

using namespace std;

int a[5005], m[5005];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	fill(m, m + 5005, -2e9);
	m[0] = 0;
	for (int i = 0; i < n; ++i) {
		int s = 0;
		for (int j = 0; j < n - i; ++j) {
			s += a[i + j];
			m[j + 1] = max(m[j + 1], s);
		}
	}
	for (int i = 0; i <= n; ++i) {
		int ans = 0;
		for (int j = 0; j <= n; ++j) {
			ans = max(ans, m[j] + min(i, j) * k);
		}
		cout << ans << ' ';
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