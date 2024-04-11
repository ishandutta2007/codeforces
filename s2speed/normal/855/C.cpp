#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 1e5 + 20 , md = 1e9 + 7;

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

vector<ll> adj[MAX_N];
ll dp[MAX_N][12][6] , n , m , x , k , h[12][3];

void DFS(ll r , ll par){
	for(auto u : adj[r]){
		if(u != par){
			DFS(u , r);
		}
	}
	for(int i = 0 ; i <= x ; i++){
		dp[r][i][0] = (i == 0);
		dp[r][i][1] = 0;
		dp[r][i][2] = (i == 1);
		dp[r][i][3] = (m - 1) * (i == 0);
		dp[r][i][4] = 0;
		dp[r][i][5] = (i == 0) * (k - 1);
	}
	for(int i = 0 ; i < 12 ; i++){
		h[i][0] = 0;
		h[i][1] = 0;
		h[i][2] = 0;
	}
	for(auto u : adj[r]){
		if(u == par){
			continue;
		}
		for(int i = 0 ; i <= x ; i++){
			for(int j = 0 ; j <= x ; j++){
				if(i + j > x){
					continue;
				}
				ll z;
				z = 1ll * dp[r][i][2] * dp[u][j][5] % md;
				h[i + j][2] += z;
				z = 1ll * dp[r][i][0] * (dp[u][j][3] + dp[u][j][4]) % md;
				h[i + j][0] += z;
				z = 1ll * dp[r][i][0] * dp[u][j][2] % md;
				h[i + j][1] += z;
				z = 1ll * dp[r][i][1] * (dp[u][j][3] + dp[u][j][4] + dp[u][j][2]) % md;
				h[i + j][1] += z;
			}
		}
		for(int i = 0 ; i <= x ; i++){
			for(int j = 0 ; j < 3 ; j++){
				h[i][j] %= md;
				dp[r][i][j] = h[i][j];
				h[i][j] = 0;
			}
			dp[r][i][3] = 1ll * dp[r][i][0] * (m - 1) % md;
			dp[r][i][4] = 1ll * dp[r][i][1] * (k - 1) % md;
			dp[r][i][5] = 1ll * (dp[r][i][0] + dp[r][i][1]) * (k - 1) % md;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i = 1 ; i < n ; i++){
		ll u , v;
		cin>>u>>v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	cin>>k>>x;
	DFS(0 , -1);
	ll ans = 0;
	for(int i = 0 ; i <= x ; i++){
		ans += dp[0][i][2];
		ans += dp[0][i][3];
		ans += dp[0][i][4];
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}

/*
4 3
1 2
1 3
1 4
2 2
*/