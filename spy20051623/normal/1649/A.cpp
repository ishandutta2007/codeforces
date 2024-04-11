#include <bits/stdc++.h>

using namespace std;

int a[100000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int x = -1, y = -1;
	for (int i = 0; i < n; ++i) {
		if (!a[i]) {
			x = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (!a[i]) {
			y = i;
			break;
		}
	}
	if (x == -1) cout << "0\n";
	else cout << y - x + 2 << '\n';
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