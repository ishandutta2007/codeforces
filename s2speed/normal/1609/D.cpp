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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> gh;

void prime(){
	gh.set(); gh[0] = gh[1] = false;
	for(ll i = 2 ; i < maxn ; i++){
		if(!gh[i]) continue;
		for(ll j = 1ll * i * i ; j < maxn ; j += i){
			gh[j] = false;
		}
	}
	return;
}

ll ds[maxn] , dsz[maxn] , k = 1;

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(v == u){
		k++;
		return;
	}
	ds[u] = v;
	dsz[v] += dsz[u];
	dsz[u] = 0;
	return;
}

vector<ll> a;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	iota(ds , ds + n , 0);
	fill(dsz , dsz + n , 1);
	for(ll i = 0 ; i < q ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		merge(v , u);
		a.clear();
		for(ll i = 0 ; i < n ; i++) a.push_back(dsz[i]);
		sort(all(a) , greater<ll>());
		ll res = 0;
		for(ll i = 0 ; i < k ; i++) res += a[i];
		cout<<res - 1<<'\n';
	}
	return 0;
}