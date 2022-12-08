#include <bits/stdc++.h>

using namespace std;

int a[100];

void solve() {
	string s;
	cin >> s;
	memset(a, 0, sizeof a);
	for (char c: s) ++a[c - 'a'];
	for (int i = 0; i < s.length(); ++i) {
		if (a[s[i] - 'a'] > 1) --a[s[i] - 'a'];
		else {
			cout << s.substr(i) << '\n';
			return;
		}
	}
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