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

const ll maxn = 1e6 + 16 , md = 998244353 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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
	fact[0] = _fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = 1ll * fact[i - 1] * i % md;
	}
	_fact[maxn - 1] = tav(fact[maxn - 1] , md - 2);
	for(ll i = maxn - 2 ; i ; i--){
		_fact[i] = 1ll * _fact[i + 1] * (i + 1) % md;
	}
	return;
}

ll chs(ll n , ll k){
	return 1ll * fact[n] * _fact[k] % md * _fact[n - k] % md;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	ll n , ans = 0;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		ll h = 1ll * chs(n , i) * tav(3 , 1ll * n * (n - i) + i) % md;
		ans += h * (-1 + ((i & 1) << 1));
	}
	ans %= md;
	for(ll i = 1 ; i <= n ; i++){
		ll h = 1ll * chs(n , i) * (tav(3 , i) - 3) % md * tav(3 , 1ll * n * (n - i)) % md;
		ans += h * (-1 + ((i & 1) << 1));
		ll o = tav(3 , n - i) - 1;
		h = 3ll * chs(n , i) * tav(o , n) % md;
		ans += h * (-1 + ((i & 1) << 1));
	}
	ans %= md; if(ans < 0) ans += md;
	cout<<ans<<'\n';
	return 0;
}