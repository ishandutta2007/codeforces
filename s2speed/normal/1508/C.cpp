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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , maxn2 = 7e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll ds[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

bool merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return (v != u);
}

ll n , m;
ll d[maxn];
vector<plll> ed;
vector<ll> adj[maxn];

void sub1(){
	memset(d , 0 , sizeof(d));
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		ed.push_back({w , {v , u}});
		adj[v].push_back(u); adj[u].push_back(v);
		d[v]++; d[u]++;
	}
	sort(all(ed));
	pll mn = {d[0] , 0};
	for(ll i = 1 ; i < n ; i++){
		mn = min(mn , {d[i] , i});
	}
	ll r = mn.second;
	sort(all(adj[r])); adj[r].push_back(inf);
	ll x = 0;
	for(ll i = 0 ; i < n ; i++){
		if(i == adj[r][x]){
			x++;
			continue;
		}
		merge(r , i);
	}
	adj[r].pop_back();
	for(auto v : adj[r]){
		sort(all(adj[v])); adj[v].push_back(inf);
		x = 0;
		for(ll i = 0 ; i < n ; i++){
			if(i == adj[v][x]){
				x++;
				continue;
			}
			merge(v , i);
		}
	}
	ll ans = 0;
	for(auto q : ed){
		ll v = q.second.first , u = q.second.second , w = q.first;
		ans += w * merge(v , u);
	}
	cout<<ans<<'\n';
	return;
}

ll f[maxn2][maxn2];

ll ds2[maxn];

ll dsu2(ll v){
	return (ds2[v] == v ? v : ds2[v] = dsu2(ds2[v]));
}

void merge2(ll v , ll u){
	v = dsu2(v); u = dsu2(u);
	ds2[u] = v;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(f , 0 , sizeof(f));
	cin>>n>>m;
	iota(ds , ds + n , 0);
	if(n > 7e2){
		sub1();
		return 0;
	}
	iota(ds2 , ds2 + n , 0);
	ll h = 0;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		f[v][u] = f[u][v] = w;
		ed.push_back({w , {v , u}});
		h ^= w;
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i + 1 ; j < n ; j++){
			if(!f[i][j]){
				if(!merge(i , j)) h = 0;
			}
		}
	}
	sort(all(ed));
	ll ans = 0;
	for(auto q : ed){
		ll w = q.first , v = q.second.first , u = q.second.second;
		if(dsu(v) == dsu(u) && dsu2(v) != dsu2(u)){
			h = min(h , w);
			merge2(v , u);
		}
		if(merge(v , u)){
			ans += w;
			merge2(v , u);
		}
	}
	cout<<ans + h<<'\n';
	return 0;
}