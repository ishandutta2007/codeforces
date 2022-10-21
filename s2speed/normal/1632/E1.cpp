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

const ll maxn = 3e3 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

ll n;
vector<ll> adj[maxn] , del[maxn];
bitset<maxn> dead;
ll x[maxn] , dis[maxn][maxn] , dep = 0 , ans[maxn];
vector<pll> cl[maxn];

void dDFS(ll r , ll par , ll v){
	dis[r][v] = dep++;
	for(auto i : adj[r]){
		if(i == par) continue;
		dDFS(i , r , v);
	}
	dep--;
	return;
}

bool check(ll k , ll y){
	ll res = inf;
	for(ll i = 0 ; i < n ; i++){
		while(dead[cl[i][x[i]].second]) x[i]++;
		res = min(res , cl[i][x[i]].first);
	}
	return (res + y <= k);
}

void solve(){
	cin>>n;
	for(ll i = 0 ; i <= n ; i++){
		adj[i].clear(); del[i].clear(); cl[i].clear();
		x[i] = 0;
		dead[i] = false;
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(ll i = 0 ; i < n ; i++){
		dDFS(i , -1 , i);
		del[dis[0][i]].push_back(i);
		for(ll j = 0 ; j < n ; j++){
			cl[i].push_back({dis[j][i] , j});
		}
		sort(all(cl[i]) , greater<pll>()); cl[i].push_back({-inf , n});
	}
	ll cur = -1;
	for(ll i = 1 ; i <= n ; i++){
		while(!check(cur , i)){
			cur++;
			for(auto j : del[cur]) dead[j] = true;
		}
		cout<<cur<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}