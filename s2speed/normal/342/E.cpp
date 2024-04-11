#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7 , inf = 1e9;
 
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

vector<int> adj[MAX_N] , comp;
int ds[MAX_N][20] , mdis[MAX_N] , dis[MAX_N] , cpar[MAX_N] , cdis[MAX_N] , z[MAX_N] , sz , cd = -1 , dep = 0;
bool mark[MAX_N] , dead[MAX_N];

void DFS(int r , int par){
	dis[r] = dep++;
	mark[r] = true;
	sz++;
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		DFS(i , r);
	}
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		z[r] += z[i];
	}
	dep--;
	return;
}

int find_centroid(int r , int par){
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		if(z[i] > sz / 2){
			return find_centroid(i , r);
		}
	}
	return r;
}

void DFS1(int r , int par){
	dis[r] = dep++;
	if(!dead[r]){
		cpar[r] = cd;
	}
	comp.push_back(r);
	for(auto i : adj[r]){
		if(i == par || dead[i]) continue;
		DFS1(i , r);
	}
	dep--;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , m;
	cin>>n>>m;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(int i = 0 ; i < n ; i++){
		dead[i] = false;
	}
	DFS1(0 , -1);
	for(int i = 0 ; i < n ; i++){
		mdis[i] = dis[i];
	}
	for(int i = 0 , cnt = 0 ; cnt < n ; i++){
		for(int j = 0 ; j < n ; j++){
			mark[j] = dead[j];
			dis[j] = inf;
		}
		for(int j = 0 ; j < n ; j++){
			if(mark[j]) continue;
			comp.clear();
			cnt++;
			sz = 0;
			DFS(j , -1);
			int h = find_centroid(j , -1);
			dead[h] = true;
			cdis[h] = i;
			cd = h;
			DFS1(h , -1);
			for(auto v : comp){
				ds[v][i] = dis[v];
			}
		}
	}
	while(m--){
		int op , v;
		cin>>op>>v; v--;
		if(op == 1){
			int x = v;
			for(int i = cdis[v] ; i >= 0 ; i--){
				mdis[x] = min(mdis[x] , ds[v][i]);
				x = cpar[x];
			}
		}
		if(op == 2){
			int x = v , ans = inf;
			for(int i = cdis[v] ; i >= 0 ; i--){
				ans = min(ans , mdis[x] + ds[v][i]);
				x = cpar[x];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}