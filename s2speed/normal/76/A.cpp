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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e2 + 16 , md = 1e9 + 7 , inf = 2e18;

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

ll ds[maxn] , dsz[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(dsz[v] < dsz[u]) swap(v , u);
	if(v == u) return;
	dsz[v] += dsz[u];
	ds[u] = v;
	return;
}

struct edge {
	ll v , u , g , s;
};

bool gmp(edge a , edge b){
	return a.g < b.g;
}

bool smp(edge a , edge b){
	return a.s < b.s;
}

vector<edge> ed , y;
vector<pll> adj[maxn] , h;
ll jad[maxn][20] , dis[maxn] , dep = 0 , cur = 0;
pll rmq[maxn][20];

void DFS(ll r , ll par , ll w){
	cur = max(cur , w);
	dis[r] = dep++;
	jad[r][0] = par;
	rmq[r][0] = {w , r};
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
		rmq[r][j] = max(rmq[r][j - 1] , rmq[jad[r][j - 1]][j - 1]);
	}
	for(auto p : adj[r]){
		ll i = p.first , j = p.second;
		if(i == par) continue;
		DFS(i , r , j);
	}
	dep--;
	return;
}

plll find_jad(ll v , ll d){
	pll res = {-1 , -1};
	d = dis[v] - d;
	for(ll j = 0 ; j < 20 ; j++){
		if(d & (1 << j)){
			res = max(res , rmq[v][j]);
			v = jad[v][j];
		}
	}
	return {v , res};
}

pll LCA(ll v , ll u){
	pll res;
	if(dis[v] > dis[u]) swap(v , u);
	plll p = find_jad(u , dis[v]);
	u = p.first; res = p.second;
	if(v == u) return res;
	for(ll j = 19 ; j >= 0 ; j--){
		if(jad[v][j] != jad[u][j]){
			res = max(res , max(rmq[v][j] , rmq[u][j]));
			v = jad[v][j]; u = jad[u][j];
		}
	}
	res = max(res , max(rmq[v][0] , rmq[u][0]));
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(jad , -1 , sizeof(jad));
	ll n , m , S , G , ans = 0;
	cin>>n>>m>>G>>S;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , s , g;
		cin>>v>>u>>g>>s; v--; u--; if(v == u) continue;
		ed.push_back({v , u , g , s});
	}
	sort(all(ed) , gmp); m = ed.size();
	iota(ds , ds + n , 0);
	fill(dsz , dsz + n , 1);
	ll x = -1;
	for(ll i = 0 ; i < m ; i++){
		ll v = ed[i].v , u = ed[i].u;
		merge(v , u);
		if(dsz[dsu(v)] == n){
			x = ed[i].g;
			break;
		}
	}
	if(x == -1){
		cout<<x<<'\n';
		return 0;
	}
	ll bruh;
	for(ll i = 0 ; i < m ; i++){
		if(ed[i].g > x){
			bruh = i;
			break;
		}
		y.push_back(ed[i]);
	}
	sort(all(y) , smp);
	iota(ds , ds + n , 0);
	for(auto p : y){
		ll v = dsu(p.v) , u = dsu(p.u);
		if(v != u){
			adj[p.v].push_back({p.u , p.s}); adj[p.u].push_back({p.v , p.s});
			merge(v , u);
		}
	}
	DFS(0 , -1 , 0);
	ans = 1ll * G * x + 1ll * S * cur;
	for(ll i = bruh ; i < m ; i++){
		ll v = ed[i].v , u = ed[i].u , w = ed[i].s;
		pll p = LCA(v , u);
		if(p.first > w){
			ll j = p.second , k = jad[j][0];
			for(auto q : adj[j]){
				if(q.first == k) continue;
				h.push_back(q);
			}
			adj[j] = h;
			h.clear();
			for(auto q : adj[k]){
				if(q.first == j) continue;
				h.push_back(q);
			}
			adj[k] = h;
			h.clear();
			adj[v].push_back({u , w}); adj[u].push_back({v , w});
			memset(jad , -1 , sizeof(jad));
			cur = 0;
			DFS(0 , -1 , 0);
			ans = min(ans , 1ll * G * ed[i].g + 1ll * S * cur);
		}
	}
	cout<<ans<<'\n';
	return 0;
}