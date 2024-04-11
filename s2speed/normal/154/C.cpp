#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MAXN = 1e6 + 20 , md = 1e9 + rng() % 1000 , md2 = 2000000357 , inf = 2e9 + 1;
// check problem statement
// i * fi = 2e

vector<ll> adj[MAXN];
vector<pll> v;
pll h[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(h , 0 , sizeof(h));
	ll n , m , ans = 0 , p = 1e6 + 3 , q = 1e6 + 33;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(ll i = 1 ; i <= n ; i++){
		sort(all(adj[i]));
		ll e = p , w = q , as = adj[i].size() , o;
		for(ll j = 0 ; j < as ; j++){
			o = 1ll * e * adj[i][j] % md;
			h[i].first += o;
			e *= p; e %= md;
			o = 1ll * w * adj[i][j] % md2;
			h[i].second += o;
			w *= q; w %= md2;
		}
		h[i].first %= md; h[i].second %= md2;
		v.push_back(h[i]);
	}
	sort(all(v));
	ll cnt = 1;
	for(ll i = 1 ; i < n ; i++){
		if(v[i] == v[i - 1]){
			cnt++;
			continue;
		}
		ans += 1ll * cnt * (cnt - 1) / 2ll;
		cnt = 1;
	}
	ans += 1ll * cnt * (cnt - 1) / 2ll;
	memset(h , 0 , sizeof(h));
	v.clear();
	for(ll i = 1 ; i <= n ; i++){
		adj[i].push_back(i); sort(all(adj[i]));
	}
	for(ll i = 1 ; i <= n ; i++){
		ll e = p , w = q , as = adj[i].size() , o;
		for(ll j = 0 ; j < as ; j++){
			o = 1ll * e * adj[i][j] % md;
			h[i].first += o;
			e *= p; e %= md;
			o = 1ll * w * adj[i][j] % md2;
			h[i].second += o;
			w *= q; w %= md2;
		}
		h[i].first %= md; h[i].second %= md2;
		v.push_back(h[i]);
	}
	sort(all(v));
	cnt = 1;
	for(ll i = 1 ; i < n ; i++){
		if(v[i] == v[i - 1]){
			cnt++;
			continue;
		}
		ans += 1ll * cnt * (cnt - 1) / 2ll;
		cnt = 1;
	}
	ans += 1ll * cnt * (cnt - 1) / 2ll;
	cout<<ans<<'\n';
	return 0;
}

/*

*/