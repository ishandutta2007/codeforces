#include <bits/stdc++.h>

using namespace std;

void solve() {
	const int mod = 998244353;
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	long long ans = 1;
	for (int i = 1; i <= k; ++i) {
		ans = ans * i % mod;
	}
	for (int i = k + 1; i <= n; ++i) {
		if (a[i - k] == -1) ans = ans * i % mod;
		else if (a[i - k] == 0) ans = ans * (k + 1) % mod;
	}
	for (int i = n - k + 1; i <= n; ++i) {
		if (a[i] > 0) ans = 0;
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