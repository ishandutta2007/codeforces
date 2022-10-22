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

const ll maxn = 2e5 + 15 , md = 1e9 + 7;
ll inf;

ll ds[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return;
}

vector<pllll> ed;
vector<pll> adj[maxn] , adi[maxn];
ll z[maxn] , q[maxn] , h[maxn] , jad[maxn][20] , rmq[maxn][20] , dis[maxn] , dep = 0;
bitset<maxn> dead , mark , mst;
pll l[maxn];
ll x , c , cnt;
ll ans[maxn];

void sDFS(ll r , ll par){
	dis[r] = dep++;
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
		rmq[r][j] = max(rmq[r][j - 1] , rmq[jad[r][j - 1]][j - 1]);
	}
	for(auto p : adj[r]){
		ll i = p.first , w = p.second;
		if(i == par) continue;
		rmq[i][0] = w;
		sDFS(i , r);
	}
	dep--;
	return;
}

pll find_jad(ll v , ll d){
	ll res = -1;
	d = dis[v] - d;
	for(ll j = 0 ; j < 20 ; j++){
		if(d & 1){
			res = max(res , rmq[v][j]);
			v = jad[v][j];
		}
		d >>= 1;
	}
	return {v , res};
}

pll LCA(ll v , ll u){
	if(dis[v] > dis[u]) swap(v , u);
	pll p = find_jad(u , dis[v]);
	u = p.first;
	ll res = p.second;
	if(v == u) return {v , res};
	for(ll j = 19 ; j >= 0 ; j--){
		if(jad[v][j] != jad[u][j]){
			res = max(res , max(rmq[v][j] , rmq[u][j]));
			v = jad[v][j]; u = jad[u][j];
		}
	}
	res = max(res , max(rmq[v][0] , rmq[u][0]));
	return {jad[v][0] , res};
}

void cDFS(ll r , ll par){
	cnt++;
	mark[r] = true;
	z[r] = 1;
	for(auto p : adi[r]){
		ll i = p.first;
		if(mark[i]) continue;
		cDFS(i , r);
		z[r] += z[i];
	}
	return;
}

ll find_centroid(ll r , ll par){
	for(auto p : adi[r]){
		ll i = p.first;
		if(i == par || dead[i]) continue;
		if(z[i] > cnt / 2){
			return find_centroid(i , r);
		}
	}
	return r;
}

void lDFS(ll r , ll par){
	l[r] = {x , c};
	for(auto p : adi[r]){
		ll i = p.first;
		if(i == par || dead[i]) continue;
		lDFS(i , r);
	}
	return;
}

void lDFS(ll r){
	l[r] = {-1 , c};
	for(auto p : adj[r]){
		ll i = p.first;
		if(dead[i]) continue;
		lDFS(i , r);
		x++;
	}
	return;
}

void qDFS(ll r , ll ind){
	mark[r] = true;
	for(auto p : adi[r]){
		ll i = p.first , j = p.second;
		if(mark[i]) continue;
		qDFS(i , j);
		q[r] = min(q[r] , q[i]);
	}
	ans[ind] = min(ans[ind] , q[r]);
	return;
}

int main(){ // check maxn
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	memset(rmq , -1 , sizeof(rmq));
	memset(ans , 63 , sizeof(ans)); inf = ans[0];
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		ed.push_back({{w , i} , {v , u}});
	}
	sort(all(ed));
	iota(ds , ds + n , 0);
	for(ll i = 0 ; i < m ; i++){
		ll v = ed[i].second.first , u = ed[i].second.second , w = ed[i].first.first , j = ed[i].first.second;
		if(dsu(v) != dsu(u)){
			merge(v , u);
			adj[v].push_back({u , w}); adj[u].push_back({v , w});
			adi[v].push_back({u , j}); adi[u].push_back({v , j});
			mst[i] = true;
		}
	}
	sDFS(0 , -1);
	for(ll i = 0 ; i < m ; i++){
		ll v = ed[i].second.first , u = ed[i].second.second , w = ed[i].first.first , j = ed[i].first.second;
		if(!mst[i]){
			ans[j] = LCA(v , u).second;
		}
	}
	for(ll j = 0 ; j < 20 ; j++){
		x = 0; c = 0;
		mark = dead;
		memset(q , 63 , sizeof(q));
		for(ll i = 0 ; i < n ; i++){
			if(mark[i]) continue;
			cDFS(i , -1);
			h[i] = find_centroid(i , -1);
			lDFS(h[i]);
			c++;
			cnt = 0;
		}
		for(ll i = 0 ; i < m ; i++){
			if(mst[i]) continue;
			ll v = ed[i].second.first , u = ed[i].second.second , w = ed[i].first.first , j = ed[i].first.second;
			if(l[v].first != l[u].first && l[v].second == l[u].second && !(dead[v] || dead[u])){
				q[v] = min(q[v] , w); q[u] = min(q[u] , w);
			}
		}
		mark = dead;
		for(ll i = 0 ; i < n ; i++){
			if(mark[i]) continue;
			qDFS(h[i] , m);
			dead[h[i]] = true;
		}
	}
	for(ll i = 0 ; i < m ; i++){
		cout<<(ans[i] == inf ? -1 : ans[i] - 1)<<' ';
	}
	cout<<'\n';
	return 0;
}