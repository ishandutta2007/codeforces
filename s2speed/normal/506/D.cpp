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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	return (v == ds[v] ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return;
}

ll cnt = 0;
map<pll , ll> ind , ans;
vector<ll> cl[maxn] , nd[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>n>>m;
	iota(ds , ds + 2 * m , 0);
	for(ll i = 0 ; i < m ; i++){
		ll v , u , c;
		cin>>v>>u>>c; v--; u--; c--;
		if(ind.count({v , c}) == 0){
			ind[{v , c}] = cnt++;
		}
		if(ind.count({u , c}) == 0){
			ind[{u , c}] = cnt++;
		}
		cl[v].push_back(c); cl[u].push_back(c);
		merge(ind[{v , c}] , ind[{u , c}]);
	}
	for(ll i = 0 ; i < n ; i++){
		sort(all(cl[i]));
		cl[i].resize(distance(cl[i].begin() , unique(all(cl[i]))));
		for(auto c : cl[i]){
			nd[i].push_back(ind[{i , c}]);
		}
		cl[i].push_back(inf);
	}
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll v , u;
		cin>>v>>u; v--; u--;
		pll pv = {sze(cl[v]) , v} , pu = {sze(cl[u]) , u};
		if(pv > pu) swap(v , u);
		if(ans.count({v , u})){
			cout<<ans[{v , u}]<<'\n';
			continue;
		}
		ll res = 0 , cs = sze(cl[v]) - 1;
		for(ll i = 0 ; i < cs ; i++){
			ll j = lower_bound(all(cl[u]) , cl[v][i]) - cl[u].begin();
			if(cl[u][j] == cl[v][i]){
				res += (dsu(nd[u][j]) == dsu(nd[v][i]));
			}
		}
		ans[{v , u}] = res;
		cout<<res<<'\n';
	}
	return 0;
}