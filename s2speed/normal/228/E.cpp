#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll {ll first , second , third;};
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e2 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

vector<ll> adj[MAXN] , ans;
ll c[MAXN] , x = 0;

void DFS(ll r){
	c[r] = x;
	for(auto i : adj[r]){
		if(~c[i]) continue;
		DFS(i);
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , -1 , sizeof(c));
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		if(w){
			adj[v].push_back(u); adj[u].push_back(v);
			adj[v + n].push_back(u + n); adj[u + n].push_back(v + n);
		} else {
			adj[v].push_back(u + n); adj[u + n].push_back(v);
			adj[u].push_back(v + n); adj[v + n].push_back(u);
		}
	}
	for(ll i = 0 ; i < 2 * n ; i++){
		if(~c[i]) continue;
		DFS(i);
		x++;
	}
	for(ll i = 0 ; i < n ; i++){
		if(c[i] == c[i + n]){
			cout<<"Impossible\n";
			return 0;
		}
		if(c[i] < c[i + n]) ans.push_back(i + 1);
	}
	cout<<ans.size()<<'\n';
	for(auto i : ans){
		cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}

/*

*/