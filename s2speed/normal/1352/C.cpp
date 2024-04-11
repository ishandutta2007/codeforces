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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , k , ans = 0;
		cin>>n>>k;
		ans += n * ((k - 1) / (n - 1));
		ans += k % (n - 1);
		if(k % (n - 1) == 0){
			ans += n - 1;
		}
		cout<<ans<<endl;
	}
	return 0;
}