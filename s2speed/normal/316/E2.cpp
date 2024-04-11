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

const ll maxn = 3e5 + 16 , md = 1e9 , inf = 2e16;

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

ll a[maxn] , b[maxn] , pa[maxn] , pb[maxn];

struct node {

	ll c0 , c1 , l;

	void def(){
		c0 = c1 = l = 0;
		return;
	}

	void init(ll x){
		c0 = c1 = x;
		l = 1;
		return;
	}

	friend node operator| (node a , ll b){
		node res;
		res.c0 = (a.c0 + 1ll * b * (pa[a.l - 1] + pb[a.l - 1])) % md;
		res.c1 = (a.c1 + 1ll * b * (pa[a.l] + pb[a.l] - 1)) % md;
		res.l = a.l;
		return res;
	}

	friend void operator|= (node &a , ll b){
		a = a | b;
		return;
	}

	friend node operator+ (node x , node y){
		node res;
		res.l = x.l + y.l;
		ll h = 1ll * a[x.l] * y.c0 + 1ll * b[x.l] * y.c1;
		res.c0 = (x.c0 + h) % md;
		h = 1ll * a[x.l + 1] * y.c0 + 1ll * b[x.l + 1] * y.c1;
		res.c1 = (x.c1 + h) % md;
		return res;
	}

};

struct segtree {

	ll sz = 1;
	vector<node> val;
	vector<ll> laz;
	node def;

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.def();
		val.assign(sz << 1 , def);
		laz.assign(sz << 1 , 0);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		val[x] |= h;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= i || lx > i) return;
		if(rx - lx == 1){
			val[x].init(k);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(i , k , ln , lx , m); set(i , k , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
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
		val[x] = val[ln] + val[rn];
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l){
			ll t = lx - l , res;
			res = (1ll * a[t] * val[x].c0 + 1ll * b[t] * val[x].c1) % md;
			return res;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	a[0] = b[1] = 1; a[1] = b[0] = 0;
	pa[0] = pa[1] = pb[1] = 1; pb[0] = 0;
	for(ll i = 2 ; i < maxn - 1 ; i++){
		a[i] = a[i - 1] + a[i - 2];
		a[i] -= (a[i] >= md) * md;
		b[i] = b[i - 1] + b[i - 2];
		b[i] -= (b[i] >= md) * md;
		pa[i] = pa[i - 1] + a[i];
		pa[i] -= (pa[i] >= md) * md;
		pb[i] = pb[i - 1] + b[i];
		pb[i] -= (pb[i] >= md) * md;
	}
	ll n , q;
	cin>>n>>q;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		st.set(i , h);
	}
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t;
		if(t == 1){
			ll i , k;
			cin>>i>>k; i--;
			st.set(i , k);
		} else if(t == 2){
			ll l , r;
			cin>>l>>r; l--;
			cout<<st.cal(l , r) % md<<'\n';
		} else {
			ll l , r , k;
			cin>>l>>r>>k; l--;
			st.add(l , r , k);
		}
	}
	return 0;
}