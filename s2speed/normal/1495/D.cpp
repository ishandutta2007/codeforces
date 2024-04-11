#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 4e2 + 16 , md = 998244353 , inf = 2e16;

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
vector<ll> adj[maxn] , bfs;
ll dis[maxn][maxn] , ans[maxn][maxn] , t[maxn];

void BFS(ll r){
	bfs.clear();
	dis[r][r] = 0;
	bfs.push_back(r);
	ll x = 0;
	while(x < sze(bfs)){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(dis[i][r] > dis[v][r] + 1){
				dis[i][r] = dis[v][r] + 1;
				bfs.push_back(i);
			}
		}
	}
	return;
}

ll f(ll a , ll b){
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		if(dis[i][a] + dis[i][b] == dis[a][b]){
			cnt++;
		}
	}
	if(cnt > dis[a][b] + 1) return 0;
	for(ll i = 0 ; i < n ; i++){
		ll h = dis[i][a] + dis[i][b] , j;
		if((h ^ dis[a][b]) & 1) return 0;
		t[i] = dis[i][a] - (h - dis[a][b]) / 2;
	}
	ll res = 1;
	for(ll i = 0 ; i < n ; i++){
		if(t[i] == dis[i][a]) continue;
		ll cnt = 0;
		for(auto v : adj[i]){
			if(t[v] == t[i] && dis[i][a] == dis[v][a] + 1) cnt++;
		}
		res *= cnt; res %= md;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(ll i = 0 ; i < n ; i++) BFS(i);
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i ; j < n ; j++){
			ans[i][j] = ans[j][i] = f(i , j);
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}