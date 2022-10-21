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

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
		fact[i] = fact[i - 1] * i % md;
	}
	_fact[maxn - 1] = tav(fact[maxn - 1] , md - 2);
	for(ll i = maxn - 2 ; i ; i--){
		_fact[i] = _fact[i + 1] * (i + 1) % md;
	}
	return;
}

ll chs(ll n , ll k){
	if(k < 0 || k > n) return 0;
	return 1ll * fact[n] * _fact[k] % md * _fact[n - k] % md;
}

vector<ll> pr[maxn];
bitset<maxn> gh;

void prime(){
	gh.set();
	for(ll i = 2 ; i < maxn ; i++){
		if(!gh[i]) continue;
		for(ll j = i ; j < maxn ; j += i){
			pr[j].push_back(i);
			gh[j] = false;
		}
	}
	return;
}

void solve(){
	ll n , k , ans = 0;
	cin>>n>>k;
	ll ps = sze(pr[n]) , lm = 1 << ps;
	for(ll mask = 0 ; mask < lm ; mask++){
		ll cnt = 0 , h = 1 , m;
		for(ll j = 0 ; j < ps ; j++){
			if(!((1 << j) & mask)) continue;
			cnt ^= 1;
			h *= pr[n][j];
		}
		m = n / h;
		ans += chs(m - 1 , k - 1) * (1 - (cnt << 1));
	}
	ans %= md; if(ans < 0) ans += md;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	prime();
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}