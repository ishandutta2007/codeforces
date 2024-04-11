#include <bits/stdc++.h>

using namespace std;

int dp[2][205000];
int dp2[2][205000];


const int mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cur = 0;
	int prev = 1;
	int a, b, k, t;
	cin >> a >> b >> k >> t;
	fill(dp[cur], dp[cur]+205000, 0);
	fill(dp2[cur], dp2[cur]+205000, 0);
	dp[cur][a+102000] = 1;
	dp2[cur][b+102000] = 1;
	for (int i = 1; i <= t; i++) {
		if (i & 1) {
			cur = 1;
		}
		else cur = 0;
		prev = 1-cur;
		int cw1 = 0;
		int cw2 = 0;
		for (int j = 0; j < k; j++) {
			cw1 = (cw1+dp[prev][j])%mod;
			cw2 = (cw2+dp2[prev][j])%mod;
		}
		// cout << "c   " << cw1 << "  " << cw2 << endl;
		for (int j = 0; j < 205000; j++) {
			if (j+k < 205000) {
				cw1 = (cw1+dp[prev][j+k])%mod;
				cw2 = (cw2+dp2[prev][j+k])%mod;
			}
			if (j - k-1 >= 0) {
				cw1 = (cw1+mod-dp[prev][j-k-1])%mod;
				cw2 = (cw2+mod-dp2[prev][j-k-1])%mod;
			}
			dp[cur][j] = cw1;
			dp2[cur][j] =  cw2;
		}
	}
	int ans = 0;
	int top = dp[cur][0];
	int tempo = 0;
	for (int i = 1; i < 205000; i++) {
		// cout << top << " " << top << endl;
		
		top = (dp[cur][i])%mod;
		// if (top > 0) {
			// cout << top << "  " << tempo << endl;
		// }
		tempo = (tempo+dp2[cur][i-1])%mod;
		int addon = (top*1LL*tempo)%mod;
		ans = (ans+addon)%mod;
	}
	cout << ans << endl;
	cin >> ans;

}