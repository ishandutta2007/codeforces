#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll md = 998244353 , MAX_N = 3e5 + 20;

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

ll fact[MAX_N];

void fact_build(){
	fact[0] = 1;
	for(int i = 1 ; i < MAX_N ; i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= md;
	}
}

ll chs(ll n, ll k){
    if(k > n) return 0;
    return (((fact[n] * tav(fact[k] , md - 2)) % md) * tav(fact[n - k] , md - 2)) % md;
}

vector<ll> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	fact_build();
	ll n;
	cin>>n;
	v.resize(2 * n);
	for(int i = 0 ; i < 2 * n ; i++){
		cin>>v[i];
	}
	sort(v.begin() , v.end());
	ll ans = 0 , o = chs(2 * n , n);
	for(int i = 0 ; i < n ; i++){
		ll h = o;
		h *= v[i];
		h %= md;
		ans -= h;
		ans += md;
		ans %= md;
	}
	for(int i = n ; i < 2 * n ; i++){
		ll h = o;
		h *= v[i];
		h %= md;
		ans += h;
		ans %= md;
	}
	cout<<ans<<"\n";
	return 0;
}