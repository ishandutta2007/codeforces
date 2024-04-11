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

const ll maxn = 112 , md = 1e9 + 7 , inf = 2e16;

ll n , k;
ll dp[maxn][24][2];
vector<ll> adj[maxn];

void dDFS(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		dDFS(i , r);
	}
	for(ll j = 1 ; j <= k ; j++){
		ll h = 1;
		for(auto i : adj[r]){
			if(i == par) continue;
			ll o = dp[i][j][0] + dp[i][j + 1][0] + dp[i][j + 1][1];
			h *= o; h %= md;
		}
		dp[r][j][1] = h;
		h = 1;
		for(auto i : adj[r]){
			if(i == par) continue;
			ll o = dp[i][j][0] + dp[i][j + 1][0] + dp[i][j + 1][1] + dp[i][j - 1][0];
			h *= o; h %= md;
		}
		h -= dp[r][j][1]; h += (h < 0) * md;
		dp[r][j][0] = h;
	}
	ll h = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		ll o = dp[i][0][0] + dp[i][1][0] + dp[i][1][1];
		h *= o; h %= md;
	}
	dp[r][0][0] = h;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	dDFS(0 , -1);
	ll res = 0;
	for(ll j = 0 ; j <= k ; j++){
		res += dp[0][j][0];
	}
	res %= md;
	cout<<res<<'\n';
	return 0;
}