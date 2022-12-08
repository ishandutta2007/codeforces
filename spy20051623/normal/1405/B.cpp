#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long sum = 0, ans = 0;
	for (int &i: a) {
		if (i == 0) continue;
		if (i > 0) sum += i, i = 0;
		else if (sum + i > 0) sum += i, i = 0;
		else i += sum, sum = 0;
	}
	for (int i: a) if (i < 0) ans -= i;
	cout << ans << '\n';
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