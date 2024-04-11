#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (a[n - 1] > a[n]) {
		cout << "-1\n";
		return;
	}
	if (a[n] >= 0) {
		cout << n - 2 << '\n';
		for (int i = 1; i <= n - 2; ++i) {
			cout << i << ' ' << n - 1 << ' ' << n << '\n';
		}
	} else {
		for (int i = 1; i < n; ++i) {
			if (a[i] > a[i + 1]) {
				cout << "-1\n";
				return;
			}
		}
		cout << "0\n";
	}
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