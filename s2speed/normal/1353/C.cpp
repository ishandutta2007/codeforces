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

ll lcm(ll a , ll b){
	ll h = a * b;
	return h / __gcd(a , b);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , ans;
		ans = 0;
		cin>>n;
		for(ll i = n - 1 , j = n / 2 ; i > 0 ; i -= 2 , j--){
			ans += i * j;
		}
		cout<<ans * 4<<"\n";
	}
	return 0;
}