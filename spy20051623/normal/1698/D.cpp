#include <bits/stdc++.h>

using namespace std;

int qry(int l, int r) {
	cout << "? " << l << " " << r << endl;
	int c = 0;
	for (int i = 0; i < r - l + 1; ++i) {
		int p;
		cin >> p;
		if (p >= l && p <= r) ++c;
	}
	return c & 1;
}

void solve() {
	int n;
	cin >> n;
	int l = 1, r = n;
	while (l < r) {
		int m = (l + r) >> 1;
		if (qry(l, m)) r = m;
		else l = m + 1;
	}
	cout << "! " << l << endl;
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