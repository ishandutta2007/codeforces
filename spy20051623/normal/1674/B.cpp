#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	cout << (s[0] - 'a') * 25 + (s[1] - 'a') + 1 - (s[1] > s[0]) << '\n';
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