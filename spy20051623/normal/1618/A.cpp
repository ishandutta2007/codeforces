#include <bits/stdc++.h>

using namespace std;

int a[100];

void solve() {
	for (int i = 0; i < 7; ++i) {
		cin >> a[i];
	}
	cout << a[0] << ' ' << a[1] << ' ' << a[6] - a[0] - a[1] << '\n';
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