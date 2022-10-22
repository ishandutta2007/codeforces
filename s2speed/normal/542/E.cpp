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

const ll MAXN = 1e3 + 15 , md = 1e9 + 7 , inf = 1e10;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll dis[MAXN];
vector<ll> adj[MAXN] , bfs , c;
vector< vector<ll> > com;
bitset<MAXN> mark;
bool f = false;

void BFS(ll r){
	memset(dis , 63 , sizeof(dis)); bfs.clear(); c.clear();
	dis[r] = 0;
	bfs.push_back(r);
	ll x = 0;
	while(x < bfs.size()){
		ll v = bfs[x++];
		mark[v] = true;
		c.push_back(v);
		for(auto i : adj[v]){
			if(dis[i] > dis[v] + 1){
				dis[i] = dis[v] + 1;
				bfs.push_back(i);
			} else {
				if(dis[i] == dis[v]) f = true;
			}
		}
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		BFS(i);
		com.push_back(c);
	}
	if(f){
		cout<<"-1\n";
		return 0;
	}
	ll ans = 0;
	for(auto q : com){
		ll o = 0;
		for(auto i : q){
			BFS(i);
			o = max(o , dis[bfs.back()]);
		}
		ans += o;
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/