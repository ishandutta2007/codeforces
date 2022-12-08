#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int l = 1e9, r = -1, m = 2e9;
	map<int, int> mp;
	while (n--) {
		int x, y, c;
		cin >> x >> y >> c;
		if (x < l) l = x, m = 2e9, mp[x] = c;
		if (y > r) r = y, m = 2e9, mp[y] = c;
		if (x == l && r == y) m = min(m, c);
		mp[x] = min(mp[x], c);
		mp[y] = min(mp[y], c);
		cout << min(mp[l] + mp[r], m) << '\n';
	}
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