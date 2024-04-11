#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

ll dp[61][15];

ll fin(ll it, ll am, ll num){
	am+=((num&(1ll<<it)) == (1ll<<it));
	if(it == 0){
		if(am <= 7)return 1;
		else return 0;
	}
	if(am >= 15)return 0;
	if(dp[it][am] != -1)return dp[it][am];
	ll ret = 0;
	for(int i = 0; i <= am; ++i){
		if(am-i <= 7){
			ret+=fin(it-1,i*2,num);
		}
	}
	return dp[it][am] = ret%MOD;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--){
		ll x; cin >> x;
		/*
		for(int i = 0; i <= 60; ++i){
			for(int j = 0; j < 15; ++j){
				dp[i][j] = -1;
			}
		}
		*/
		cout << (x/4+1)%MOD*((x/2-x/4+1)%MOD)%MOD << '\n';
	}
}