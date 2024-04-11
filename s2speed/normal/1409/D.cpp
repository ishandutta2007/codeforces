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

ll dsum(ll a){
	ll sum = 0;
	while(a > 0){
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , s , h , ans , k = 10;
		cin>>n>>s; ans = n;
		h = dsum(ans);
		while(h > s){
			ans -= ans % k;
			ans += k;
			h = dsum(ans);
			k *= 10;
		}
		cout<<ans - n<<"\n";
	}
	return 0;
}