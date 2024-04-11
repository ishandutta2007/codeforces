#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 500 + 20;
 
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

vector<int> adj[MAX_N];
int dis[MAX_N][MAX_N] , cnt[MAX_N][MAX_N] , ans[MAX_N][MAX_N] , e[MAX_N][MAX_N];
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			dis[i][j] = 6e8 * (i != j);
			e[i][j] = 6e8;
			cnt[i][j] = 0;
			ans[i][j] = 0;
		}
	}
	for(int i = 0 ; i < m ; i++){
		ll u , v , w;
		cin>>v>>u>>w; u--; v--;
		dis[u][v] = w;
		dis[v][u] = w;
		e[u][v] = w;
		e[v][u] = w;
	}
	for(int k = 0 ; k < n ; k++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				if(dis[i][j] == dis[i][k] + e[k][j]){
					cnt[i][j]++;
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				if(dis[i][j] == dis[i][k] + dis[k][j]){
					ans[i][j] += cnt[i][k];
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			if(dis[i][j] >= 6e8){
				cout<<"0 ";
			} else {
				cout<<ans[i][j]<<' ';
			}
		}
	}
	cout<<'\n';
	return 0;
}