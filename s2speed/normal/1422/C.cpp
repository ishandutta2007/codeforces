#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0 , md = 1e9 + 7;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x % md;
	} else {
		return x * x % md * n % md;
	}
}

void solve(){
	ll n , ans = 0 , q = 1 , p = 1 , z;
	string k;
	cin>>k; n = k.size();
	q = 0;
	for(int i = n - 1 ; i >= 0 ; i--){
		q += (n - i - 1) * p; q %= md;
		ll h = (k[i] - '0') * q; h %= md;
		ans += h; ans %= md;
		z = (i + 1); z *= i * (k[i] - '0'); z /= 2; z %= md; z *= tav(10 , n - i - 1); z %= md;
		ans += z; ans %= md;
		if(i != n - 1){
			p *= 10; p %= md;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}