#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 5020;

vector<ll> adj[MAX_N] , v0 , v1;
ll dp[2][MAX_N][MAX_N] , par[MAX_N] , pd[MAX_N];
bool mark[MAX_N];

void DFS(ll r){
	mark[r] = true;
	for(auto u : adj[r]){
		if(!mark[u]){
			par[u] = r;
			DFS(u);
		}
	}
	pd[r] = (adj[r].size() == 1);
	dp[0][r][0] = 0;
	dp[1][r][(adj[r].size() == 1)] = 0;
	for(auto u : adj[r]){
		if(u == par[r]){
			continue;
		}
		v0.assign(pd[r] + pd[u] + 1 , 1e18);
		v1.assign(pd[r] + pd[u] + 1 , 1e18);
		for(int i = 0 ; i <= pd[r] ; i++){
			for(int j = 0 ; j <= pd[u] ; j++){
				for(int p = 0 ; p < 2 ; p++){
					v0[i + j] = min(v0[i + j] , dp[0][r][i] + dp[p][u][j] + p);
				}
				for(int p = 0 ; p < 2 ; p++){
					v1[i + j] = min(v1[i + j] , dp[1][r][i] + dp[p][u][j] + 1 - p);
				}
			}
		}
		pd[r] += pd[u];
		for(int i = 0 ; i <= pd[r] ; i++){
			dp[0][r][i] = v0[i];
			dp[1][r][i] = v1[i];
		}
		v0.clear();
		v1.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , r = 5019 , b = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ;j++){
			dp[0][i][j] = 1e18;
			dp[1][i][j] = 1e18;
		}
	}
	for(int i = 1 ; i < n ; i++){
		ll u , v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	if(n == 2){
		cout<<"2\n";
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		if(adj[i].size() > 1){
			r = i;
		} else {
			b++;
		}
		mark[i] = false;
	}
	par[r] = -1;
	DFS(r);
	ll ans = min(dp[0][r][b / 2] , dp[1][r][b / 2]);
	cout<<ans<<"\n";
	return 0;
}