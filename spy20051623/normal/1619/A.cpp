#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	if (s.length() % 2) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < s.length() / 2; ++i) {
		if (s[i] != s[i + s.length() / 2]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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