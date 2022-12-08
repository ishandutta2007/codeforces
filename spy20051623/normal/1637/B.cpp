#include <bits/stdc++.h>

using namespace std;

int a[1000];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += i * (n - i + 1) * (a[i] == 0 ? 2 : 1);
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