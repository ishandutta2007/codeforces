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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e6 + 15 , md = 1e9 + 7 , inf = 1e10;

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
	vector<pll> mx , st;
	pll p = {inf , inf};
 
	void init(ll n){
		while(sz < n) sz <<= 1;
		mx.assign(2 * sz , p);
		st.assign(2 * sz , p);
		return;
	}
 
	void shift(ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(st[x] != p){
				mx[x] = st[x];
				st[x] = p;
			}
			return;
		}
		if(st[x] != p){
			mx[x] = st[x];
		}
		ll ln = 2 * x + 1 , rn = ln + 1;
		if(st[x] != p){
			st[ln] = st[x];
			st[rn] = st[x];
		}
		st[x] = p;
		return;
	}
 
	void set(ll l , ll r , pll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			st[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		set(l , r , k , ln , lx , m); set(l , r , k , rn , m , rx);
		mx[x] = max(mx[ln] , mx[rn]);
		return;
	}
 
	void set(ll l , ll r , pll k){
		if(l >= r || l == -1 || r == -1) return;
		set(l , r , k , 0 , 0 , sz);
		return;
	}
 
	ll xcal(pll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(mx[x] < k) return -1;
		if(rx - lx == 1){
			return lx;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a = xcal(k , ln , lx , m);
		if(a != -1) return a;
		return xcal(k , rn , m , rx);
	}
 
	ll xcal(pll k){
		return xcal(k , 0 , 0 , sz);
	}
 
};

struct sagtree {

	ll sz = 1;
	vector<ll> laz , lav;
	vector<pll> val;
	pll p = {-inf , -inf};

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(2 * sz , p);
		laz.assign(2 * sz , inf);
		lav.assign(2 * sz , -inf);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		if(laz[x] == inf) return;
		ll h = laz[x];
		val[x].second = laz[x];
		val[x].first = lav[x];
		laz[x] = inf;
		if(rx - lx == 1){
			return;
		}
		ll ln = 2 * x + 1 , rn = ln + 1;
		laz[ln] = h;
		laz[rn] = h;
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
		ll o = val[ln].first + val[ln].second , u = val[rn].first + val[rn].second;
		if(o > u){
			val[x] = val[ln];
		} else {
			val[x] = val[rn];
		}
		return;
	}		

	void set(ll l , ll r , ll k){
		if(l >= r) return;
		if(l == -1) l++;
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	void Set(ll i , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx - lx == 1){
			val[x].first = k;
			lav[x] = k;
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		if(i < m){
			Set(i , k , ln , lx , m);
		} else {
			Set(i , k , rn , m , rx);
		}
		ll o = val[ln].first + val[ln].second , u = val[rn].first + val[rn].second;
		lav[x] = max(lav[ln] , lav[rn]);
		if(o > u){
			val[x] = val[ln];
		} else {
			val[x] = val[rn];
		}
		return;
	}

	void Set(ll i , ll k){
		Set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return -inf;
		if(rx <= r && lx >= l) return val[x].first + val[x].second;
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
sagtree ts;

ll a[MAXN] , b[MAXN] , dp[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	for(ll i = 1 ; i <= n ; i++){
		cin>>b[i];
	}
	st.init(n + 1);
	ts.init(n + 1);
	dp[0] = 0;
	ts.Set(0 , dp[0]);
	st.set(0 , 1 , {-inf , -inf});
	for(ll i = 1 ; i <= n ; i++){
		ll o = st.xcal({a[i] , -b[i]});
		st.set(o , i + 1 , {a[i] , -b[i]});
		ts.set(o - 1 , i , b[i]);
		dp[i] = ts.cal(0 , i + 1);
		ts.Set(i , dp[i]);
	}
	cout<<dp[n]<<'\n';
	return 0;
}

/*

*/