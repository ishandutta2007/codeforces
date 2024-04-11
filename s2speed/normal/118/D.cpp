#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll md = 1e8;

ll dp[120][120];

int main(){
	ll n1 , n2 , k1 , k2;
	cin>>n1>>n2>>k1>>k2;
	for(int i = 0 ; i <= n1 ; i++){
		for(int j = 0 ; j <= n2 ; j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for(int i = 1 ; i <= n1 ; i++){
		if(i <= k1){
			dp[i][0] = 1;
		} else {
			break;
		}
	}
	for(int i = 1 ; i <= n2 ; i++){
		if(i <= k2){
			dp[0][i] = 1;
		} else {
			break;
		}
	}
	for(int i = 1 ; i <= n1 ; i++){
		for(int j = 1 ; j <= n2 ; j++){
			bool st = true;
			ll x = i - 1 , y = j , z = 0;
			while(x >= 0 && y >= 0){
				if(st){
					z += dp[x][y];
					z %= md;
					st = !st;
					x -= k1;
					if(y >= 1 || x >= 1) y--;
				} else {
					z -= dp[x][y] - md;
					z %= md;
					st = !st;
					y -= k2;
					if(x >= 1 || y >= 1) x--;
				}
			}
			dp[i][j] += z;
			x = i; y = j - 1; z = 0; st = true;
			while(x >= 0 && y >= 0){
				if(st){
					z += dp[x][y];
					z %= md;
					st = !st;
					y -= k2;
					if(x >= 1 || y >= 1) x--;
				} else {
					z -= dp[x][y] - md;
					z %= md;
					st = !st;
					x -= k1;
					if(y >= 1 || x >= 1) y--;
				}
			}
			dp[i][j] += z;
			dp[i][j] %= md;
		}
	}
	cout<<dp[n1][n2]<<"\n";
	return 0;
}