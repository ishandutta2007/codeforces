#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 5020;

ll dp[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , ans = 0;
	string a , b;
	cin>>n>>m>>a>>b;
	dp[0][0] = 0;
	for(int i = 1 ; i <= n ; i++){
		dp[i][0] = -1;
	}
	for(int j = 1 ; j <= m ; j++){
		dp[0][j] = -1;
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(a[i - 1] == b[j - 1]){
				ll z = max(dp[i - 1][j - 1] , 0LL);
				dp[i][j] = z + 2;
			} else {
				ll z = max(dp[i][j - 1] , dp[i - 1][j]);
				z = max(z , -1LL);
				dp[i][j] = z - 1;
			}
		}
	}
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++){
			ans = max(ans , dp[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}