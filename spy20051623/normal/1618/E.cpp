#include <bits/stdc++.h>

using namespace std;

long long a[100000], b[100000];

void solve() {
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % (n * (n + 1) / 2)) {
		cout << "NO\n";
		return;
	}
	sum /= n * (n + 1) / 2;
	for (int i = 0; i < n; ++i) {
		long long d = sum - (a[i] - a[(i + n - 1) % n]);
		if (d % n || d <= 0) {
			cout << "NO\n";
			return;
		}
		b[i] = d / n;
	}
	cout << "YES\n";
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
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}