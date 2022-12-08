#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 203
#define maxk 1010
int N, K; //caps for the big boys
const ll mod = 1000000007LL; //could be int maybe

ll dp[2][maxn][maxk]; //the whole thing
					  //space saving dp works better here

void add (ll& v1, ll v2) {
	v1 = (v1+v2)%mod;
}

ll mult(ll v1, ll v2) {
	return (v1*v2)%mod;
}
//these above two are just kind of cute ways to do some operations

int main() {
	cin >> N >> K;
	vector<int> nums;
	int cur;
	nums.push_back(0); //allow for 1 indexing
	for (int i = 0; i < N; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= N; j++) {
			fill(dp[i][j], dp[i][j]+maxk, 0LL); //initialize everything to zero
		}
	}
	dp[0][0][0] = 1LL; //set up the initial value
	cur = 1; //overload
	int prev = 0;
	for (int i = 1; i <= N; i++) {
		cur = i % 2; 
		prev =  1-cur;
		// cout << "vals " << cur << " " << prev << endl;

		int d = nums[i]-nums[i-1]; //this will be the added value
		for (int j = 0; j <= N; j++) {
			fill(dp[cur][j], dp[cur][j]+maxk, 0LL); //nerf run time for space
		}

		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= K; k++) {
				//consider contribution of previous group (i-1, j, k)

				//add me to own group
				if (k + j*d <= K) {
					add(dp[cur][j][k+j*d], dp[prev][j][k]); 
				}
				
				//close off one of the groups (can be any group)
				if (k+j*d <= K && j >= 1) {
					add(dp[cur][j-1][k+j*d], mult(dp[prev][j][k], j)); 
				}

				//insert to a group and do not close
				if (k+j*d <= K) {
					add(dp[cur][j][k+j*d], mult(dp[prev][j][k], j));
				}

				//create a new group
				if (k+j*d <= K) {
					add(dp[cur][j+1][k+j*d], dp[prev][j][k]);
				}

			}
		}
	}
	ll ans = 0LL;
	for (int i = 0; i <= K; i++) {
		add(ans, dp[cur][0][i]); //must end up at 0 open groups
	}
	cout << ans << endl;
	cin >> N;
}