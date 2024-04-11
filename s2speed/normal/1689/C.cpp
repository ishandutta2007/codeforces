#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> adj[maxn];
ll z[maxn] , dp[maxn];

void DFS(ll r , ll par){
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
		z[r] += z[i];
	}
	if(z[r] == 1){
		dp[r] = 0;
		return;
	}
	if(sze(adj[r]) + (par == -1) == 2){
		dp[r] = z[r] - 2;
		return;
	}
	ll v = -1 , u = -1;
	for(auto i : adj[r]){
		if(i == par) continue;
		if(v == -1){
			v = i;
			continue;
		}
		u = i;
		break;
	}
	dp[r] = max(z[v] - 1 + dp[u] , z[u] - 1 + dp[v]);
	return;
}

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) adj[i].clear();
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	cout<<dp[0]<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}