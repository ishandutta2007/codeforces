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

const ll maxn = 3e5 + 16 , md = 1e9 + 9 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<ll> val , laz1 , laz2;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz1.assign(sz << 1 , 0);
		laz2.assign(sz << 1 , 0);
		return;
	}

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < sze(a)){
				val[x] = a[lx];
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
		ll l = rx - lx , h1 = laz1[x] , h2 = laz2[x] , o , t;
		laz1[x] = laz2[x] = 0;
		o = 1ll * pa[l] * h1 + 1ll * pb[l] * h2;
		val[x] += o; val[x] %= md;
		if(l == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		t = (l >> 1) + 1;
		laz1[ln] += h1; laz2[ln] += h2;
		laz1[rn] += 1ll * a[t] * h1 + 1ll * b[t] * h2;
		laz2[rn] += 1ll * a[++t] * h1 + 1ll * b[t] * h2;
		laz1[ln] %= md; laz2[ln] %= md;
		laz1[rn] %= md; laz2[rn] %= md;
		return;
	}

	void add(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			ll t = lx - l + 1;
			laz1[x] = (a[t] + b[t]) % md;
			laz2[x] = (a[++t] + b[t]) % md;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , ln , lx , m); add(l , r , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void add(ll l , ll r){
		add(l , r , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	a[1] = b[2] = 1; a[2] = b[1] = 0;
	pa[1] = pa[2] = pb[2] = 1; pb[1] = 0;
	for(ll i = 3 ; i < maxn ; i++){
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
	cin>>n>>q; v.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	st.init(n);
	st.build(v);
	for(ll i = 0 ; i < q ; i++){
		ll t , l , r;
		cin>>t>>l>>r; l--;
		if(t == 1){
			st.add(l , r);
		} else {
			cout<<st.cal(l , r) % md<<'\n';
		}
	}
	return 0;
}