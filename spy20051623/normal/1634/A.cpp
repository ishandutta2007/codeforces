#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (k == 0) {
		cout << 1 << '\n';
		return;
	}
	for (int i = 0, j = n - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) {
			cout << 2 << '\n';
			return;
		}
	}
	cout << 1 << '\n';
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