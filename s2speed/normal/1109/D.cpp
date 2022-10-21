#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 17 , md = 1e9 + 7 , inf = 2e16;

inline ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll fact[maxn] , _fact[maxn];

void fact_build(){
	fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = fact[i - 1] * i % md;
	}
	_fact[maxn - 1] = tav(fact[maxn - 1] , md - 2);
	for(ll i = maxn - 2 ; ~i ; i--){
		_fact[i] = _fact[i + 1] * (i + 1) % md;
	}
	return;
}

ll chs(ll n , ll k){
	if(k < 0 || k > n) return 0;
	return fact[n] * _fact[k] % md * _fact[n - k] % md;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	ll n , m , completelyusefullinput1 , completelyusefullinput2;
	cin>>n>>m>>completelyusefullinput1>>completelyusefullinput2;
	ll z = tav(n , n - 2) * tav(m , n - 1) % md , dv = tav(n , md - 2) * tav(m , md - 2) % md , ans = 0;
	for(ll i = 0 ; i < n - 1 ; i++){
		z *= dv; z %= md;
		ll h = chs(m - 1 , i) * z % md * (2 + i) % md;
		ans += h;
		z *= n - 2 - i; z %= md;
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}