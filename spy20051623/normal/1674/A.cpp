#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	if (y % x == 0) cout << "1 " << y / x << '\n';
	else cout << "0 0\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}