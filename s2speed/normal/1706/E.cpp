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

const ll maxn = 3e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll ds[maxn];
vector<ll> adj[maxn];
ll jad[maxn][20] , t[maxn] , o , dis[maxn] , dep = 0;

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u , ll k){
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	adj[o].push_back(v); adj[o].push_back(u);
	t[o] = k;
	ds[v] = o; ds[u] = o;
	o++;
	return;
}

void dDFS(ll r){
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	dis[r] = dep++;
	for(auto i : adj[r]){
		jad[i][0] = r;
		dDFS(i);
	}
	dep--;
	return;
}

ll find_jad(ll v , ll d){
	d = dis[v] - d;
	for(ll j = 0 ; j < 20 ; j++){
		if(d & (1 << j)){
			v = jad[v][j];
		}
	}
	return v;
}

ll lca(ll v , ll u){
	if(dis[v] > dis[u]) swap(v , u);
	u = find_jad(u , dis[v]);
	if(v == u) return v;
	for(ll j = 19 ; ~j ; j--){
		if(jad[v][j] != jad[u][j]){
			v = jad[v][j];
			u = jad[u][j];
		}
	}
	return jad[v][0];
}

ll a[maxn] , rmq[maxn][20] , rb[maxn];

void solve(){
	ll n , m , q;
	cin>>n>>m>>q; o = n;
	for(ll i = 0 ; i < n + n ; i++){
		adj[i].clear();
		for(ll j = 0 ; j < 20 ; j++) jad[i][j] = -1;
	}
	iota(ds , ds + 2 * n , 0);
	for(ll i = 1 ; i <= m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		merge(v , u , i);
	}
	dDFS(2 * n - 2);
	for(ll i = 0 ; i < n - 1 ; i++){
		rmq[i][0] = a[i] = t[lca(i , i + 1)];
	}
	ll lm = n - 1;
	for(ll j = 1 ; j < 20 ; j++){
		ll z = 1 << (j - 1);
		if(z >= lm) break;
		for(ll i = 0 ; i < lm - z ; i++){
			rmq[i][j] = max(rmq[i][j - 1] , rmq[i + z][j - 1]);
		}
		for(ll i = lm - z ; i < lm ; i++) rmq[i][j] = rmq[i][j - 1];
	}
	for(ll e = 0 ; e < q ; e++){
		ll l , r;
		cin>>l>>r; l--; r--;
		if(l == r){
			cout<<"0 ";
			continue;
		}
		ll res = max(rmq[l][rb[r - l]] , rmq[r - (1 << rb[r - l])][rb[r - l]]);
		cout<<res<<' ';
	}
	cout<<'\n';
	return;
}

/*
1
5 5 5
1 2
1 3
2 4
3 4
3 5
1 4
3 4
2 2
2 5
3 5
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	rb[1] = 0;
	ll h = 2;
	for(ll i = 2 ; i < maxn ; i++){
		rb[i] = rb[i - 1];
		if(h == i){
			rb[i]++;
			h <<= 1;
		}
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}