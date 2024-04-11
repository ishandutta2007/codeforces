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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 2e15;

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

struct segtree {

	ll sz = 1;
	vector<ll> val , laz , xal;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(2 * sz , 0);
		xal.assign(2 * sz , inf);
		laz.assign(2 * sz , -1);
		return;
	}

	void build(ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = lx;
			xal[x] = lx;
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		build(ln , lx , m); build(rn , m , rx);
		val[x] = val[ln] + val[rn]; xal[x] = max(xal[ln] , xal[rn]);
		return;
	}

	void build(){
		build(0 , 0 , sz);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = -1;
		if(h == -1) return;
		val[x] = 1ll * h * (rx - lx);
		xal[x] = h;
		if(rx - lx == 1) return;
		ll ln = 2 * x + 1 , rn = ln + 1;
		laz[ln] = h; laz[rn] = h;
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
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		set(l , r , k , ln , lx , m); set(l , r , k , rn , m , rx);
		val[x] = val[ln] + val[rn]; xal[x] = max(xal[ln] , xal[rn]);
		return;
	}

	void set(ll l , ll r , ll k){
		if(l >= r) return;
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	ll mal(ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(k >= xal[x]) return -1;
		if(rx - lx == 1) return lx;
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a = mal(k , ln , lx , m);
		if(a != -1) return a;
		return mal(k , rn , m , rx);
	}

	ll mal(ll k){
		return mal(k , 0 , 0 , sz);
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;

vector<ll> d[MAXN] , v[MAXN];
ll c[MAXN] , f[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	c[0] = 3;
	for(ll i = 1 ; i < MAXN ; i++){
		for(ll j = i ; j < MAXN ; j += i){
			d[j].push_back(i);
		}
	}
	ll n , ans = 0;
	cin>>n;
	if(n <= 2){
		cout<<"0\n";
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		for(auto j : d[h]){
			v[j].push_back(i);
		}
	}
	st.init(n);
	st.build();
	for(ll i = 2e5 + 1 ; i > 0 ; i--){
		c[i] = 1ll * n * n - st.cal(0 , n);
		if(v[i].size() < 2) continue;
		ll vs = v[i].size() , a = v[i][0] , b = v[i][1] , c = v[i][vs - 2] , d = v[i][vs - 1];
		ll x = min(st.mal(c) , a + 1) , y = min(st.mal(d) , b + 1);
//		cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<x<<' '<<y<<'\n';
		st.set(0 , x , c); st.set(a + 1 , y , d); st.set(b + 1 , n , n);
	}
	for(ll i = 1 ; i <= 2e5 ; i++){
		f[i] = c[i] - c[i - 1];
		ans += 1ll * i * f[i];
	}
	cout<<ans<<'\n';
	return 0;
}