#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int x = min(a, b), y = min(a, c), z = min(b, c);
	if (a == max(x, y) && b == max(x, z) && c == max(y, z)) cout << "YES\n" << x << ' ' << y << ' ' << z << '\n';
	else cout << "NO\n";
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