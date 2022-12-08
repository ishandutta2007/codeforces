#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000000007LL;

ll pow(ll base, ll exp) {
	if (exp == 0) return 1LL;
	if (exp == 1) return base;
	if (exp%2LL == 0LL) {
		ll temp = pow(base, exp/2);
		temp = (temp*temp)%mod;
		return temp;
	}
	else {
		ll temp = pow(base, exp-1);
		temp = (temp*base)%mod;
		return temp;
	}
}

ll inv(ll base) {
	return pow(base, mod-2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, pa, pb;
	cin >> k >> pa >> pb;
	ll dp[k+1][k+1][2];
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j][0] = 0LL;
			dp[i][j][1] =  1LL;
		}
	}
	dp[1][0][0] = dp[1][0][1] = 1LL;
	ll invab = inv(pa+pb);
	ll invb = inv(pb);
	ll proba = (pa*(invab))%mod;
	ll probb = (pb*(invab))%mod;
	ll ansTop = 0LL;
	ll ansBot = 1LL;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[i][j][0] == 0LL) continue;
			// cout << "i   " << i << "   " << j << "  " << dp[i][j][0] << " " << dp[i][j][1] << endl;
			if (i + j >= k) {
				// cout << "here   " << i << "   " << j << endl;
				ll atop = (j*pb + pa + pb - pb + i*pb)%mod;
				ll abot = pb;
				atop = (atop*dp[i][j][0])%mod;
				abot = (abot*dp[i][j][1])%mod;
				// cout << "atop   " << atop << "   " << abot << endl;
				// cout << "frac   " << dp[i][j][0] << "  " << dp[i][j][1] << endl;
				ll ttemp = ansTop;
				ll btemp = ansBot;
				ansTop = ((atop*btemp) + (ttemp*abot))%mod;
				ansBot = (btemp*abot)%mod;
			}
			else {
				ll ttemp = dp[i+1][j][0];
				ll btemp = dp[i+1][j][1];
				ll atop = (dp[i][j][0]*pa)%mod;
				ll abot = (dp[i][j][1]*(pa+pb))%mod;
				dp[i+1][j][0] = ((atop*btemp) + (ttemp*abot))%mod;
				dp[i+1][j][1] = (btemp*abot)%mod;

				ttemp = dp[i][i+j][0];
				btemp = dp[i][i+j][1];
				atop = (dp[i][j][0]*pb)%mod;
				dp[i][i+j][0] = ((atop*btemp) + (ttemp*abot))%mod;
				dp[i][i+j][1] = (btemp*abot)%mod;
			}

		}
	}
	// cout << ansTop << endl;
	// cout << ansBot << endl;
	ll ans = (ansTop*(inv(ansBot)))%mod;
	cout << ans << endl;
	cin >> ans;
}