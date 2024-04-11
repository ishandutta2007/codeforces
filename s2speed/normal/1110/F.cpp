#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 2e18;
 
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

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign((sz << 1) , 0);
		laz.assign((sz << 1) , 0);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		if(h == 0) return;
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

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return inf;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return min(a , b);
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

ll n , q;
segtree st;
vector<pll> adj[maxn];
vector<plll> v[maxn];
ll ft[maxn] , tme = 0 , ans[maxn] , dis[maxn] , dep = 0;

void dDFS(ll r){
	dis[r] = dep;
	tme++;
	for(auto p : adj[r]){
		ll i = p.first , w = p.second;
		dep += w;
		dDFS(i);
		dep -= w;
	}
	if(adj[r].empty()){
		st.add(r , r + 1 , dep);
	} else {
		st.add(r , r + 1 , inf);
	}
	ft[r] = tme;
	return;
}

void sDFS(ll r){
	for(auto y : v[r]){
		ll l = y.first.first , r = y.first.second , i = y.second;
		ans[i] = st.cal(l , r);
	}
	for(auto p : adj[r]){
		ll i = p.first , w = p.second;
		st.add(0 , n , w); st.add(i , ft[i] , -2ll * w);
		sDFS(i);
		st.add(0 , n , -w); st.add(i , ft[i] , 2ll * w);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>q;
	for(ll u = 1 ; u < n ; u++){
		ll v , w;
		cin>>v>>w; v--;
		adj[v].push_back({u , w});
	}
	st.init(n);
	for(ll i = 0 ; i < q ; i++){
		ll u , l , r;
		cin>>u>>l>>r; u--; l--;
		v[u].push_back({{l , r} , i});
	}
	dDFS(0); sDFS(0);
	for(ll i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}