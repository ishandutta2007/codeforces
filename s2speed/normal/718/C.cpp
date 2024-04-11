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

struct matrix {

	ll a[2][2];

	void def(){
		memset(a , 0 , sizeof(a));
		return;
	}

	void I(){
		def();
		a[0][0] = a[1][1] = 1;
		return;
	}

	friend matrix operator* (matrix a , matrix b){
		matrix res;
		res.def();
		for(ll i = 0 ; i < 2 ; i++){
			for(ll j = 0 ; j < 2 ; j++){
				for(ll k = 0 ; k < 2 ; k++){
					res.a[i][j] += 1ll * a.a[i][k] * b.a[k][j];
				}
				res.a[i][j] %= md;
			}
		}
		return res;
	}

	friend void operator*= (matrix &a , matrix b){
		a = a * b;
		return;
	}

	friend matrix operator^ (matrix a , ll k){
		matrix res;
		res.I();
		while(k > 0){
			if(k & 1){
				res *= a;
			}
			a *= a;
			k >>= 1;
		}
		return res;
	}

};

matrix fib , mh;

ll f(ll a , ll b , ll k , bool ch){
	if(k == 0){
		return a;
	}
	if(k == 1){
		return b;
	}
	if(ch) mh = fib ^ (k - 2);
	if(k == 2 && !ch){
		mh.I();
	}
	ll res = 1ll * (mh.a[0][0] + mh.a[0][1]) * a + 1ll * (mh.a[1][0] + mh.a[1][1]) * b;
	res %= md;
	return res;
}

struct node {

	ll a , b;

	void def(){
		a = b = 0;
		return;
	}

	void init(ll x){
		a = f(1 , 1 , x , true);
		mh *= fib;
		b = f(1 , 1 , x + 1 , false);
		return;
	}

	friend node operator+ (node a , ll b){
		node res;
		res.a = f(a.a , a.b , b , true);
		mh *= fib;
		res.b = f(a.a , a.b , b + 1 , true);
		return res;
	}

	friend void operator+= (node &a , ll b){
		a = a + b;
		return;
	}

	friend node operator+ (node a , node b){
		node res;
		res.a = a.a + b.a; res.a -= (res.a >= md) * md;
		res.b = a.b + b.b; res.b -= (res.b >= md) * md;
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

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < sze(a)){
				val[x].init(a[lx]);
			}
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
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
		if(rx <= r && lx >= l) return val[x].a;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz) % md;
	}

};

segtree st;
vector<ll> a;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	fib.a[0][0] = 0;
	fib.a[0][1] = fib.a[1][0] = fib.a[1][1] = 1;
	a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	st.init(n); st.build(a);
	for(ll e = 0 ; e < q ; e++){
		ll t , l , r , k;
		cin>>t>>l>>r; l--;
		if(t == 1){
			cin>>k;
			st.add(l , r , k);
		} else {
			cout<<st.cal(l , r)<<'\n';
		}
	}
	return 0;
}