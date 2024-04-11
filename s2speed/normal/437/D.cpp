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

ll ds[maxn] , dsz[maxn] , res = 0;

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u , ll w){
	v = dsu(v) , u = dsu(u);
	if(v == u) return;
	res += 1ll * dsz[v] * dsz[u] * w;
	dsz[v] += dsz[u];
	ds[u] = v;
	return;
}

vector<pll> ed , sr;
ll a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		ed.push_back({v , u});
		sr.push_back({min(a[v] , a[u]) , i});
	}
	sort(all(sr) , greater<pll>());
	iota(ds , ds + n , 0);
	fill(dsz , dsz + n , 1);
	for(ll i = 0 ; i < m ; i++){
		ll j = sr[i].second , v = ed[j].first , u = ed[j].second;
		merge(v , u , sr[i].first);
	}
	db ans = (db)1 * res / (n * (n - 1) / 2ll);
	cout<<fixed<<setprecision(10)<<ans<<'\n';
	return 0;
}