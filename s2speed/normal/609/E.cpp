#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;

struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

vector<int> adj[MAX_N] , v[MAX_N] , dsu[MAX_N] , msp;
int jad[MAX_N][20] , dis[MAX_N] , dep = 0 , rmq[MAX_N][20] , ds[MAX_N];
ll ans[MAX_N];
map<pii , int> wm;
vector<piii> ed;
set<pii> s;

void DFS(int r , int par){
	jad[r][0] = par;
	if(par != -1) rmq[r][0] = wm[{par , r}];
	int o;
	for(int i = 1 ; i < 20 ; i++){
		if(jad[r][i - 1] == -1){
			o = i;
			break;
		}
		jad[r][i] = jad[jad[r][i - 1]][i - 1];
		rmq[r][i] = max(rmq[r][i - 1] , rmq[jad[r][i - 1]][i - 1]);
	}
	for(int i = o ; i < 20 ; i++){
		rmq[r][i] = rmq[r][i - 1];
	}
	dis[r] = dep++;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	dep--;
	return;
}

pii find_jad(int u , int d){
	int h = 1 << 19 , o = -1;
	for(int i = 19 ; i >= 0 && u > -1 ; i--){
		if(d >= h){
			o = max(o , rmq[u][i]);
			u = jad[u][i];
			d -= h;
		}
		h /= 2;
	}
	return {u , o};
}

int LCA(int v , int u){
	int o = -1;
	if(dis[v] > dis[u]){
		pii p;
		p = find_jad(v , dis[v] - dis[u]);
		v = p.first;
		o = p.second;
	}
	if(dis[u] > dis[v]){
		pii p;
		p = find_jad(u , dis[u] - dis[v]);
		u = p.first;
		o = p.second;
	}
	if(v == u){
		return o;
	}
	for(int i = 19 ; i >= 0 ; i--){
		if(jad[v][i] != jad[u][i]){
			o = max(o , rmq[v][i]);
			o = max(o , rmq[u][i]);
			v = jad[v][i];
			u = jad[u][i];
		}
	}
	o = max(o , rmq[v][0]);
	o = max(o , rmq[u][0]);
	return o;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , m;
	ll sum = 0;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		int v , u , w;
		cin>>v>>u>>w; v--; u--;
		ed.push_back({v , u , w});
		wm[{v , u}] = w; wm[{u , v}] = w;
		s.insert({w , i});
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 20 ; j++){
			jad[i][j] = -1;
			rmq[i][j] = -1;
		}
	}
	for(int i = 0 ; i < m ; i++){
		ans[i] = -1;
	}
	for(int i = 0 ; i < n ; i++){
		ds[i] = i;
		dsu[i].push_back(i);
	}
	while(s.size() > 0){
		pii p = *s.begin();
		s.erase(s.begin());
		int i = p.second , w = p.first;
		int v = ed[i].first , u = ed[i].second;
		if(ds[v] == ds[u]) continue;
		adj[v].push_back(u); adj[u].push_back(v);
		sum += w;
		msp.push_back(i);
		if(dsu[ds[v]].size() < dsu[ds[u]].size()){
			swap(u , v);
		}
		int o = ds[u];
		for(auto j : dsu[o]){
			ds[j] = ds[v];
			dsu[ds[v]].push_back(j);
		}
		dsu[o].clear();
	}
	for(auto i : msp){
		ans[i] = sum;
	}
	DFS(0 , -1);
	for(int i = 0 ; i < m ; i++){
		if(ans[i] != -1) continue;
		int v = ed[i].first , u = ed[i].second;
		int o = LCA(v , u);
		ll h;
		h = sum + ed[i].third - o;
		ans[i] = h;
	}
	for(int i = 0 ; i < m ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}