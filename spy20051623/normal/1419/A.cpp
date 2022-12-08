#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 0, y = 0;
	for (int i = n & 1 ^ 1; i < n; i += 2) {
		if ((s[i] - '0') & 1) ++x;
		else ++y;
	}
	if (!x) {
		cout << 2 << '\n';
		return;
	}
	if (!y) {
		cout << 1 << '\n';
		return;
	}
	cout << (n & 1 ^ 1) + 1 << '\n';
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