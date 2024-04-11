#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
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
	_fact[0] = 1;
	for(int i = 1 ; i < maxn ; i++){
		fact[i] = 1ll * fact[i - 1] * i % md;
		_fact[i] = tav(fact[i] , md - 2);
	}
}

ll chs(ll n , ll k){
	if(k > n || k < 0 || n < 0) return 0;
	return 1ll * fact[n] * _fact[k] % md * _fact[n - k] % md;
}

ll dv(ll n , ll k){
	return 1ll * n * tav(k , md - 2) % md;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	ll n , m , h , ans = 0 , res = 0;
	cin>>n>>m>>h;
	if(n == 0){
		cout<<(m > h)<<'\n';
		return 0;
	}
	if(m == 0){
		cout<<"1\n";
		return 0;
	}
	for(ll i = 1 ; i <= n + m ; i++){
		ll l = (i + 1) / 2 , r = i / 2 , o;
		o = 1ll * chs(n - 1 , l - 1) * chs(m - 1 , r - 1) % md;
		ans += o;
		o = 1ll * chs(n - 1 , r - 1) * chs(m - 1 , l - 1) % md;
		ans += o;
	}
	ans %= md;
	for(ll i = 1 ; i <= n + m ; i++){
		ll l = (i + 1) / 2 , r = i / 2 , o;
		o = 1ll * chs(n - 1 , l - 1) * chs(m - 1 - (1ll * h * r) , r - 1) % md;
		res += o;
		o = 1ll * chs(n - 1 , r - 1) * chs(m - 1 - (1ll * h * l) , l - 1) % md;
		res += o;
	}
	res %= md;
	ans = dv(res , ans);
	cout<<ans<<'\n';
	return 0;
}