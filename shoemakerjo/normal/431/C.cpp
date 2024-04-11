#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll mod = 1000000007LL;
	int n, k, d;
	cin >> n >> k >> d;
	ll combos[101][101];
	for (int i = 0; i < 101; i++) {
		combos[i][0] = 1LL;
		combos[i][1] = i;
	}
	for (int i = 0; i < 101; i ++) {
		for (int j = 2; j <= i; j++) {
			combos[i][j] = (combos[i-1][j] + combos[i-1][j-1])%mod;
		}
		for (int j = i+1; j < 101; j++) {
			combos[i][j] = 0LL;
		}
	}
	ll dp[n+1][n+1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <=n ;j++) {
			dp[i][j] = 0LL;
		}
		
	}
	dp[0][0] = 1LL;
	ll ans = 0LL;
	for (int i = 1; i <= k; i++) {
		// if (i == d) continue;
		ll adds[n+1][n+1];
		for (int j = 0; j <= n; j++) {
			for (int m = 0; m <= n; m++) {
				adds[j][m] = 0LL;
			}
		}
		for (int j = 1; j <= n; j++) {
			int si = i*j;
			for (int m = 0; m <= n; m++) {
				for (int q = 0; q <= n; q++) {
					if (m - si >= 0 && q-j >= 0) {
						adds[m][q] = (adds[m][q]+combos[q][j]*dp[m-si][q-j])%mod;
					}
				}
			}
		}
		for (int j = 0; j <= n; j++) {
			for (int m = 0; m <= n; m++) {
				dp[j][m] = (dp[j][m]+adds[j][m])%mod;
				// cout << "cur: " << j << " " << m << " " << dp[j][m] << endl;

			}
			if (i >= d) {
					ans = (ans + adds[n][j])%mod;
			}
		}
		// cout << i << " " << ans << endl;
	}
	
	cout << ans << endl;
	// cin >> ans;
}