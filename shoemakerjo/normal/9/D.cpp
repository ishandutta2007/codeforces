#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 40
//make sure n is big enough
ll dp[maxn][maxn][maxn];
ll create[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, h;
	cin >> n >> h;
	for (int i = 0; i < maxn; i++) {
		fill(create[i], create[i]+maxn, 0LL);
		for (int j = 0; j < maxn; j++) {
			fill(dp[i][j], dp[i][j]+maxn, 0LL);
		}
	}
	create[0][0] = 1LL;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) { //i think we want to go to zero
			create[i][j] = create[i-1][j];
			if (j > 0) create[i][j] += 2LL*create[i-1][j-1];
			if (j > 1) create[i][j] += create[i-1][j-2];
		}
	}
	ll ans = 0LL; //want to add up dp[i][j][n] for all i >= h and any j
	dp[1][1][1] = 1LL; //all else is zero 
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = j; k <= n; k++) { //total used is at least what it is here
				for (int alph = 1; alph <= k; alph++) {
					dp[i][j][k] += dp[i-1][alph][k-j]*create[alph][j];
				}
				// cout << "dp  " << i << " " << j << " " << k << "  " << dp[i][j][k] << endl;
			}
		}
		if (i >= h) {
			for (int j = 1; j <= n; j++) {
				ans += dp[i][j][n]; //any number allowed at this level
			}
		}
	}
	if (h == 1) ans += dp[1][1][n]; //corner case
	cout << ans << endl;
	cin >> n;

}