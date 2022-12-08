#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > 0) ++x;
		if (a[i] < 0) ++y;
		if (a[i] == 0) ++z;
	}
	if (x > 2 || y > 2) {
		cout << "NO\n";
		return;
	}
	vector<int> b;
	for (int i = 0; i < n; ++i) {
		if (a[i]) b.push_back(a[i]);
	}
	if (z) b.push_back(0);
	int m = b.size();
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			for (int k = j + 1; k < m; ++k) {
				bool ok = false;
				for (int l = 0; l < m; ++l) {
					if (b[i] + b[j] + b[k] == b[l]) {
						ok = true;
						break;
					}
				}
				if (!ok) {
					cout << "NO\n";
					return;
				}
			}
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
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}