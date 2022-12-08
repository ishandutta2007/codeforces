#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, i, j, k;
	char ch;
	cin >> n;
	vector<vector<int>> mp(n);
	for (i = 0; i < n; ++i) {
		getchar();
		for (j = 0; j < n; ++j) {
			cin >> ch;
			k = ch - '0';
			mp[i].push_back(k);
		}
	}
	for (i = 0; i < n; ++i) {
		getchar();
		for (j = 0; j < n; ++j) {
			cin >> ch;
			k = ch - '0';
			mp[i][j] ^= k;
		}
	}
	for (i = 0; i < n; ++i) {
		if (mp[0][i]) {
			for (j = 0; j < n; ++j) {
				mp[j][i] ^= 1;
			}
		}
	}
	for (i = 1; i < n; ++i) {
		for (j = 1; j < n; ++j) {
			if (mp[i][j] != mp[i][0]) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}