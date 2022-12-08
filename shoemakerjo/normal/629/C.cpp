#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
int dp[2005][2005];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int endpower = 0;
	int minpower = 0;
	int cp = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] == '(') cp++;
		else cp--;
		minpower = min(minpower, cp);
	}
	endpower = cp;
	//length of i with end point of j, never below 0
	for (int i = 0; i <= 2004; i++) {
		for (int j = 0; j <= 2004; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			if (j > 0) {
				dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
			}
			dp[i][j] = (dp[i][j]+dp[i-1][j+1])%mod;
		}
	}
	int ans = 0;
	for (int i = 0; i <= n-m; i++) {
		int j = n-m-i; //other lenght
		// int addon = 0;
		for (int k = 0-minpower; k <= 2000; k++) {
			int ot = k+endpower;
			if (ot > 2000) continue;
			// if (ot < 5) cout << "here   " << i << "  " << k << "  " << j << "  " << ot << ":  " << 
				// dp[i][k] << " " << dp[j][ot] << endl;
			int addon  = (dp[i][k]*1LL*dp[j][ot])%mod;
			ans = (ans+addon)%mod;
		}
	}
	cout << ans << endl;
	cin >> ans;

}