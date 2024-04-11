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

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll ds[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return;
}

vector<ll> prt;
vector<pll> adj[maxn];
vector<plll> fed;
ll dis[maxn] , par[maxn];
priority_queue<pll , vector<pll> , greater<pll>> pq;
bitset<maxn> mark;

void dij(){
	while(!pq.empty()){
		pll q = pq.top(); pq.pop();
		ll v = q.second;
		if(mark[v]) continue;
		mark[v] = true;
		for(auto p : adj[v]){
			ll i = p.first , w = p.second;
			if(dis[i] > dis[v] + w){
				par[i] = par[v];
				dis[i] = dis[v] + w;
				pq.push({dis[i] , i});
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(dis , 63 , sizeof(dis));
	ll n , m , k , ans = inf;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back({u , w}); adj[u].push_back({v , w});
	}
	cin>>k;
	for(ll i = 0 ; i < k ; i++){
		ll v;
		cin>>v; v--;
		prt.push_back(v);
	}
	dis[0] = 0;
	pq.push({0 , 0});
	dij();
	for(auto i : prt){
		ans = min(ans , dis[i]);
	}
	memset(dis , 63 , sizeof(dis));
	mark.reset();
	for(auto i : prt){
		dis[i] = 0;
		par[i] = i;
		pq.push({0 , i});
	}
	dij();
	for(ll v = 0 ; v < n ; v++){
		for(auto p : adj[v]){
			ll i = p.first , w = p.second;
			if(i < v) continue;
			if(par[i] != par[v]) fed.push_back({dis[v] + w + dis[i] , {par[v] , par[i]}});
		}
	}
	sort(all(fed));
	iota(ds , ds + n , 0);
	for(auto q : fed){
		ll v = q.second.first , u = q.second.second , w = q.first;
		if(dsu(v) != dsu(u)){
			merge(v , u);
			ans += w;
		}
	}
	cout<<ans<<'\n';
	return 0;
}