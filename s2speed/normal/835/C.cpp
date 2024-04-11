#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

ll dp[100][100][11] , a[100][100][11] , c;

void dp_build(ll t){
	if(a[0][0][t] == -1){
		dp[0][0][t] = 0;
	} else {
		dp[0][0][t] = a[0][0][t];
	}
	for(int i = 1 ; i < 100 ; i++){
		dp[i][0][t] = dp[i - 1][0][t];
		if(a[i][0][t] != -1){
			dp[i][0][t] += a[i][0][t];
		}
	}
	for(int i = 1 ; i < 100 ; i++){
		dp[0][i][t] = dp[0][i - 1][t];
		if(a[0][i][t] != -1){
			dp[0][i][t] += a[0][i][t];
		}
	}
	for(int i = 1 ; i < 100 ; i++){
		for(int j = 1 ; j < 100 ; j++){
			dp[i][j][t] = dp[i - 1][j][t] + dp[i][j - 1][t] - dp[i - 1][j - 1][t];
			if(a[i][j][t] != -1){
				dp[i][j][t] += a[i][j][t];
			}
		}
	}
}

void solve(){
	for(int i = 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 100 ; j++){
			for(int p = 0 ; p < 11 ; p++){
				a[i][j][p] = -1;
			}
		}
	}
	ll n , q;
	cin>>n>>q>>c; c++;
	for(int i = 0 ; i < n ; i++){
		ll x , y , inp;
		cin>>x>>y>>inp; x--; y--;
		if(a[x][y][0] == -1){
			for(int j = 0 ; j < 11 ; j++){
				a[x][y][j] = 0;
			}
		}
		for(int j = 0 ; j < 11 ; j++){
			a[x][y][j] += (inp + j) % c;
		}
	}
	for(int i = 0 ; i < c ; i++){
		dp_build(i);
	}
	while(q--){
		ll t , x1 , x2 , y1 , y2 , ans;
		cin>>t>>x1>>y1>>x2>>y2; t %= c; x1--; x2--; y1--; y2--;
		ans = dp[x2][y2][t];
		if(x1 > 0){
			ans -= dp[x1 - 1][y2][t];
		}
		if(y1 > 0){
			ans -= dp[x2][y1 - 1][t];
		}
		if(x1 > 0 && y1 > 0){
			ans += dp[x1 - 1][y1 - 1][t];
		}
		cout<<ans<<"\n";
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}