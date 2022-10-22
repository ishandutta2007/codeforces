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

ll dp[31];

void dp_build(){
	dp[0] = 0;
	for(int i = 1 ; i <= 30 ; i++){
		dp[i] += dp[i - 1] + tav(2 , i - 1) * (tav(2 , i) - 1);
	}
	return;
}

void solve(){
	ll n;
	cin>>n;
	for(int i = 30 ; i >= 0 ; i--){
		if(n >= dp[i]){
			cout<<i<<"\n";
			break;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	dp_build();
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}