#include <bits/stdc++.h>
using namespace std;
const int N = 2022;
int n, k;
string s[N];
int dp[N][N];
string str[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int go[N][12];
int main() {
	memset(go, -1, sizeof(go));
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 10; j ++) {
			bool flag = 0; int cnt = 0;
			for (int k = 0; k < 8; k ++) {
				if (s[i][k] == '0' && str[j][k] == '1') cnt ++;
				if (s[i][k] == '1' && str[j][k] == '0') flag = 1;
			}
			if (flag == 0) {
				go[i][cnt] = max(go[i][cnt], j);
			}
		}
	}
	dp[n+1][0] = 1;
	for (int i = n + 1; i >= 2; i --) {
		for (int j = 0; j <= k; j ++) {
			if (dp[i][j]) {
				for (int x = 0; x <= 9; x ++) {
					if (go[i-1][x] != -1 && j + x <= k) {
						dp[i-1][j + x] = 1;
					}
				}
			}
		}
	}
	if (dp[1][k] == 0) return !printf("-1\n");
	for (int i = 1; i <= n; i ++) {
		int mx = -1;
		for (int x = min(9, k); x >= 0; x --) {
			if (dp[i+1][k-x])
				mx = max(mx, go[i][x]);
		}
		for (int x = min(9, k); x >= 0; x --) {
			if (go[i][x] == mx && dp[i+1][k-x]) {
				printf("%d", go[i][x]);
				k -= x; 
				break;
			}
		}
	}
	printf("\n");
}