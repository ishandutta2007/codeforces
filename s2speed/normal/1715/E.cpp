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

const ll maxn = 1e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll n , m , k;
vector<pll> adj[maxn];
ll dp[maxn] , pd[maxn];
priority_queue<pll , vector<pll> , greater<pll>> pq;

void dij(){
	for(ll i = 0 ; i < n ; i++){
		pq.push({dp[i] , i});
	}
	while(!pq.empty()){
		pll q = pq.top(); pq.pop();
		ll v = q.second;
		if(q.first != dp[v]) continue;
		for(auto p : adj[v]){
			ll i = p.first , w = p.second;
			if(dp[i] > dp[v] + w){
				dp[i] = dp[v] + w;
				pq.push({dp[i] , i});
			}
		}
	}
	return;
}

void upd(ll l , ll r , ll opl , ll opr){
	if(l >= r) return;
	ll m = (r + l) >> 1;
	ll res = inf , opt = -1;
	for(ll i = opl ; i <= opr ; i++){
		ll h = dp[i] + (i - m) * (i - m);
		if(h < res){
			res = h;
			opt = i;
		}
	}
	pd[m] = res;
	upd(l , m , opl , opt); upd(m + 1 , r , opt , opr);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m>>k;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		adj[v].push_back({u , w}); adj[u].push_back({v , w});
	}
	memset(dp , 63 , sizeof(dp));
	dp[0] = 0;
	for(ll j = 0 ; j < k ; j++){
		dij();
		upd(0 , n , 0 , n - 1);
		memcpy(dp , pd , sizeof(dp));
	}
	dij();
	for(ll i = 0 ; i < n ; i++){
		cout<<dp[i]<<' ';
	}
	cout<<'\n';
	return 0;
}