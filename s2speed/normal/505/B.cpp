#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 110;

ll cnt[MAX_N][MAX_N];
vector<ll> adj[MAX_N][MAX_N] , v;
bool mark[MAX_N];

void DFS(ll r , ll c){
	v.push_back(r);
	mark[r] = true;
	for(auto u : adj[c][r]){
		if(!mark[u]){
			DFS(u , c);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cnt[i][j] = 0;
		}
	}
	for(int i = 0 ; i < m ; i++){
		ll u , s , c;
		cin>>u>>s>>c;
		u--;
		s--;
		c--;
		adj[c][u].push_back(s); adj[c][s].push_back(u);
	}
	for(int c = 0 ; c < m ; c++){
		for(int j = 0 ; j < n ; j++){
			mark[j] = false;
		}
		for(int i = 0 ; i < n ; i++){
			if(!mark[i]){
				DFS(i , c);
				int vs = v.size();
				for(int j = 0 ; j < vs ; j++){
					for(int q = 0 ; q < vs ; q++){
						cnt[v[j]][v[q]]++;
					}
				}
				v.clear();
			}
		}
	}
	ll q;
	cin>>q;
	while(q--){
		ll u , s;
		cin>>u>>s;
		u--;
		s--;
		cout<<cnt[u][s]<<"\n";
	}
	return 0;
}