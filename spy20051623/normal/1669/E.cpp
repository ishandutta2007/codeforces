#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	map<string, int> mp;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		++mp[s];
	}
	long long ans = 0;
	for (const auto &i: mp) {
		for (const auto &j: mp) {
			if (i.first[0] == j.first[0] && i.first[1] != j.first[1] ||
				i.first[0] != j.first[0] && i.first[1] == j.first[1])
				ans += 1ll * i.second * j.second;
		}
	}
	cout << ans / 2 << '\n';
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