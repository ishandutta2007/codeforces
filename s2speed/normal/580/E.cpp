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

const ll maxn = 2e5 + 16 , md = 2000000357 , P = 131 , inf = 2e9;

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

ll tv[maxn] , _tv[maxn];

struct node {

	ll hs , len;

	void init(ll i , ll x){
		len = x;
		hs = 1ll * _tv[x] * i % md;
		return;
	}

	friend node operator+ (node a , node b){
		node res;
		res.len = a.len + b.len;
		res.hs = (a.hs + 1ll * b.hs * tv[a.len]) % md;
		return res;
	}

};

struct segtree {

	ll sz = 1;
	vector<node> val;
	node def;
	vector<ll> laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.init(0 , 0);
		val.assign(sz << 1 , def);
		laz.assign(sz << 1 , -1);
		return;
	}
	
	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = -1;
		if(h == -1) return;
		val[x].init(h , rx - lx);
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] = laz[rn] = h;
		return;
	}

	void set(ll l , ll r , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(l , r , k , ln , lx , m); set(l , r , k , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(ll l , ll r , ll k){
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	node cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return def;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		node a = cal(l , r , ln , lx , m) , b = cal( l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		if(l >= r) return 0;
		node h = cal(l , r , 0 , 0 , sz);
		return h.hs;
	}

};

segtree st;
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1; _tv[0] = 0;
	ll dv = tav(P - 1 , md - 2);
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = 1ll * tv[i - 1] * P % md;
		_tv[i] = 1ll * (tv[i] - 1) * dv % md;
	}
	ll n , m , k , q;
	cin>>n>>m>>k>>s; q = m + k;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		st.set(i , i + 1 , s[i]);
	}
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t; t--;
		if(t){
			ll l , r , d;
			cin>>l>>r>>d; l--;
			cout<<(st.cal(l , r - d) == st.cal(l + d , r) ? "YES\n" : "NO\n");
		} else {
			ll l , r;
			char c;
			cin>>l>>r>>c; l--;
			st.set(l , r , c);
		}
	}
	return 0;
}