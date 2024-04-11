#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, int> mp;
	int c2 = 0, c4 = 0, c6 = 0, c8 = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++mp[x];
		if (mp[x] == 2) ++c2;
		if (mp[x] == 4) ++c4, --c2;
		if (mp[x] == 6) ++c6, --c4;
		if (mp[x] == 8) ++c8, --c6;
	}
	int q;
	cin >> q;
	while (q--) {
		char c;
		int x;
		cin >> c >> x;
		if (c == '+') {
			++mp[x];
			if (mp[x] == 2) ++c2;
			if (mp[x] == 4) ++c4, --c2;
			if (mp[x] == 6) ++c6, --c4;
			if (mp[x] == 8) ++c8, --c6;
		} else {
			--mp[x];
			if (mp[x] == 1) --c2;
			if (mp[x] == 3) --c4, ++c2;
			if (mp[x] == 5) --c6, ++c4;
			if (mp[x] == 7) --c8, ++c6;
		}
		if (c8 || c6 && c2 || c6 && c4 || c6 >= 2 || c4 >= 2 || c4 && c2 + c4 - 1 >= 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

int main() {
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