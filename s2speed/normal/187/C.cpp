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

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 1e10;

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

vector<ll> adj[MAXN] , gas , bfs;
vector<pll> ed;
vector<plll> fed;
ll dis[MAXN] , par[MAXN];

void BFS(){
	for(auto i : gas){
		dis[i] = 0;
		par[i] = i;
		bfs.push_back(i);
	}
	ll x = 0;
	while(x < bfs.size()){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(dis[i] > dis[v] + 1){
				dis[i] = dis[v] + 1;
				par[i] = par[v];
				bfs.push_back(i);
			}
		}
	}
	return;
}

ll ds[MAXN];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	ds[u] = v;
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	ll n , m , k , s , t;
	cin>>n>>m>>k;
	for(ll i = 0 ; i < k ; i++){
		ll v;
		cin>>v; v--;
		gas.push_back(v);
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		ed.push_back({v , u});
		adj[v].push_back(u); adj[u].push_back(v);
	}
	cin>>s>>t; s--; t--; gas.push_back(t);
	BFS();
	for(auto p : ed){
		ll v = p.first , u = p.second;
		if(par[v] != par[u]){
			fed.push_back({dis[v] + dis[u] + 1 , {par[v] , par[u]}});
		}
	}
	iota(ds , ds + n , 0);
	sort(all(fed));
	for(auto q : fed){
		pll p = q.second;
		ll v = q.first;
		merge(p.first , p.second);
		if(dsu(s) == dsu(t)){
			cout<<v<<'\n';
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}

/*

*/