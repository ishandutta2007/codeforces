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

const ll maxn = 2e5 + 17 , md = 998244353 , inf = 2e16;

ll dp[maxn][3];
// 0 morde az avval 1 zendast bad mimire 2 zendast o zende mimoone
vector<pll> adj[maxn] , z;
ll ps[maxn] , sf[maxn];

void DFS(ll r , ll par , ll t){
	for(auto p : adj[r]){
		ll i = p.second;
		if(i == par) continue;
		DFS(i , r , p.first);
	}
	z.clear();
	for(auto p : adj[r]){
		ll i = p.second;
		if(i == par) continue;
		z.push_back(p);
	}
	ll sz = sze(z);
	if(sz == 0){
		dp[r][0] = dp[r][1] = dp[r][2] = 1;
		return;
	}
	ps[0] = dp[z[0].second][2];
	for(ll i = 1 ; i < sz ; i++){
		ll h = ps[i - 1] * dp[z[i].second][2] % md;
		ps[i] = h;
	}
	sf[sz] = 1;
	for(ll i = sz - 1 ; ~i ; i--){
		ll h = sf[i + 1] * dp[z[i].second][0] % md;
		sf[i] = h;
	}
	ll res = ps[sz - 1];
	for(ll i = 0 ; i < sz ; i++){
		ll h = dp[z[i].second][1] * (i ? ps[i - 1] : 1) % md * sf[i + 1] % md;
		res += h;
	}
	dp[r][0] = res % md;
	if(par == -1) return;
	res = ps[sz - 1];
	ll j = lower_bound(all(z) , mp(t , -1ll)) - z.begin();
	for(ll i = j ; i < sz ; i++){
		ll h = dp[z[i].second][1] * (i ? ps[i - 1] : 1) % md * sf[i + 1] % md;
		res += h;
	}
	dp[r][1] = res % md;
	res = (j ? ps[j - 1] : 1) * sf[j] % md;
	for(ll i = 0 ; i < j ; i++){
		ll h = dp[z[i].second][1] * (i ? ps[i - 1] : 1) % md * sf[i + 1] % md;
		res += h;
	}
	dp[r][2] = res % md;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back({i , u}); adj[u].push_back({i , v});
	}
	DFS(0 , -1 , -1);
	cout<<dp[0][0]<<'\n';
	return 0;
}