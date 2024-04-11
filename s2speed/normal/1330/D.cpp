#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll m;

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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll dp[40] , d , ans , t;
	cin>>t;
	while(t--){
		cin>>d>>m;
		if(d == 1){
			cout<<d % m<<endl;
			continue;
		}
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2 ; i < 35 ; i++){
			dp[i] = ((dp[i - 1] * (tav(2 , i - 1) + 1)) % m) + tav(2 , i - 1);
			dp[i] %= m;
		}
		for(int i = 1 ; i < 35 ; i++){
			if(d / tav(2 , i) == 1){
				ans = ((d + 2 - tav(2 , i)) * dp[i]) % m + (d - (tav(2 , i) - 1));
				ans %= m;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}