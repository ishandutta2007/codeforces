#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long c = a[n - 1], ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] < a[i + 1]) ans += a[i + 1] - a[i], c -= a[i + 1] - a[i];
		else ans += a[i] - a[i + 1];
	}
	ans += abs(c);
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