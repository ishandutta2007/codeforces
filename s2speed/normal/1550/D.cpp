#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	if(k > n || k < 0) return 0;
	return 1ll * fact[n] * _fact[k] % md * _fact[n - k] % md;
}

ll dv(ll n , ll k){
	return 1ll * n * tav(k , md - 2);
}

void solve(){
	ll n , l , r , ans , x , y;
	cin>>n>>l>>r;
	ll h = min(r - n , 1 - l);
	ans = 1ll * h * chs(n , n >> 1);
	if(n & 1) ans <<= 1;
	ans %= md;
	x = r - h;
	y = l + h;
	for(ll i = 0 ; i < n && x > y ; i++){
		ll a = max(0ll , y) , b = max(0ll , n - x + 1);
		ans += chs(n - a - b , (n >> 1) - a);
		if(n & 1){
			ans += chs(n - a - b , (n >> 1) - a + 1);
		}
		x--; y++;
	}
	ans %= md;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}