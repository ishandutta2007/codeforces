#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef double db;
 
const int MAX_N = 5000 + 20;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}
 
int dp[MAX_N][MAX_N] , cnt[MAX_N];
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		dp[i][0] = 0;
		cnt[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		int k;
		db trash;
		cin>>k>>trash; k--; cnt[k]++;
		for(int j = 1 ; j <= k ; j++){
			dp[i][j] = dp[i - 1][j];
		}
		for(int j = k + 1 ; j < m ; j++){
			dp[i][j] = min(dp[i - 1][j] + 1 , dp[i][j - 1] + cnt[j]);
		}
	}
	cout<<dp[n - 1][m - 1]<<'\n';
	return 0;
}