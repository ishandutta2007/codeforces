#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

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

const ll z = 0;
const ll md = 1e9 + 7;

ll dp[2000001];

void solve(){
	dp[1] = 0;
	dp[2] = 0;
	for(ll i = 3 ; i <= 2e6 ; i++){
		dp[i] = dp[i - 2] * 2 + dp[i - 1];
		if(i % 3 == 0){
			dp[i] += 4;
		}
		dp[i] %= md;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	return 0;
}