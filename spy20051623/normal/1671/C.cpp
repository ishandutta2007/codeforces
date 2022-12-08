#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<long long> a(n), s(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		s[i] = (i ? s[i - 1] : 0) + a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] > x) break;
		ans += (x - s[i]) / (i + 1) + 1;
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