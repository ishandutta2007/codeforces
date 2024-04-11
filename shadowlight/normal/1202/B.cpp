#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	int dp[10][10][10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					dp[i][j][k][l] = 1e9;
				}
			}
		}
	}
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			for (int i = 0; i < 10; i++) {
				dp[i][(i + x) % 10][x][y] = 1;
				dp[i][(i + y) % 10][x][y] = 1;
			}
			for (int k = 0; k < 10; k++) {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						dp[i][j][x][y] = min(dp[i][j][x][y], dp[i][k][x][y] + dp[k][j][x][y]);
					}
				}
			}
		}
	}
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			int cnt = 0;
			for (int i = 0; i < n - 1; i++) {
				int a = s[i] - '0', b = s[i + 1] - '0';
				cnt += dp[a][b][x][y] - 1;
				if (cnt >= 1e8) break;
			}	
			cout << (cnt >= 1e8 ? -1 : cnt) << " ";
		}
		cout << "\n";
	}
}