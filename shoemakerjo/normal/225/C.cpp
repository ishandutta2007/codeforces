#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	bool white[n][m];
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			if (line[j]=='.') white[i][j] = true;
			else white[i][j] = false;
		}
	}
	int bil = 100000000;
	int wdp[m+1][m+1];
	int bdp[m+1][m+1];
	wdp[0][0] = 0;
	bdp[0][0] = 0;
	for (int i = 1; i<= m; i++) {
		wdp[0][i] = bdp[0][i] = -1;
	}
	for (int i = 0; i < m; i++) {
		int wcount = 0;
		for (int j = 0; j < n; j++) {
			if (white[j][i]) wcount++;
		}
		int bcount = n-wcount;
		// cout << bcount << "   -   " << wcount << endl;
		wdp[i+1][0] = bdp[i+1][0] = -1;
		wdp[i+1][1] = bil;
		bdp[i+1][1] = bil;
		for (int j = 1; j <= m; j++) {
			if (wdp[i][j-1] != -1 && wdp[i][j-1] != bil) {
				wdp[i+1][j] = wdp[i][j-1] + wcount;
			}
			else wdp[i+1][j] = -1;

			if (bdp[i][j-1] != -1 && bdp[i][j-1] != bil) {
				bdp[i+1][j] = bdp[i][j-1] + bcount;
			}
			else bdp[i+1][j] = -1;
		}
		if (wdp[i+1][1] == -1) wdp[i+1][1] = bil;
		if (bdp[i+1][1] == -1) bdp[i+1][1] = bil;
		for (int j = x; j <= y && j <= m; j++) {
			if (wdp[i][j] != -1 && wdp[i][j] != bil) {
				bdp[i+1][1] = min(bdp[i+1][1], wdp[i][j] + bcount);
			}
			if (bdp[i][j] != -1 && bdp[i][j] != bil) {
				wdp[i+1][1] = min(wdp[i+1][1], bdp[i][j] + wcount);
			}
		}
	}
	int ans = bil;
	for (int i = x; i <= y && i <= m; i++) {
		if (wdp[m][i] != -1) ans = min(ans, wdp[m][i]);
		if (bdp[m][i] != -1) ans = min(ans, bdp[m][i]);
	}
	// for (int i = 0; i <= m; i++) {
	// 	for (int j = 0; j <= m; j++) {
	// 		cout << i << " " << j << " " << wdp[i][j] << endl;
	// 	}
	// }
	cout << ans << endl;
	cin >> ans;
}