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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	vector<ll> val , laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , -inf);
		laz.assign(sz << 1 , 0);
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
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(){
		return val[0];
	}

	void clear(){
		sz = 1;
		val.clear();
		laz.clear();
		return;
	}

};

segtree st;
vector<ll> adj[maxn] , del[maxn] , a;
ll dis[maxn] , ds[maxn] , dep = 0 , bt[maxn] , ft[maxn] , tme = 0 , pr[maxn] , ch[maxn];
ll cur , v , r , n;

void pDFS(ll r , ll par){
	pr[r] = par;
	dis[r] = dep++;
	bt[r] = tme++;
	for(auto i : adj[r]){
		if(i == par) continue;
		pDFS(i , r);
	}
	ft[r] = tme;
	dep--;
	return;
}

void dDFS(ll r , ll par){
	ds[r] = dep++;
	for(auto i : adj[r]){
		if(i == par) continue;
		dDFS(i , r);
	}
	dep--;
	return;
}

bool check(ll x){
	if(cur < 1) return false;
	if(cur >= dis[r]) return true;
	if(x > cur) return false;
	while(dis[r] - dis[v] + x < cur){
		st.add(bt[v] , ft[v] , 2);
		st.add(0 , n , -1);
		v = pr[v];
	}
	if(dis[r] - dis[v] + x > cur){
		v = ch[v];
		st.add(bt[v] , ft[v] , -2);
		st.add(0 , n , 1);
	}
	return (st.cal() + x <= cur);
}

void solve(){
	cin>>n;
	tme = 0;
	st.clear();
	a.clear();
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear();
		del[i].clear();
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	pDFS(0 , -1);
	st.init(n);
	cur = -1;
	r = 0;
	for(ll i = 0 ; i < n ; i++){
		del[dis[i]].push_back(i);
		if(dis[i] > dis[r]) r = i;
	}
	dDFS(r , -1);
	ll o = r;
	while(o > 0){
		ch[pr[o]] = o;
		o = pr[o];
	}
	a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		a[bt[i]] = ds[i];
	}
	st.build(a);
	v = r;
	for(ll i = 1 ; i <= n ; i++){
		while(!check(i)){
			cur++;
			for(auto j : del[cur]){
				st.add(bt[j] , bt[j] + 1 , -inf);
			}
		}
		cout<<cur<<' ';
	}
	cout<<'\n';
	return;
}

/*
1
7
1 2
1 3
3 4
3 5
3 6
5 7
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}