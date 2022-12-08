#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x;
	cin >> x;
	cout << "Division ";
	if (x < 1400) cout << 4;
	else if (x < 1600) cout << 3;
	else if (x < 1900) cout << 2;
	else cout << 1;
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