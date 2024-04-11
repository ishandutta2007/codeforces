#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<int, int> m;
	++m[0];
	int x = 0;
	for (char c: s) {
		x += c - '1';
		++m[x];
	}
	long long ans = 0;
	for (auto i: m) {
		ans += 1ll * i.second * (i.second - 1) / 2;
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