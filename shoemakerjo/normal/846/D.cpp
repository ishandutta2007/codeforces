#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	int broke[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			broke[i][j] = -1;
		}
	}
	int x, y, t;
	for (int i = 0; i < q; i++) {
		cin >> x >> y >> t;
		broke[x-1][y-1] = t;
	}
	int mint[n][m];
	for (int i = 0; i <= n-k; i++) {
		for (int j = 0; j < m; j++) {
			int curmax = -1;
			bool ok = true;
			for (int o = i; o < i+k; o++) {
				if (broke[o][j] == -1) ok = false;
				curmax = max(curmax, broke[o][j]);
			}
			if (!ok) mint[i][j] = -1;
			else {
				mint[i][j] = curmax;
				// cout << i << "  " << j << " " << curmax  <<  " " << mint[i][j] <<endl;
			}
		}
	}
	int b2 = 2000000000;
	int ans = b2;
	for (int i = 0; i <= n-k; i++) {
		for (int j = 0; j <= m-k; j++) {
			int curmax = -1;
			bool ok = true;
			for (int o = j; o < j+k; o++) {
				if (mint[i][o] == -1) ok = false;
				curmax = max(curmax, mint[i][o]);
				// cout << "--> " << curmax << " " << mint[i][j] << endl;
			}
			if (ok) {
				// cout << i << "  -   " << j << endl;
				ans = min(ans, curmax);
			}
		}
	}
	if (ans == b2) {
		cout << -1 << endl;
	}
	else cout << ans << endl;
	// cin >> ans;
}