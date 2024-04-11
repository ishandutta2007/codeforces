#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		++mp[k - p % k];
	}
	long long ans = 0;
	for (auto i: mp) if (i.first != k) ans = max(ans, 1ll * (i.second - 1) * k + i.first + 1);
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