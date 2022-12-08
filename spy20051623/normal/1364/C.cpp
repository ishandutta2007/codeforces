#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(b, -1, sizeof b);
	int p = 0;
	if (a[0] == 1) b[0] = 0, p = 1;
	else if (a[0] > 1) {
		cout << "-1\n";
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] > i + 1 || a[i] < a[i - 1]) {
			cout << "-1\n";
			return;
		}
		if (a[i] == a[i - 1]) continue;
		b[i] = a[i - 1];
		for (int j = a[i - 1] + 1; j < a[i]; ++j) {
			while (b[p] != -1) ++p;
			b[p] = j;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (b[i] == -1) b[i] = 1000000;
	}
	for (int i = 0; i < n; ++i) {
		cout << b[i] << ' ';
	}
	cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}