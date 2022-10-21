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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<ll> val , laz;

	void build(ll n , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = lx - n;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		build(n , ln , lx , m); build(n , rn , m , rx);
		val[x] = val[ln];
		return;
	}

	void build(ll n){
		build(n , 0 , 0 , sz);
		return;
	}

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , 0);
		build(n);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		val[x] += h;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(){
		return val[0];
	}

};

segtree st;
vector<ll> v;
ll w[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , x;
	cin>>n>>m>>x;
	v.resize(m);
	for(ll i = 0 ; i < m ; i++){
		cin>>v[i];
	}
	sort(all(v));
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		ll j = m - (lower_bound(all(v) , x - h) - v.begin());
		w[i] = j;
	}
	st.init(m);
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		st.add(0 , w[i] , 1);
		if(i >= m) st.add(0 , w[i - m] , -1);
		if(!st.cal()) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}