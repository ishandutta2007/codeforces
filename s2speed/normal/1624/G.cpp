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

ll ds[maxn] , dsz[maxn];
vector<ll> upd;

ll dsu(ll v){
	return (ds[v] == v ? v : dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(v == u){
		upd.push_back(-1);
		return;
	}
	if(dsz[v] < dsz[u]) swap(v , u);
	dsz[v] += dsz[u];
	ds[u] = v;
	upd.push_back(u);
	return;
}

void undo(){
	ll u = upd.back(); upd.pop_back();
	if(u == -1) return;
	ll v = ds[u];
	ds[u] = u; dsz[v] -= dsz[u];
	return;
}

vector<pll> ed;
ll w[maxn];

void solve(){
	upd.clear(); ed.clear();
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		ds[i] = i;
		dsz[i] = 1;
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u>>w[i]; v--; u--;
		ed.push_back({v , u});
	}
	ll cur = 0 , lm = (1 << 31) - 1;
	for(ll j = 30 ; j >= 0 ; j--){
		ll h = (1 << j) , o = (lm ^ cur);
		for(ll i = 0 ; i < m ; i++){
			if((w[i] & o) >= h) continue;
			merge(ed[i].first , ed[i].second);
		}
		bool f = (dsz[dsu(0)] == n);
		for(ll i = 0 ; i < m ; i++){
			if((w[i] & o) >= h) continue;
			undo();
		}
		if(f) continue;
		cur ^= (1 << j);
		for(ll i = 0 ; i < m ; i++){
			if((w[i] & o) != h) continue;
			merge(ed[i].first , ed[i].second);
		}
	}
	cout<<cur<<'\n';
	return;
}

/*
1
3 4
1 2 1
2 3 2
1 3 3
3 1 4
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}