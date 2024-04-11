#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;
typedef double db;

const ll MAX_N = 2000 + 20 , md = 1e9 + 7;

ll dp[MAX_N][MAX_N];

vector<ll> dv[MAX_N];

void dv_build(){
	ll s;
	for(int i = 1 ; i < MAX_N ; i++){
		s = sqrt(i);
		for(int j = 1 ; j <= s ; j++){
			if(i % j == 0){
				dv[i].push_back(j);
				if(j * j != i){
					dv[i].push_back(i / j);
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	dv_build();
	ll n , k , ans = 0;
	cin>>n>>k;
	for(int i = 1 ; i <= n ; i++){
		dp[1][i] = 1;
	}
	for(int j = 2 ; j <= k ; j++){
		for(int i = 1 ; i <= n ; i++){
			dp[j][i] = 0;
			for(auto q : dv[i]){
				dp[j][i] += dp[j - 1][q];
				dp[j][i] %= md;
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		ans += dp[k][i];
		ans %= md;
	}
	cout<<ans<<'\n';
	return 0;
}