#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int x = n - 30, y = n - 31;
	if (n > 30 && x != 6 && x != 10 && x != 14) {
		cout << "yes\n";
		cout << "6 10 14 " << x << '\n';
	} else if (n > 31 && y != 6 && y != 10 && y != 15) {
		cout << "yes\n";
		cout << "6 10 15 " << y << '\n';
	} else cout << "no\n";
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