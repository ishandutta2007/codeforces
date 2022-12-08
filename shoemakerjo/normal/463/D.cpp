#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int dp[n+1];
	fill(dp, dp+n+1, 0); //start with all zeroes
	int seq[k][n+1];
	int ind[k][n+1]; //maps value to its index
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> seq[i][j];
			ind[i][seq[i][j]] = j;
		}
	}
	for (int i = 0; i < n; i++) {
		int vcur = seq[0][i];
		dp[vcur] = 1; //only process in this order
		for (int j = 0; j < i; j++) {
			int vprev = seq[0][j];
			int ct = 0;
			for (int kk = 0; kk < k; kk++) {
				if (ind[kk][vprev] < ind[kk][vcur]) ct++;
			}
			if (ct < k) continue;
			dp[vcur] = max(dp[vcur], dp[vprev]+1);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]); //this is on values i think
	}
	cout << ans << endl;
	cin >>  ans;
}