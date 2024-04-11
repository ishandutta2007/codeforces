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

const ll maxn = 4e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	vector<pll> val;
	vector<ll> laz;
	
	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , {-1 , -1});
		laz.assign(sz << 1 , 0);
	}

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < sze(a)){
				val[x] = {a[lx] , lx};
			}
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
		return;
	}
	
	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		val[x].first += h;
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
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	pll cal(){
		return val[0];
	}

};

segtree st;
vector<ll> adj[maxn];
ll bt[maxn] , ft[maxn] , tme = 0 , dis[maxn] , dep = 0 , pr[maxn];
vector<ll> a , t;

void pDFS(ll r , ll par){
	pr[r] = par;
	bt[r] = tme++;
	t.push_back(r);
	dis[r] = dep++;
	for(auto i : adj[r]){
		if(i == par) continue;
		pDFS(i , r);
	}
	dep--;
	ft[r] = tme;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k;
	cin>>n>>k;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	pDFS(0 , -1);
	a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		a[bt[i]] = dis[i] + 1;
	}
	st.init(n);
	st.build(a);
	ll ans = -(n / 2) * ((n + 1) / 2) , b = n;
	for(ll e = 1 ; e <= k ; e++){
		pll p = st.cal();
		ll v = t[p.second];
		for(ll w = 0 ; w < p.first ; w++){
			st.add(bt[v] , ft[v] , -1);
			v = pr[v];
		}
		b -= p.first;
		ll r = e , w = n - r;
		ll h = (w - b) * (r - b);
		if(r > w) swap(r , w);
		ll q = -((w - r) / 2);
		if(b >= r - q){
			h = q * (w - r + q);
		}
		ans = max(ans , h);
	}
	cout<<ans<<'\n';
	return 0;
}

/*
5 2
2 1
2 3
5 3
4 1
*/