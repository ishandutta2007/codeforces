#include <bits/stdc++.h>

using namespace std;

int a[100];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int cnt = 0, dx = j - i, dy = a[j] - a[i];
			for (int k = 0; k < n; ++k) {
				if (dx * a[k] != dy * (k - i) + dx * a[i]) ++cnt;
			}
			ans = min(ans, cnt);
		}
	}
	if (ans == 1e9) ans = 0;
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