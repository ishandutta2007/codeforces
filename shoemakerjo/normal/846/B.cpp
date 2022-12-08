#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define INF 3000000000LL
int main() {
	int n, k;
	ll M;
	cin >> n >> k >> M;
	vector<ll> subs;
	ll cur;
	for (int i = 0; i < k; i++) {
		cin >> cur;
		subs.push_back(cur);
	}
	sort(subs.begin(), subs.end());
	ll dp[n+1][50*50];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 50*50; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 50*50; j++) {
			ll csum = 0LL;
			for (int m = 0; m < k; m++) {
				if (j-m >= 0) {
					dp[i][j] = min(dp[i][j], dp[i-1][j-m] + 
						csum);
				}
				csum += subs[m];
			}
			if (j-k-1 >= 0) {
				dp[i][j] = min(dp[i][j], 
					dp[i-1][j-k-1] + csum);
			}
			if (dp[i][j] <= M) ans = max(ans, j);
		}
	}
	cout << ans << endl;
	cin >> ans;
}