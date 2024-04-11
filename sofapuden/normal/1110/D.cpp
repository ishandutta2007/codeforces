#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	int am[m+5];
	memset(am,0,sizeof am);
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		am[x]++;
	}
	int dp[m+5][5][5];
	for(int i = 0; i < m+5; ++i)for(int j = 0; j < 5; ++j)for(int k = 0; k < 5; ++k)dp[i][j][k] = -1;

	dp[0][0][0] = 0;
	int mx = 0;
	for(int i = 0; i <= m+1; ++i){
		for(int j = 0; j < 5; ++j){
			for(int k = 0; k < 5; ++k){
				if(dp[i][j][k] == -1)continue;
				mx = max(mx,dp[i][j][k]);
				int amf = am[i]-j, ams = am[i+1]-k, amt = am[i+2];
				int mn = min({amf,ams,amt,2});
				for(int l = 0; l <= mn; ++l){
					dp[i+1][k+l][l] = max(dp[i+1][k+l][l],dp[i][j][k] + l + (amf-l)/3);
				}
			}
		}
	}
	cout << mx << '\n';
}

int main(){
	solve();
}