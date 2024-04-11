#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	if (!x && !y) cout << "0\n";
	else if (int(sqrt(x * x + y * y)) == sqrt(x * x + y * y)) cout << "1\n";
	else cout << "2\n";
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