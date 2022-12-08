#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	bool grid[n][m];
	string line;
	for (int i = 0; i < n ; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			if (line[j] == '1') grid[i][j] = true;
			else grid[i][j] = false;
		}
		
	}
	int prev[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			prev[i][j] = j+1;
			for (int k = j; k >= 0; k--) {
				if (!grid[i][k]) {
					prev[i][j] = k;
				}
				else break;
			}
			// cout << "prev:   " << prev[i][j] << endl;
		}
	}
	ll dp[n][m][n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = i; k < n; k++) {
				for (int l = j; l < m; l++) {
					dp[i][j][k][l] = 0;
					if (k > i) {
						dp[i][j][k][l] += dp[i][j][k-1][l];
					}
					if (l > j) {
						dp[i][j][k][l] += dp[i][j][k][l-1];
					}
					if (k > i && l > j) {
						dp[i][j][k][l] -= dp[i][j][k-1][l-1];
					}
					int left = j;
					for (int r = k; r>= i; r--) {
						left = max(left, prev[r][l]);
						dp[i][j][k][l] += l-left+1;
						// cout << "  " << i << " " << 
						// j << " " << k << " " << l << " " << 
						//  l-left+1 << endl;
					}
				}
				
			}
		}
	}
	int a, b, c, d;

	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c >> d;
		// cout << "ans: ";
		cout << dp[a-1][b-1][c-1][d-1] << endl;
	}
	cin >> a;

}