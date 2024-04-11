#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 998244353 , inf = 2e17;
pll def = {inf , -1};

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
	vector<pll> val , laz;
	pll nl = {-1 , -1};

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , def);
		laz.assign(sz << 1 , nl);
		return;
	}
	
	void shift(ll x , ll lx , ll rx){
		if(laz[x] == nl) return;
		pll h = laz[x];
		laz[x] = nl;
		val[x] = h;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] = laz[rn] = h;
		return;
	}

	void set(ll l , ll r , pll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(l , r , k , ln , lx , m); set(l , r , k , rn , m , rx);
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void set(ll l , ll r , pll k){
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	pll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return def;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		pll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return min(a , b);
	}

	pll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear(); laz.clear();
	}

};

ll a[maxn] , b[maxn] , dp[maxn] , bt[maxn] , ft[maxn] , tme , dis[maxn] , dep = 0;
vector<ll> adj[maxn] , jda[maxn];
vector<plll> cl[maxn];
segtree st;

void bDFS(ll r){
	dis[r] = dep++;
	bt[r] = tme++;
	for(auto i : jda[r]){
		if(i == b[r]) continue;
		bDFS(i);
	}
	ft[r] = tme;
	dep--;
	return;
}

void aDFS(ll r){
	dp[r] = (r == 0 ? 0 : dp[a[r]]);
	pll h = st.cal(bt[r] , ft[r]);
	if(h.second == -1){
		st.set(bt[r] , ft[r] , {dis[r] , r});
		dp[r]++;
		cl[r].push_back({r , def});
	} else if(h.first < dis[r]){
		ll v = h.second;
		st.set(bt[v] , ft[v] , def);
		st.set(bt[r] , ft[r] , {dis[r] , r});
		cl[r].push_back({v , {dis[v] , v}});
	}
	for(auto i : adj[r]){
		if(i == a[r]) continue;
		aDFS(i);
	}
	for(auto q : cl[r]){
		ll v = q.first;
		st.set(bt[v] , ft[v] , q.second);
	}
	cl[r].clear();
	return;
}

void solve(){
	st.clear();
	ll n;
	cin>>n;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear(); jda[i].clear();
	}
	for(ll i = 1 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		adj[i].push_back(a[i]); adj[a[i]].push_back(i);
	}
	for(ll i = 1 ; i < n ; i++){
		cin>>b[i]; b[i]--;
		jda[i].push_back(b[i]); jda[b[i]].push_back(i);
	}
	tme = 0;
	bDFS(0);
	aDFS(0);
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		ans = max(ans , dp[i]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}