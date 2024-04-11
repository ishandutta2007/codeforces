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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e12;

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

struct segtree {

	ll sz = 1;
	vector<ll> val , laz;
	vector<bool> res;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , 0);
		res.assign(sz << 1 , 0);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		bool o = res[x];
		laz[x] = res[x] = 0;
		if(o) val[x] = 0;
		val[x] += h; val[x] %= md;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		if(o){
			res[ln] = res[rn] = true; laz[ln] = laz[rn] = 0;
		}
		laz[ln] += h; laz[rn] += h;
		laz[ln] %= md; laz[rn] %= md;
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
		if(l >= r) return;
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	void rst(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			res[x] = true; laz[x] = 0;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		rst(l , r , ln , lx , m); rst(l , r , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void rst(ll l , ll r){
		rst(l , r , 0 , 0 , sz);
		return;
	}

	ll get(ll i , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx - lx == 1){
			return val[x];
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			return get(i , ln , lx , m);
		}
		return get(i , rn , m , rx);
	}	

	ll get(ll i){
		return get(i , 0 , 0 , sz);
	}

};

segtree st;
set<ll> s;
vector<pll> add[maxn] , del[maxn];
vector<ll> v[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , k;
	cin>>m>>n>>k;
	st.init(m);
	for(ll i = 0 ; i < k ; i++){
		ll x1 , x2 , y1 , y2;
		cin>>x1>>y1>>x2>>y2; x1--; y1--; x2--; y2--;
		add[y1].push_back({x1 , x2 + 1}); del[y2 + 1].push_back({x1 , x2 + 1});
		if(x1) v[y2].push_back(x1 - 1);
	}
	s.insert(m);
	for(auto p : add[0]){
		st.rst(p.first , p.second);
		s.insert(p.first);
	}
	st.add(0 , *s.begin() , 1);
	for(ll i = 0 ; i < n - 1 ; i++){
//		for(ll j = 0 ; j < m ; j++){
//			cout<<st.get(j)<<' ';
//		}
//		cout<<'\n';
		for(auto p : del[i + 1]){
			s.erase(p.first);
		}
		for(auto p : add[i + 1]){
			st.rst(p.first , p.second);
			s.insert(p.first);
		}
		sort(all(v[i]) , greater<ll>());
		for(auto j : v[i]){
			ll h = st.get(j);
			st.add(j + 1 , *s.lower_bound(j) , h);
		}
	}
	cout<<st.get(m - 1)<<'\n';
	return 0;
}

/*
3 3 2
3 2 3 2
2 3 2 3
*/