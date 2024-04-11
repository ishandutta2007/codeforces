#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

const ll MAX_N = 2e5 + 20;

vector<pll> adj[MAX_N];
ll dp[MAX_N][20] , a[MAX_N][20] , z[MAX_N] , d = 0 , dis[MAX_N];
vector<ll> v;

void DFS(ll r){
	dis[r] = d++;
	for(int j = 1 ; j < 20 ; j++){
		if(a[r][j - 1] == -1){
			break;
		}
		a[r][j] = a[a[r][j - 1]][j - 1];
		dp[r][j] = dp[a[r][j - 1]][j - 1] + dp[r][j - 1];
	}
	for(auto p : adj[r]){
		ll i = p.first , u = p.second;
		if(i != a[r][0]){
			a[i][0] = r;
			if(u == r){
				dp[i][0]++;
				z[r]++;
			}
			DFS(i);
		}
	}
	for(auto p : adj[r]){
		ll i = p.first;
		if(i != a[r][0]){
			z[r] += z[i];
		}
	}
	d--;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m = 1e18 , c = 0;
	cin>>n;
	for(int i = 1 ; i < n ; i++){
		ll u , v;
		cin>>u>>v; u--; v--;
		adj[u].push_back( {v , v} ); adj[v].push_back( {u , v} );
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 20 ; j++){
			a[i][j] = -1;
			dp[i][j] = 0;
		}
		z[i] = 0;
	}
	DFS(0);
//	for(int i = 0 ; i < n ; i++){
//		cout<<dis[i]<<" ";
//	}
//	cout<<"\n";
	for(int i = 0 ; i < n ; i++){
		ll u = i , ans = 0 , q = 0;
		for(int j = 19 ; j >= 0 ; j--){
			if(a[u][j] > -1){
				q += dp[u][j];
				u = a[u][j];
			}
		}
		ans = z[0] + dis[i] - 2 * q;
		if(ans < m){
			m = ans;
			v.clear();
			v.push_back(i + 1);
		} else if(ans == m){
			v.push_back(i + 1);
		}
	}
	cout<<m<<"\n";
	for(auto i : v){
		cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}