#include <bits/stdc++.h>

using namespace std;

int a[10000];

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s += "WWW";
	int ok = 0, c = 0;
	for (int i = 0; i <= n; ++i) {
		if (s[i] == 'W') {
			if (!ok && c) {
				cout << "NO\n";
				return;
			}
			ok = 0, c = 0;
			continue;
		}
		++c;
		if (s[i] == 'B' && s[i + 1] == 'R' || s[i] == 'R' && s[i + 1] == 'B') ok = 1;
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