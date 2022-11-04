#include <bits/stdc++.h>

using namespace std;
#define MN 505

char pan[MN][MN];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> pan[i];
		if (n == 1) {
			for (int i = 0; i < m; i++) cout << 'X'; cout << endl;
			continue;
		}
		for (int i = 1; i < n; i += 3) {
			for (int j = 0; j < m; j++) pan[i][j] = 'X';
			if (i == 1) continue;
			bool flg = 0;
			for (int j = 0; j < m; j++) {
				if (pan[i - 1][j] == 'X') {
					pan[i - 2][j] = 'X';
					flg = 1;
					break;
				}
				if (pan[i - 2][j] == 'X') {
					pan[i - 1][j] = 'X';
					flg = 1;
					break;
				}
			}
			if (flg) continue;
			pan[i - 1][0] = pan[i - 2][0] = 'X';
		}
		if (n % 3 == 1) {
			for (int j = 0; j < m; j++) if (pan[n - 1][j] == 'X') {
				pan[n - 2][j] = 'X';
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << pan[i][j];
			cout << endl;
		}
	}

	return 0;

}