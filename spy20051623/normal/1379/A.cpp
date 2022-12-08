#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s, ss = "abacaba", sss = "caba", ssss = "abac", sssss = "bacaba", ssssss = "abacab";
	cin >> s;
	int cnt = 0;
	for (int i = 0; i + 7 <= n; ++i) {
		if (s.substr(i, 7) == ss) {
			++cnt;
		}
	}
	if (cnt > 1) {
		cout << "no\n";
		return;
	}
	if (cnt == 1) {
		cout << "yes\n";
		for (int i = 0; i < n; ++i) {
			if (s[i] == '?') s[i] = 'z';
		}
		cout << s << '\n';
		return;
	}
	bool ok = false;
	for (int i = 0; i + 7 <= n; ++i) {
		bool f = true;
		for (int j = 0; j < 7; ++j) {
			if (s[i + j] != ss[j] && s[i + j] != '?') {
				f = false;
				break;
			}
		}
		if (i + 11 <= n && s.substr(i + 7, 4) == sss) f = false;
		if (i >= 4 && s.substr(i - 4, 4) == ssss) f = false;
		if (i + 13 <= n && s.substr(i + 7, 6) == sssss) f = false;
		if (i >= 6 && s.substr(i - 6, 6) == ssssss) f = false;
		if (f) {
			for (int j = 0; j < 7; ++j) {
				s[i + j] = ss[j];
			}
			for (int j = 0; j < n; ++j) {
				if (s[j] == '?') s[j] = 'z';
			}
			ok = true;
			break;
		}
	}
	if (ok) cout << "yes\n" << s << '\n';
	else cout << "no\n";
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