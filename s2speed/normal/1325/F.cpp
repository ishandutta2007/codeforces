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
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 15 , md = 1e9 + 7;
ll inf;

ll dis[maxn] , dep = 0 , par[maxn] , ha[maxn] , hz[maxn] , cyc = -1 , sq;
vector<ll> adj[maxn] , cdj[maxn] , is;
bitset<maxn> mark , ans;

void pDFS(ll r){
	mark[r] = true;
	dis[r] = dep++;
	for(auto i : adj[r]){
		if(mark[i]){
			ha[r] = min(ha[r] , dis[i]);
			continue;
		}
		par[i] = r;
		cdj[r].push_back(i);
		pDFS(i);
	}
	dep--;
	return;
}

void iDFS(ll r){
	for(auto i : cdj[r]){
		iDFS(i);
		if(cyc != -1) return;
		hz[r] = min(hz[r] , hz[i]);
	}
	if(hz[r] > dis[r]){
		if(dis[r] - ha[r] >= sq){
			cyc = r;
			return;
		}
		is.push_back(r);
		hz[r] = min(hz[r] , ha[r]);
	}
	return;
}

int main(){ // check maxn
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(ha , 63 , sizeof(ha));
	memset(hz , 63 , sizeof(hz));
	inf = ha[0];
	ll n , m;
	cin>>n>>m; sq = ceil(sqrt(n)) - 1;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	par[0] = -1;
	pDFS(0); iDFS(0); par[0] = n; dis[n] = -1;
	if(cyc != -1){
		cout<<"2\n";
		ll v = cyc;
		cout<<dis[v] - ha[v] + 1<<'\n';
		while(dis[v] >= ha[cyc]){
			cout<<v + 1<<' ';
			v = par[v];
		}
		cout<<'\n';
		return 0;
	}
	cout<<"1\n";
	for(ll j = 0 ; j <= sq ; j++){
		cout<<is[j] + 1<<' ';
	}
	cout<<'\n';
	return 0;
}