#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (n & 1) cout << "Mike\n";
	else {
		int mn = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < a[mn]) mn = i;
		}
		if (mn & 1) cout << "Mike\n";
		else cout << "Joe\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}