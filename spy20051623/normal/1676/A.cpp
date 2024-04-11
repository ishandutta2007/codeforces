#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) cout << "YES\n";
	else cout << "NO\n";
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