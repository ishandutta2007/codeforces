#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e6 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

ll ds[MAXN] , dsz[MAXN] , cnt[MAXN];

ll dsu(ll v){
	return ds[v] = (ds[v] == v ? v : dsu(ds[v]));
}

void unite(ll v , ll u){
	ll dv = dsu(v) , du = dsu(u);
	if(dv == du) return;
	if(dsz[dv] < dsz[du]) swap(v , u);
	ll h = 1ll * dsz[dv] * dsz[du];
	cnt[v] += h; cnt[u] += h;
	dsz[dv] += dsz[du]; dsz[du] = 0;
	ds[du] = ds[dv];
	return;
}

ll a[MAXN];
vector<pll> ed , b;
vector<pllll> d;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		b.push_back({a[i] , i});
	}
	for(int i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		ed.push_back({v , u});
	}
	for(int i = 0 ; i < n - 1 ; i++){
		ll v = ed[i].first , u = ed[i].second;
		pll o = min(mp(a[v] , v) , mp(a[u] , u));
		d.push_back({o , ed[i]});
	}
	sort(all(d) , greater<pllll>());
	sort(all(b) , greater<pll>());
	ll x = 0;
	iota(ds , ds + n , 0);
	fill(dsz , dsz + n , 1);
	fill(cnt , cnt + n , 1);
	for(int e = 0 ; e < n ; e++){
		ll i = b[e].second;
		while(x < n - 1){
			if(d[x].first < b[e]) break;
			ll v = d[x].second.first , u = d[x].second.second;
			unite(v , u);
			x++;
		}
		ans -= 1ll * cnt[i] * a[i];
	}
//	cout<<ans<<'\n';
	d.clear();
	reverse(all(b));
	for(int i = 0 ; i < n - 1 ; i++){
		ll v = ed[i].first , u = ed[i].second;
		pll o = max(mp(a[v] , v) , mp(a[u] , u));
		d.push_back({o , ed[i]});
	}
	sort(all(d));
	iota(ds , ds + n , 0);
	fill(dsz , dsz + n , 1);
	fill(cnt , cnt + n , 1);
	x = 0;
	for(int e = 0 ; e < n ; e++){
		ll i = b[e].second;
		while(x < n - 1){
			if(d[x].first > b[e]) break;
			ll v = d[x].second.first , u = d[x].second.second;
			unite(v , u);
			x++;
		}
		ans += 1ll * cnt[i] * a[i];
	}
	cout<<ans<<'\n';
	return 0;
}

/*
4
1 1 1 1
1 2 2 3 1 4
*/