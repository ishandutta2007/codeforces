#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	ll mod = 100000000;
	ll dp[n1+n2+1][n1+1][k1+1];
	ll dp2[n1+n2+1][n1+1][k2+1];
	for (int i = 0; i <= n1+n2; i++) {
		for (int j = 0; j <= n1; j++) {
			for (int k = 0; k <= k1; k++) dp[i][j][k] = 0;
		}
	}
	for (int i = 0; i <= n1+n2; i++) {
		for (int j = 0; j <= n1; j++) {
			for (int k = 0; k <= k2; k++) dp2[i][j][k] = 0;
		}
	}
	dp[0][0][0] = 1;
	dp2[0][0][0] = 1;

	for (int i = 1; i <= n1+n2; i++) {
		for (int j = 0; j <= n1; j++) {
			dp[i][j][0] = 0;
			if (j > 0) dp[i][j][1] = dp[i-1][j-1][0];
			
			dp2[i][j][0] = 0;
			dp2[i][j][1] = dp[i-1][j][0];
			for (int k = 1; k <= k1; k++) {
				if (k > 1 && j > 0) dp[i][j][k] = dp[i-1][j-1][k-1];
				// cout << "f:  " << dp[i][j][k] << endl;
				dp2[i][j][1] = (dp2[i][j][1] + dp[i-1][j][k])%mod; 
			}
			for (int k = 1; k <= k2; k++) {
				if (k > 1) dp2[i][j][k] = dp2[i-1][j][k-1];
				if ( j > 0) dp[i][j][1] = (dp[i][j][1] + dp2[i-1][j-1][k])%mod; 
				// cout << "h:  " << dp[i][j][1] << endl;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= k1; i++) {
		ans = (ans + dp[n1+n2][n1][i]) % mod;
		// cout << "i:  " << i << "  " << dp[n1+n2][n1][i] << endl;
	}
	for (int i = 1; i <= k2; i++) {
		ans = (ans + dp2[n1+n2][n1][i]) % mod;
		// cout << "i2:   " << i << "  " << dp2[n1+n2][n1][i] << endl;
	}
	cout << ans << endl;
	cin >> ans;
}