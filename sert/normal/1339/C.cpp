#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int mx = a[0];
	int dif = 0;
	for (int i = 1; i < n; i++) {
		dif = max(dif, mx - a[i]);
		mx = max(mx, a[i]);
	}

	int ans = 0;
	ll pw = 1;
	while (dif > 0) {
		dif -= pw;
		pw *= 2;
		ans++;
	}
	cout << ans << "\n";
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