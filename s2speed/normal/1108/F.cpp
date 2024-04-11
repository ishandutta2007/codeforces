#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
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

vector<int> adj[MAX_N];
unordered_map<int , int> em[MAX_N];
priority_queue<pii , vector<pii> , greater<pii> > s;
vector<piii> edge;
int jad[MAX_N][20] , rmq[MAX_N][20] , dis[MAX_N] , ds[MAX_N] , dep = 0;
bool mark[MAX_N];

int dsu(int v){
	return ds[v] = (v == ds[v] ? v : dsu(ds[v]));
}

void unite(int v , int u){
	ds[dsu(u)] = dsu(v);
	return;
}

void DFS(int r , int par){
	dis[r] = dep++;
	if(~par) rmq[r][0] = em[r][par];
	jad[r][0] = par;
	int t = 20;
	for(int i = 1 ; i < 20 ; i++){
		if(!~jad[r][i - 1]){
			t = i;
			break;
		}
		jad[r][i] = jad[jad[r][i - 1]][i - 1];
		rmq[r][i] = max(rmq[r][i - 1] , rmq[jad[r][i - 1]][i - 1]);
	}
	for(int i = t ; i < 20 ; i++){
		rmq[r][i] = rmq[r][i - 1];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	dep--;
	return;
}

pii find_jad(int v , int d){
	d = dis[v] - d;
	int h = 1 << 19 , o = -1;
	for(int i = 19 ; i >= 0 ; i--){
		if(d >= h){
			d -= h;
			o = max(o , rmq[v][i]);
			v = jad[v][i];
		}
		h /= 2;
	}
	return {v , o};
}

int LCA(int v , int u){
	int o = -1;
	if(dis[v] > dis[u]){
		pii p = find_jad(v , dis[u]);
		v = p.first;
		o = p.second;
	}
	if(dis[v] < dis[u]){
		pii p = find_jad(u , dis[v]);
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
	
	int n , m , ans = 0;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		int v , u , w;
		cin>>v>>u>>w; v--; u--;
		edge.push_back({v , u , w});
		s.push({w , i});
	}
	iota(ds , ds + n , 0);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 20 ; j++){
			rmq[i][j] = -1;
			jad[i][j] = -1;
		}
		mark[i] = false;
	}
	while(s.size()){
		pii p = s.top(); s.pop();
		int v , u , w;
		v = edge[p.second].first; u = edge[p.second].second; w = p.first;
		if(dsu(v) == dsu(u)) continue;
		unite(v , u);
		mark[p.second] = true;
		adj[v].push_back(u); adj[u].push_back(v);
		em[u][v] = w; em[v][u] = w;
	}
	DFS(0 , -1);
	for(int i = 0 ; i < m ; i++){
		if(mark[i]) continue;
		int o = LCA(edge[i].first , edge[i].second);
		if(o == edge[i].third){
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}