#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2e5 + 20;
 
int tav(ll n , ll k){
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

vector<pll> q;
vector<ll> adj[MAX_N];
ll d[MAX_N] , gosh = 0 , k = 0 , dis[MAX_N] , dep = 0;
bool mark[MAX_N];

void DFS(ll r , ll par){
	dis[r] = dep++;
	for(auto u : adj[r]){
		if(u != par){
			DFS(u , r);
		}
	}
	q.clear();
	if(adj[r].size() == 1 && par != -1){
		d[r] = dis[r];
	} else {
		d[r] = 1e6;
	}
	for(auto u : adj[r]){
		if(u == par){
			continue;
		}
		d[r] = min(d[r] , d[u]);
		q.push_back( {d[u] , u} );
	}
	sort(q.begin() , q.end() , greater<pll>() );
	ll x = 0 , y = 0 , qs = q.size();
	for(int y = 0 ; y < qs ; y++ , x++){
		if(adj[r][x] == par){
			x++;
		}
		adj[r][x] = q[y].second;
	}
	dep--;
	if(r == 0){
		adj[0].push_back(adj[0][0]);
		adj[0].erase(adj[0].begin());
	}
}

void DFS1(ll r , ll par){
	gosh++;
	k = max(gosh , k);
	gosh = 0;
	mark[r] = false;
	for(auto u : adj[r]){
		if(u != par){
			DFS1(u , r);
			gosh++;
			k = max(k , gosh);
		}
	}
}

/*
1
9
1 2
2 3
3 4
3 5
3 6
2 7
7 8
8 9
*/

void solve(){
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		mark[i] = true;
		adj[i].clear();
	}
	gosh = 0;
	k = 0;
	for(int i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	DFS1(0 , -1);
	cout<<k<<'\n';
	return;
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}