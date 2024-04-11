#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i] && a[i] % b[0]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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