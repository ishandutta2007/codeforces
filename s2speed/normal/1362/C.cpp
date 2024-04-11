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

ll sm2(ll n){
	ll counter = 0 , h = 1;
	while(h <= n){
		counter++;
		h *= 2;
	}
	counter--;
	return counter;
}

const ll z = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll dp[64];
	dp[0] = 1;
	for(int i = 1 ; i < 64 ; i++){
		dp[i] = 2 * dp[i - 1] + 1;
	}
	ll t;
	cin>>t;
	while(t--){
		ll n , ans = 0 , h;
		cin>>n;
		h = sm2(n);
		while(n > 0){
			ans += dp[h];
			n -= tav(2 , h);
			h = sm2(n);
		}
		cout<<ans<<"\n";
	}
	return 0;
}