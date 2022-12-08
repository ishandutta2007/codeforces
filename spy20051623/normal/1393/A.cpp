#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n & 1) {
		cout << (n + 1) / 2 << '\n';
	} else {
		cout << n / 2 + 1 << '\n';
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