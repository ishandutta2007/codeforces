#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 3e5 , md = 2000000357 , inf = 2e9 + 1;
// check problem statement

ll t[MAXN];

void t_build(){
	t[0] = 1;
	for(ll i = 1 ; i < MAXN ; i++){
		t[i] = 2ll * t[i - 1] % md;
	}
	return;
}

struct item {

	ll sz , hs , rh;

	friend item operator +(item a , item b){
		item res;
		res.sz = a.sz + b.sz;
		ll h = 1ll * a.rh * t[b.sz] + b.rh;
		res.rh = h % md;
		h = 1ll * b.hs * t[a.sz] + a.hs;
		res.hs = h % md;
		return res;
	}

};

struct segtree {

	ll sz = 1;
	vector<item> val;
	item def = {0 , 0 , 0};

	void val_init(ll x , ll lx , ll rx){
		val[x].sz = rx - lx;
		if(rx - lx == 1) return;
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		val_init(ln , lx , m); val_init(rn , m , rx);
		return;
	}

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(2 * sz , def);
		val_init(0 , 0 , sz);
		return;
	}

	void set(ll i , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = {1 , 1 , 1};
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		if(i < m){
			set(i , ln , lx , m);
		} else {
			set(i , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(ll i){
		set(i , 0 , 0 , sz);
		return;
	}

	item cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return def;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		item a , b;
		a = cal(l , r , ln , lx , m); b = cal(l , r , rn , m , rx);
		return a + b;
	}

	item cal(ll l , ll r){
		if(l >= r) return def;
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	t_build();
	ll n;
	cin>>n;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		ll h , v;
		cin>>h; h--;
		st.set(h);
		v = min(n - h - 1 , h);
		if(v == 0) continue;
		item a , b;
		a = st.cal(h - v , h);
		b = st.cal(h + 1 , h + v + 1);
		if(a.hs != b.rh){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}

/*

*/