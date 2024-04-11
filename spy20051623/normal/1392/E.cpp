#include <bits/stdc++.h>

using namespace std;

long long mp[30][30];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < 30; ++i) {
		if (!(i & 1)) {
			for (int j = 0; j < 30; ++j) {
				mp[i][j] = 1ll << (i + j - 1);
			}
		}
	}
	mp[0][0] = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << mp[i][j] << ' ';
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while (q--) {
		long long s;
		cin >> s;
		int x = 0, y = 0;
		cout << x + 1 << ' ' << y + 1 << endl;
		while (x != n - 1 || y != n - 1) {
			if (x & 1) {
				if (s & mp[x + 1][y]) ++x;
				else ++y;
			} else {
				if (s & mp[x][y + 1]) ++y;
				else ++x;
			}
			cout << x + 1 << ' ' << y + 1 << endl;
		}
	}
	return 0;
}