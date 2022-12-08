#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n > 19) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	int x = 1;
	for (int i = 0; i < n; ++i) {
		cout << x << ' ';
		x *= 3;
	}
	cout << '\n';
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