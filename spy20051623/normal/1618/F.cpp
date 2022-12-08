#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long x, y;
	cin >> x >> y;
	if (x == y) {
		cout << "YES\n";
		return;
	}
	if (y % 2 == 0) {
		cout << "NO\n";
		return;
	}
	string s, t;
	bool ok = false;
	for (int i = 62; i >= 0; --i) {
		if (y >> i & 1) ok = true;
		if (ok) t += '0' + (y >> i & 1);
	}
	cerr << t << '\n';
	ok = false;
	for (int i = 62; i >= 0; --i) {
		if (x >> i & 1) ok = true;
		if (ok) s += '0' + (x >> i & 1);
	}
	s += '1';
	cerr << s << '\n';
	for (int i = 0; i <= (int) t.length() - (int) s.length(); ++i) {
		if (t[i] == '0') break;
		if (t.substr(i, s.length()) == s) {
			bool f = true;
			for (int j = i + s.length(); j < t.length(); ++j) {
				if (t[j] == '0') {
					f = false;
					break;
				}
			}
			if (f) {
				cout << "YES\n";
				return;
			}
		}
	}
	reverse(s.begin(), s.end());
	cerr << s << '\n';
	for (int i = 0; i <= (int) t.length() - (int) s.length(); ++i) {
		if (t[i] == '0') break;
		if (t.substr(i, s.length()) == s) {
			bool f = true;
			for (int j = i + s.length(); j < t.length(); ++j) {
				if (t[j] == '0') {
					f = false;
					break;
				}
			}
			if (f) {
				cout << "YES\n";
				return;
			}
		}
	}
	while (x % 2 == 0) x /= 2;
	s.clear();
	ok = false;
	for (int i = 62; i >= 0; --i) {
		if (x >> i & 1) ok = true;
		if (ok) s += '0' + (x >> i & 1);
	}
	cerr << s << '\n';
	for (int i = 0; i <= (int) t.length() - (int) s.length(); ++i) {
		if (t[i] == '0') break;
		if (t.substr(i, s.length()) == s) {
			bool f = true;
			for (int j = i + s.length(); j < t.length(); ++j) {
				if (t[j] == '0') {
					f = false;
					break;
				}
			}
			if (f) {
				cout << "YES\n";
				return;
			}
		}
	}
	reverse(s.begin(), s.end());
	cerr << s << '\n';
	for (int i = 0; i <= (int) t.length() - (int) s.length(); ++i) {
		if (t[i] == '0') break;
		if (t.substr(i, s.length()) == s) {
			bool f = true;
			for (int j = i + s.length(); j < t.length(); ++j) {
				if (t[j] == '0') {
					f = false;
					break;
				}
			}
			if (f) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
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