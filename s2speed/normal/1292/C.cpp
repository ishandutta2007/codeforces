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

const ll MAXN = 3e3 + 15 , md = 998244353 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

vector<ll> adj[MAXN] , bfs;
ll jad[MAXN][12] , dis[MAXN][MAXN] , dep = 0 , z[MAXN];

void DFS(ll r , ll par){
	dis[0][r] = dep++;
	jad[r][0] = par;
	for(ll j = 1 ; j < 12 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
		z[r] += z[i];
	}
	dep--;
	return;
}

void BFS(ll r){
	bfs.clear();
	dis[r][r] = 0;
	bfs.push_back(r);
	ll x = 0;
	while(x < bfs.size()){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(dis[r][i] > dis[r][v] + 1){
				dis[r][i] = dis[r][v] + 1;
				bfs.push_back(i);
			}
		}
	}
	return;
}

ll find_jad(ll v , ll h){
	h = dis[0][v] - h;
	for(ll j = 0 ; j < 12 ; j++){
		if(h & 1){
			v = jad[v][j];
		}
		h >>= 1;
	}
	return v;
}

ll LCA(ll v , ll u){
	if(dis[0][v] > dis[0][u]){
		v = find_jad(v , dis[0][u]);
	} else {
		u = find_jad(u , dis[0][v]);
	}
	if(v == u) return v;
	for(ll j = 11 ; j >= 0 ; j--){
		if(jad[v][j] != jad[u][j]){
			v = jad[v][j];
			u = jad[u][j];
		}
	}
	return jad[v][0];
}

bool cmp(pll a , pll b){
	return (dis[a.first][a.second] < dis[b.first][b.second]);
}

vector<pll> v;
ll dp[MAXN][MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	memset(jad , -1 , sizeof(jad));
	memset(dp , 0 , sizeof(dp));
	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	for(ll i = 1 ; i < n ; i++){
		BFS(i);
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i ; j < n ; j++){
			v.push_back({i , j});
		}
	}
	sort(all(v) , cmp);
	ll ans = 0;
	for(auto p : v){
		ll a = p.first , b = p.second , c = LCA(a , b) , d , e , h;
		if(a == b) continue;
		if(dis[0][a] > dis[0][b]) swap(a , b);
		h = z[b];
		if(c == a){
			d = find_jad(b , dis[0][a] + 1);
			h *= n - z[d];
		} else {
			d = jad[a][0];
			h *= z[a];
		}
		e = jad[b][0];
		dp[a][b] = h;
		dp[a][b] += max(dp[b][d] , dp[a][e]);
		dp[b][a] = dp[a][b];
		ans = max(ans , dp[a][b]);
	}
	printf("%lld\n" , ans);
	return 0;
}

/*

*/