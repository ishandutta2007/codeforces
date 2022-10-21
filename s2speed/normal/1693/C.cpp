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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> adj[maxn];
ll dp[maxn] , d[maxn];
priority_queue<pll , vector<pll> , greater<pll>> pq;

void dij(ll r){
	dp[r] = 0;
	pq.push({0 , r});
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(p.first != dp[v]) continue;
		for(auto i : adj[v]){
			if(dp[v] + d[i] < dp[i]){
				dp[i] = dp[v] + d[i];
				pq.push({dp[i] , i});
			}
			d[i]--;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[u].push_back(v);
		d[v]++;
	}
	dij(n - 1);
	cout<<dp[0]<<'\n';
	return 0;
} // maxne lanati ro check kon