#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n & 1) {
		cout << "-1\n";
		return;
	}
	cout << n / 2 << " 0 0\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}