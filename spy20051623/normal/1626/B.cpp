#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	for (int i = s.length() - 2; i >= 0; --i) {
		if (s[i] - '0' + s[i + 1] - '0' >= 10) {
			s.replace(i, 2, to_string(s[i] - '0' + s[i + 1] - '0'));
			cout << s << '\n';
			return;
		}
	}
	s.replace(0, 2, to_string(s[0] - '0' + s[1] - '0'));
	cout << s << '\n';
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