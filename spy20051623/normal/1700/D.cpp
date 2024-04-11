#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), s(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s[i] = i ? s[i - 1] + a[i] : a[i];
	}
	int mn = 0;
	for (int i = 0; i < n; ++i) {
		mn = max(mn, (s[i] - 1) / (i + 1) + 1);
	}
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t < mn) cout << "-1\n";
		else cout << (s[n - 1] - 1) / t + 1 << '\n';
	}
}

int32_t main() {
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