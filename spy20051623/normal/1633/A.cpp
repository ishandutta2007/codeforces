#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int x = n / 7 * 7;
	if (x / 10 % 10 != n / 10 % 10) x += 7;
	cout << x << '\n';
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