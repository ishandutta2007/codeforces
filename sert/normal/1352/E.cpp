#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<bool> u(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int sum = a[i];
		for (int j = i + 1; j < n && sum <= n; j++) {
			sum += a[j];
			if (sum <= n) u[sum] = true;
		}
	}
	int ans = 0;
	for (int x : a) ans += (int)u[x];
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}