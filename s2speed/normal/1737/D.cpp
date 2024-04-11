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

const ll maxn = 5e2 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> adj[maxn] , v;
vector<plll> ed;
ll dis[maxn][maxn] , par[maxn][2] , cnt[maxn][2];

void solve(){
	ll n , m;
	cin>>n>>m;
	ed.clear();
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear(); par[i][0] = par[i][1] = -1; cnt[i][0] = cnt[i][1] = 0;
		for(ll j = 0 ; j < n ; j++) dis[i][j] = inf;
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		ed.push_back({{v , u} , w});
	}
	for(auto q : ed){
		pll p = q.first;
		ll v = p.first , u = p.second;
//		if(!f[v] || !f[u]) continue;
		dis[v][u] = dis[u][v] = 1;
	}
	for(ll i = 0 ; i < n ; i++) dis[i][i] = 0;
	for(ll k = 0 ; k < n ; k++){
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < n ; j++){
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(auto j : adj[i]){
			if(dis[j][0] < dis[i][0]){
				cnt[i][0]++;
				par[i][0] = j;
			}
			if(dis[j][n - 1] < dis[i][n - 1]){
				cnt[i][1]++;
				par[i][1] = j;
			}
		}
	}
	ll ans = inf;
	for(auto q : ed){
		pll p = q.first;
		ll v = p.first , u = p.second , w = q.second;
		ll h = inf;
		for(ll i = 0 ; i < n ; i++){
			h = min(h , dis[i][0] + dis[i][n - 1] + max(dis[i][v] , dis[i][u]));
		}
		ans = min(ans , (h + 1) * w);
		h = dis[0][v] + dis[u][n - 1] + 1;
		if((par[u][1] == v && cnt[u][1] == 1) || (par[v][0] == u && cnt[v][0] == 1)){
		} else {
			ans = min(ans , h * w);
		}
		h = dis[0][u] + dis[v][n - 1] + 1;
		if((par[u][0] == v && cnt[u][0] == 1) || (par[v][1] == u && cnt[v][1] == 1)){
		} else {
			ans = min(ans , h * w);
		}
	}
	cout<<ans<<'\n';
	return;
}

/*
1
4 5
1 2 1
2 4 1
3 4 1
3 1 1
1 3 2
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}