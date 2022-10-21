#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 2e5 + 17 , maxk = 1 << 30 , md = 1e9 + 7 , inf = 2e16;

bitset<maxk> g;
vector<int> v[maxn] , adj[maxn];
int a[maxn] , dis[maxn] , z[maxn] , hc[maxn];

void pDFS(int r , int par){
	int m = -1 , ind = -1;
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		dis[i] = dis[r] ^ a[i];
		pDFS(i , r);
		z[r] += z[i];
		if(z[i] > m){
			m = z[i]; ind = i;
		}
	}
	hc[r] = ind;
	return;
}

int res = 0;

void gDFS(int r , int par){
	if(hc[r] == -1){
		g[dis[r]] = true;
		v[r].push_back(r);
		return;
	}
	for(auto i : adj[r]){
		if(i == par || i == hc[r]) continue;
		gDFS(i , r);
		for(auto j : v[i]){
			g[dis[j]] = false;
		}
	}
	gDFS(hc[r] , r);
	v[r].swap(v[hc[r]]);
	bool f = false;
	for(auto i : adj[r]){
		if(i == par || i == hc[r]) continue;
		for(auto j : v[i]){
			f |= g[dis[j] ^ a[r]];
		}
		for(auto j : v[i]){
			v[r].push_back(j);
			g[dis[j]] = true;
		}
		v[i].clear(); v[i].shrink_to_fit();
	}
	f |= g[dis[r] ^ a[r]];
	g[dis[r]] = true;
	v[r].push_back(r);
	if(f){
		res++;
		for(auto j : v[r]){
			g[dis[j]] = false;
		}
		v[r].clear(); v[r].shrink_to_fit();
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	dis[0] = a[0];
	pDFS(0 , -1);
	gDFS(0 , -1);
	cout<<res<<'\n';
	return 0;
}