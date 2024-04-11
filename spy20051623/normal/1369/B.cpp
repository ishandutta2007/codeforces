#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int p = -1, q = -1;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == '1' && s[i + 1] == '0') {
			p = i;
			break;
		}
	}
	for (int i = n - 1; i > 0; --i) {
		if (s[i] == '0' && s[i - 1] == '1') {
			q = i;
			break;
		}
	}
	if (p == -1) {
		cout << s << '\n';
		return;
	}
	while (p >= 0 && s[p] == '1') --p;
	while (q < n && s[q] == '0') ++q;
	if (p >= 0)cout << s.substr(0, p + 1);
	cout << 0;
	if (q < n) cout << s.substr(q);
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