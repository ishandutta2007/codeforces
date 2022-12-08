#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	if (s.length() <= 2) {
		cout << s[s.length() - 1] << '\n';
		return;
	}
	int mn = 11;
	for (char c: s) {
		mn = min(mn, c - 48);
	}
	cout << mn << '\n';
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