#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 5e5 + 15 , md = 1e9 + 7 , inf = 1e18;

vector<ll> adj[MAXN] , v;
ll ans = 0 , dep = 0;

void DFS(ll r , ll par){
	dep++;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	if(adj[r].size() == 1){
		v.push_back(dep);
	}
	dep--;
	if(par != 0) return;
	ll h = 0;
	sort(all(v));
	for(auto i : v){
		h = (i > h ? i : h + 1);
	}
	v.clear();
	ans = max(ans , h);
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(auto i : adj[0]){
		DFS(i , 0);
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/