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
		ll n , k;
		cin>>n>>k;
		if(n == 1){
			cout<<0<<"\n";
		} else if(n == 2){
			cout<<k<<"\n";
		} else {
			cout<<k * 2<<"\n";
		}
	}
	return 0;
}