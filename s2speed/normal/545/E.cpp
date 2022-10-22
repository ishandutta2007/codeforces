#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<ll , pll> plll;
typedef pair<int , int> pii;
typedef long double db;
struct piii {
	int first , second , third;
};

const ll MAXN = 3e5 + 20 , md = 1e9 + 7 , inf = 1e9;
// check problem statement

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

map<pll , ll> ed;
vector<plll> es;
vector<pll> adj[MAXN] , st , tree;
priority_queue<pll , vector<pll> , greater<pll> > pq;
ll dis[MAXN];
bool mark[MAXN];

void dij(ll r){
	dis[r] = 0;
	pq.push({0 , r});
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(mark[v]) continue;
		for(auto q : adj[v]){
			ll i = q.second , w = q.first;
			if(dis[i] > dis[v] + w){
				dis[i] = dis[v] + w;
				pq.push({dis[i] , i});
			}
		}
		mark[v] = true;
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , ans = 0;
	cin>>n>>m;
	memset(dis , 63 , sizeof(dis));
	memset(mark , 0 , sizeof(mark));
	for(int i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back({w , u}); adj[u].push_back({w , v});
		ed[{u , v}] = i + 1; ed[{v , u}] = i + 1;
	}
	ll r;
	cin>>r; r--;
	dij(r);
	for(int i = 0 ; i < n ; i++){
		st.push_back({dis[i] , i});
		ll as = adj[i].size();
		for(int j = 0 ; j < as ; j++){
			es.push_back({dis[adj[i][j].second] , adj[i][j]});
		}
		adj[i].clear();
		sort(all(es) , greater<plll>());
		for(int j = 0 ; j < as ; j++){
			adj[i].push_back(es[j].second);
		}
		es.clear();
	}
	sort(all(st));
	for(int i = 1 ; i < n ; i++){
		ll v = st[i].second , as = adj[v].size();
		for(int j = 0 ; j < as ; j++){
			ll u = adj[v][j].second , w = adj[v][j].first;
			if(dis[u] + w == dis[v]){
				ans += w;
				tree.push_back({v , u});
				break;
			}
		}
	}
	cout<<ans<<'\n';
	for(int i = 0 ; i < n - 1 ; i++){
		cout<<ed[tree[i]]<<' ';
	}
	cout<<'\n';
	return 0;
}

/*
4 4
1 2 1
1 3 2
2 3 1
2 4 1
1
*/