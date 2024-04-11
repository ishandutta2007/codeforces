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

ll a[200000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , ans = 0 , c = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i += 2){
		c += a[i];
	}
	ans = max(ans , c);
	for(int i = 0 ; i + 1 < n ; i += 2){
		c -= a[i];
		c += a[i + 1];
		ans = max(ans , c);
	}
	c = a[0];
	for(int i = 1 ; i < n ; i += 2){
		c += a[i];
	}
	ans = max(ans , c);
	for(int i = 1 ; i + 1 < n ; i += 2){
		c -= a[i];
		c += a[i + 1];
		ans = max(ans , c);
	}
	cout<<ans<<"\n";
	return 0;
}