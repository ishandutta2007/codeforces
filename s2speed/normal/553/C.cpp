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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return;
}

vector<pll> ed;
bitset<maxn> dis , mark;
ll dep = 0;
vector<ll> adj[maxn];

void bDFS(ll r){
	mark[r] = true;
	dis[r] = dep;
	dep ^= 1;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		bDFS(i);
	}
	dep ^= 1;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>n>>m;
	iota(ds , ds + n , 0);
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		if(w){
			merge(v , u);
		} else {
			ed.push_back({v , u});
		}
	}
	for(auto p : ed){
		ll v = dsu(p.first) , u = dsu(p.second);
		adj[v].push_back(u); adj[u].push_back(v);
	}
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		if(ds[i] != i || mark[i]) continue;
		bDFS(i);
		cnt++;
	}
	for(auto p : ed){
		ll v = dsu(p.first) , u = dsu(p.second);
		if(dis[v] ^ dis[u]) continue;
		cout<<"0\n";
		return 0;
	}
	cout<<tav(2 , cnt - 1)<<'\n';
	return 0;
}