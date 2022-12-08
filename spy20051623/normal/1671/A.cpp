#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		if (i == 0 || s[i] != s[i - 1]) {
			int cnt = 0;
			for (int j = i; j < n && s[j] == s[i]; ++j) {
				++cnt;
			}
			if (cnt == 1) {
				cout << "NO\n";
				return;
			}
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