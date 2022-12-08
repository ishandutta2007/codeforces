#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int x = (n - 1) / 4 + 1;
	for (int i = 0; i < n - x; ++i) {
		cout << 9;
	}
	for (int i = 0; i < x; ++i) {
		cout << 8;
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