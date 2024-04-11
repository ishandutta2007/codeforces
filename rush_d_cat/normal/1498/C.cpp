#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
const LL MOD = 1e9 + 7;
LL dp[N][N][2];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t --){    	
		int n, k;
		cin >> n >> k;
		for (int i = 0; i <= n+1; i ++) for (int j = 0; j <= k+1; j ++) dp[i][j][0] = dp[i][j][1] = 0;
		for (int i = 1; i <= k; i ++) dp[i][0][0] = dp[i][n+1][1] = 1;

		for (int i = 1; i <= k; i ++) {
			for (int pos = n; pos >= 1; pos --) {
				dp[i][pos][1] = (dp[i][pos+1][1] + dp[i-1][pos-1][0]) % MOD; 
			}
			for (int pos = 1; pos <= n; pos ++) {
				dp[i][pos][0] = (dp[i][pos-1][0] + dp[i-1][pos+1][1]) % MOD;
			}
		}
		cout << dp[k][1][1] << endl;
	}
}