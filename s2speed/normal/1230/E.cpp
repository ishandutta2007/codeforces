#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	return ((b == 0) ? a : gcd(b , a % b));
}

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 1e18;

vector<ll> adj[MAXN];
ll a[MAXN] , dis[MAXN] , dep = 0;
vector<ll> o[MAXN] , v , d , g;
ll ans = 0;
set<ll> s[MAXN];

void DFS(ll r , ll par){
	if(par != -1){
		o[r] = o[par];
		s[r] = s[par];
	}
	dis[r] = dep++;
	s[r].insert(dis[r]);
	auto et = s[r].end();
	v.clear(); d.clear(); g.clear();
	for(auto it = s[r].begin() ; it != et ; it++){
		v.push_back(*it);
	}
	ll vs = v.size();
	o[r].push_back(a[r]);
	for(ll i = 0 ; i < vs - 1 ; i++){
		o[r][i] = gcd(o[r][i] , a[r]);
	}
	g.push_back(o[r][0]);
	for(ll e = 1 ; e < vs ; e++){
		if(o[r][e] == o[r][e - 1]){
			d.push_back(v[e]);
		} else {
			g.push_back(o[r][e]);
		}
	}
	for(auto j : d){
		s[r].erase(j);
	}
	for(ll e = 0 ; e < vs - 1 ; e++){
		ans += 1ll * (v[e + 1] - v[e]) * o[r][e]; ans %= md;
	}
	o[r] = g;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	s[r].erase(dis[r]);
	dep--;
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(o , 0 , sizeof(o));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		ans += a[i];
	}
	ans %= md;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	cout<<ans<<'\n';
	return 0;
}

/*

*/