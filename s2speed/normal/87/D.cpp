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

const ll MAXN = 1e6 + 15 , md = 1e9 + 7 , inf = 2e9;

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

ll ds[MAXN] , dsz[MAXN];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	dsz[v] += dsz[u]; dsz[u] = 0;
	ds[u] = v;
	return;
}

vector<ll> adj[MAXN] , inv , res;
vector<plll> temp;
vector<pllll> ed;
ll ans[MAXN] , z[MAXN], root , rt[MAXN] , dep = 0 , dis[MAXN];
bitset<MAXN> mark;

void DFS(ll r , ll par){
	dis[r] = dep++;
	mark[r] = true;
	rt[r] = root;
	z[r] = dsz[r];
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
		z[r] += z[i];
	}
	dep--;
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ed.push_back({{inf , 0} , {0 , 0}});
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n - 1 ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		ed.push_back({{w , i} , {v , u}});
	}
	iota(ds , ds + n , 0);
	fill(dsz , dsz + n , 1);
	sort(all(ed));
	ll e = ed[0].first.first;
	for(ll i = 0 ; i < n ; i++){
		if(ed[i].first.first == e){
			ll v = dsu(ed[i].second.first) , u = dsu(ed[i].second.second);
			temp.push_back({ed[i].first.second , {v , u}});
			inv.push_back(v); inv.push_back(u);
			adj[v].push_back(u); adj[u].push_back(v);
			continue;
		}
		e = ed[i].first.first;
		for(auto j : inv){
			if(mark[j]) continue;
			root = j;
			DFS(j , -1);
		}
		for(auto q : temp){
			ll v = q.second.first , u = q.second.second;
			merge(v , u);
			if(dis[v] < dis[u]) swap(v , u);
			ans[q.first] = 1ll * (z[rt[v]] - z[v]) * z[v];
		}
		for(auto j : inv){
			mark[j] = false;
			adj[j].clear();
		}
		temp.clear();
		inv.clear();
		i--;
	}
	ll m = -1;
	for(ll i = 0 ; i < n - 1 ; i++){
		if(ans[i] > m){
			res.clear();
			m = ans[i];
		}
		if(ans[i] == m){
			res.push_back(i + 1);
		}
	}
	cout<<2ll * m<<' '<<res.size()<<'\n';
	for(auto i : res){
		cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}

/*

*/