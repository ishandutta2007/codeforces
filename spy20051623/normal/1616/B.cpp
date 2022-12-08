#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s.length() == 1) {
		cout << s << s << '\n';
		return;
	}
	if (s[0] == s[1]) {
		cout << s[0] << s[0] << '\n';
		return;
	}
	int p = n - 1;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] < s[i + 1]) {
			p = i;
			break;
		}
	}
	string ss = s.substr(0, p + 1);
	cout << ss;
	reverse(ss.begin(), ss.end());
	cout << ss << '\n';
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