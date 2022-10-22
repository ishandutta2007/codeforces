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

ll calc(ll a , ll b , ll x , ll y , ll n){
	ll h;
	h = max(b - n , y);
	n -= b - h;
	b = h;
	h = max(a - n , x);
	n -= a - h;
	a = h;
	ll ans = a * b;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll a , b , x , y , n , h , ans;
		cin>>a>>b>>x>>y>>n;
		ans = min(calc(a , b , x , y , n) , calc(b , a , y , x , n));
		cout<<ans<<"\n";
	}
	return 0;
}