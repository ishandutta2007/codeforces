#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<db , pair<db , db>> pddd;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e17;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

ll n , m;
vector<ll> adj[maxn] , jda[maxn];
vector<pll> y;
vector<plll> ed;
bitset<maxn> mark[2] , imp;
ll dis[maxn];
bool nc = false;

void aDFS(ll r){
	mark[0][r] = true;
	for(auto i : adj[r]){
		if(mark[0][i]) continue;
		aDFS(i);
	}
	return;
}

void bDFS(ll r){
	mark[1][r] = true;
	for(auto i : jda[r]){
		if(mark[1][i]) continue;
		bDFS(i);
	}
	return;
}

void bellmanford(){
	memset(dis , 63 , sizeof(dis));
	dis[n] = 0;
	for(ll i = 0 ; i < n ; i++){
		for(auto q : ed){
			ll v = q.first.first , u = q.first.second , w = q.second;
			dis[u] = min(dis[u] , dis[v] + w);
		}
	}
	for(auto q : ed){
		ll v = q.first.first , u = q.first.second , w = q.second;
		nc |= (dis[u] > dis[v] + w);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		y.push_back({v , u});
		adj[v].push_back(u); jda[u].push_back(v);
	}
	aDFS(0); bDFS(n - 1);
	imp = mark[0] & mark[1];
	for(ll i = 0 ; i < n ; i++){
		if(!imp[i]) continue;
		ed.push_back({{n , i} , 0});
		for(auto j : adj[i]){
			if(!imp[j]) continue;
			ed.push_back({{j , i} , -1});
			ed.push_back({{i , j} , 2});
		}
	}
	bellmanford();
	if(nc){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	for(auto p : y){
		ll v = p.first , u = p.second;
		if(!(imp[v] & imp[u])){
			cout<<"1\n";
			continue;
		}
		cout<<dis[u] - dis[v]<<'\n';
	}
	return 0;
}