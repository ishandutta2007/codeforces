#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && c % 2 == 0 || b == c && a % 2 == 0 || c == a && b % 2 == 0 || a == b + c || b == c + a || c == a + b)
		cout << "YES\n";
	else cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}