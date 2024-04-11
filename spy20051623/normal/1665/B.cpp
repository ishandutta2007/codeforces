#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		++mp[p];
	}
	int mx = 0;
	for (auto i: mp) {
		mx = max(mx, i.second);
	}
	if (mx == n) {
		cout << "0\n";
		return;
	}
	int ans = 0;
	while (true) {
		++ans;
		if (mx + mx >= n) {
			ans += n - mx;
			break;
		}
		ans += mx;
		mx <<= 1;
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