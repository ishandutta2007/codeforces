#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[32][2][2];

ll f(ll X, ll Y) {
	dp[31][1][1] = 1;
	for(int b = 30; b >= 0; b--) {
		int x = (X & (1 << b)) >> b, y = (Y & (1 << b)) >> b;
		//cout << x << " " << y << endl;
		dp[b][1][1] = dp[b + 1][1][1];
		if(x && y) {
			dp[b][0][0] = 3*dp[b+1][0][0] + 2*dp[b+1][1][0] + 2*dp[b+1][0][1] + dp[b+1][1][1];
			dp[b][0][1] = dp[b+1][0][1] + dp[b+1][1][1];
			dp[b][1][0] = dp[b+1][1][0] + dp[b+1][1][1];
			dp[b][1][1] = 0;
			continue;
		}
		if(x) {
			dp[b][0][0] = 3*dp[b+1][0][0] + 2*dp[b+1][1][0];
			dp[b][0][1] = 2*dp[b+1][0][1] + dp[b+1][1][1];
			dp[b][1][0] = dp[b+1][1][0];
			continue;
		}
		if(y) {
			dp[b][0][0] = 3*dp[b+1][0][0] + 2*dp[b+1][0][1];
			dp[b][0][1] = dp[b+1][0][1];
			dp[b][1][0] = 2*dp[b+1][1][0] + dp[b+1][1][1];
			continue;
		}
		dp[b][0][0] = 3*dp[b+1][0][0];
		dp[b][0][1] = 2*dp[b+1][0][1];
		dp[b][1][0] = 2*dp[b+1][1][0];
	}
	return dp[0][0][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t, l, r;
	cin >> t;
	while(t--) {
		cin >> l >> r;
		r++;
		cout << f(l, l) + f(r, r) - 2*f(l, r) << endl;
	}
}