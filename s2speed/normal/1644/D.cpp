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

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e16;

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

ll a[maxn] , b[maxn];
vector<pll> c;

void solve(){
	c.clear();
	ll n , m , k , q , ans = 1;
	cin>>n>>m>>k>>q;
	if(q >= n){
		for(ll i = 0 ; i < n ; i++){
			a[i] = -1;
		}
	}
	if(q >= m){
		for(ll j = 0 ; j < m ; j++){
			b[j] = -1;
		}
	}
	for(ll e = 0 ; e < q ; e++){
		ll x , y;
		cin>>x>>y; x--; y--;
		a[x] = b[y] = e;
		c.push_back({x , y});
	}
	ll h = inf , o = inf;
	if(q < n){
		h = -1;
	} else {
		for(ll i = 0 ; i < n ; i++){
			h = min(h , a[i]);
		}
	}
	if(q < m){
		o = -1;
	} else {
		for(ll i = 0 ; i < m ; i++){
			o = min(o , b[i]);
		}
	}
	h = max(h , o);
	for(ll e = 0 ; e < q ; e++){
		if(e < h) continue;
		ll x = c[e].first , y = c[e].second;
		if(a[x] > e && b[y] > e) continue;
		ans *= k; ans %= md;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}