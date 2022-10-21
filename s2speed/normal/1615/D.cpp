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

const ll maxn = 4e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> tdj[maxn];
ll pr[maxn] , w[maxn] , g[maxn] , c[maxn];
vector<plll> ed;

void dDFS(ll r , ll par){
	pr[r] = par;
	for(auto i : tdj[r]){
		if(i == par) continue;
		dDFS(i , r);
	}
	return;
}

void aDFS(ll r , ll par){
	if(par != -1){
		cout<<r + 1<<' '<<par + 1<<' '<<(w[r] == -1 ? (g[r] ^ g[par]) : w[r])<<'\n';
	}
	for(auto i : tdj[r]){
		if(i == par) continue;
		aDFS(i , r);
	}
	return;
}

void solve(){
	ed.clear();
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < 2 * n ; i++){
		tdj[i].clear();
		ds[i] = i;
		c[i] = -1;
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		ed.push_back({{v , u} , w});
		tdj[v].push_back(u); tdj[u].push_back(v);
	}
	pr[0] = -1;
	dDFS(0 , -1);
	for(ll i = 0 ; i < n - 1 ; i++){
		ll v = ed[i].first.first , u = ed[i].first.second , o = ed[i].second;
		ll f = 0;
		for(ll j = 0 ; j < 30 ; j++){
			f ^= (bool)(o & (1 << j));
		}
		if(o == -1) f = -1;
		if(pr[u] == v) swap(v , u);
		w[v] = o;
		if(f == 0){
			merge(v , u);
			merge(v + n , u + n);
		} else if(f == 1) {
			merge(v , u + n);
			merge(v + n , u);
		}
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u , f;
		cin>>v>>u>>f; v--; u--;
		if(f == 0){
			merge(v , u);
			merge(v + n , u + n);
		} else {
			merge(v , u + n);
			merge(v + n , u);
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(dsu(i) == dsu(i + n)){
			cout<<"NO\n";
			return;
		}
	}
	ll cnt = 0;
	for(ll i = 0 ; i < 2 * n ; i++){
		if(c[dsu(i)] == -1){
			c[ds[i]] = cnt++;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		g[i] = (c[dsu(i)] > c[dsu(i + n)]);
	}
	cout<<"YES\n";
	aDFS(0 , -1);
	return;
}

/*
1
6 5
1 2 -1
1 3 1
4 2 7
6 3 0
2 5 -1
2 3 1
2 5 0
5 6 1
6 1 1
4 5 1
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}