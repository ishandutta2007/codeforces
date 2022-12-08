#include <bits/stdc++.h>

using namespace std;


const int inf = 1000000;
int dp[2][51][101];
int nums[20010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, k, p;
	cin >> N >> k >> p;
	for (int i = 0; i <= 50; i++) {
		fill(dp[0][i], dp[0][i]+101, inf);
	}
	dp[0][0][0] = 0;
	int tsum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		nums[i] = nums[i]%p;
		tsum += nums[i];
	}
	int cur = 0;
	int prev = 1;
	int minsub = inf; //minimum number we are forced to subtract out
	for (int i = 1; i <= N; i++) {
		cur = prev;
		prev = 1-cur;
		for (int j = 0; j <= k; j++) {
			fill(dp[cur][j], dp[cur][j]+p, inf);
		}
		for (int j = 0; j <= k; j++) {
			for (int m = 0; m < p; m++) {
				//close off after me
				int nx = m + nums[i];
				int delt = 0;
				if (nx >= p) {
					delt = 1; //it overflows once (always less than or equal to once)
					nx -= p; //modify to be within range
				}
				if (j < k) { //basically, we just reset k times
					dp[cur][j+1][0] = min(dp[cur][j+1][0], dp[prev][j][m]+delt); //cursum is 0 if closed
					if (i == N && j+1 == k) minsub = min(minsub, dp[prev][j][m]+delt);
				}
				//take another or not

				//don't close and just continue
				if (j < k) {
					dp[cur][j][nx] = min(dp[cur][j][nx], dp[prev][j][m] + delt); 
				}
			}
		}
		
	}
	int ans = tsum - p*minsub;
	cout << ans << endl; 
	cin >> N;


}
//currently i am subtracting 1 less than the optimal answer (my answer is incorrectly more optimal)