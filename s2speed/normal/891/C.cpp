#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 2e18;

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

ll ds[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return;
}

struct wed {
	ll v , u , w;
};

bool cmp(wed a , wed b){
	return a.w < b.w;
}

vector<ll> v , c[maxn];
vector<pll> adj[maxn];
bitset<maxn> mark , ans , ch;
ll x[maxn] , s;
vector<wed> q[maxn] , t;
wed e[maxn];

void DFS(ll r , ll ind){
	mark[r] = true;
	for(auto p : adj[r]){
		ll i = p.first , j = p.second;
		if(j == ind) continue;
		if(mark[i]){
			ans[s] = false;
			return;
		}
		DFS(i , j);
		if(!ans[s]) return;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ans.set();
	memset(x , 0 , sizeof(x));
	ll n , m , Q;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		e[i] = {v , u , w};
		t.push_back(e[i]);
	}
	cin>>Q;
	for(ll i = 0 ; i < Q ; i++){
		ll k;
		cin>>k;
		for(ll j = 0 ; j < k ; j++){
			ll y;
			cin>>y; y--;
			q[i].push_back(e[y]);
			c[e[y].w].push_back(i);
		}
		sort(all(q[i]) , cmp); q[i].push_back({-1 , -1 , inf});
	}
	sort(all(t) , cmp); t.push_back({-1 , -1 , inf});
	ll y = 0;
	iota(ds , ds + n , 0);
	for(ll i = 1 ; i < maxn ; i++){
		for(auto j : c[i]){
			if(ch[j]) continue;
			ch[j] = true;
			ll z = x[j] , g = 0;
			while(q[j][z].w == i){
				ll a = dsu(q[j][z].v) , b = dsu(q[j][z].u);
				if(a == b){
					ans[j] = false;
					z++;
					continue;
				}
				adj[a].push_back({b , g}); adj[b].push_back({a , g++});
				v.push_back(a); v.push_back(b);
				z++;
			}
			x[j] = z;
			s = j;
			for(auto k : v){
				if(mark[k]) continue;
				DFS(k , -1);
			}
			for(auto k : v){
				mark[k] = false;
				adj[k].clear();
			}
			v.clear();
		}
		for(auto j : c[i]) ch[j] = false;
		while(t[y].w == i){
			merge(t[y].v , t[y].u);
			y++;
		}		
	}
	for(ll i = 0 ; i < Q ; i++){
		cout<<(ans[i] ? "YES\n" : "NO\n");
	}
	return 0;
}