#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	int x;
	cin >> s >> x;
	vector<int> v(s.length(), 1);
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '0') {
			if (i >= x) v[i - x] = 0;
			if (i < s.length() - x) v[i + x] = 0;
		}
	}
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '1') {
			if (i < x && i >= s.length() - x) {
				cout << "-1\n";
				return;
			}
			if (i < x) {
				if (v[i + x] == 0) {
					cout << "-1\n";
					return;
				}
			} else if (i >= s.length() - x) {
				if (v[i - x] == 0) {
					cout << "-1\n";
					return;
				}
			} else {
				if (v[i - x] == 0 && v[i + x] == 0) {
					cout << "-1\n";
					return;
				}
			}
		}
	}
	for (int i: v) cout << i;
	cout << '\n';
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