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

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 2e9;

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

ll n , m , k , q;
vector<pll> adj[MAXN] , fdj[MAXN];
vector<plll> fed , ed;
ll dis[MAXN] , par[MAXN];
priority_queue<pll , vector<pll> , greater<pll> > pq;
bitset<MAXN> mark;

void dij(){
	for(ll i = 0 ; i < k ; i++){
		dis[i] = 0;
		par[i] = i;
		pq.push({0 , i});
	}
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(mark[v]) continue;
		mark[v] = true;
		for(auto y : adj[v]){
			ll i = y.first , w = y.second;
			if(dis[i] > dis[v] + w){
				dis[i] = dis[v] + w;
				par[i] = par[v];
				pq.push({dis[i] , i});
			}
		}
	}
	return;
}

ll ds[MAXN];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u , ll w){
	ll a = v , b = u;
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	fdj[a].push_back({b , w}); fdj[b].push_back({a , w});
	ds[u] = v;
	return;
}

ll jad[MAXN][20] , rmq[MAXN][20] , h[MAXN] , dep = 0;

void DFS(ll r , ll par){
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
		rmq[r][j] = max(rmq[r][j - 1] , rmq[jad[r][j - 1]][j - 1]);
	}
	h[r] = dep++;
	for(auto p : fdj[r]){
		ll i = p.first , w = p.second;
		if(i == par) continue;
		jad[i][0] = r;
		rmq[i][0] = w;
		DFS(i , r);
	}
	dep--;
	return;
}

pll find_jad(ll v , ll d){
	d = h[v] - d;
	ll res = -1;
	for(ll j = 0 ; j < 20 ; j++){
		if(d & 1){
			res = max(res , rmq[v][j]);
			v = jad[v][j];
		}
		d >>= 1;
	}
	return {v , res};
}

ll ask(ll v , ll u){
	ll res = -1;
	if(h[v] > h[u]) swap(v , u);
	pll p = find_jad(u , h[v]);
	res = p.second; u = p.first;
	if(v == u) return res;
	for(ll j = 19 ; j >= 0 ; j--){
		if(jad[v][j] == jad[u][j]) continue;
		res = max(res , rmq[v][j]);	res = max(res , rmq[u][j]);
		v = jad[v][j]; u = jad[u][j];
	}
	res = max(res , rmq[v][0]); res = max(res , rmq[u][0]);
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	memset(jad , -1 , sizeof(jad));
	memset(rmq , 63 , sizeof(rmq));
	cin>>n>>m>>k>>q;
	iota(ds , ds + k , 0);
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back({u , w}); adj[u].push_back({v , w});
		ed.push_back({w , {v , u}});
	}
	dij();
	for(auto e : ed){
		ll w = e.first , v = e.second.first , u = e.second.second;
		if(par[v] == par[u]) continue;
		fed.push_back({dis[v] + dis[u] + w , {par[v] , par[u]}});
	}
	sort(all(fed));
	for(auto y : fed){
		merge(y.second.first , y.second.second , y.first);
	}
	DFS(0 , -1);
	while(q--){
		ll v , u;
		cin>>v>>u; v--; u--;
		cout<<ask(v , u)<<'\n';
	}
	return 0;
}

/*

*/