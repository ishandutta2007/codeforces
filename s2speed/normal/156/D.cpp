#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 16 , inf = 2e16;
ll md;

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

ll ds[maxn] , dsz[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	ds[u] = v;
	dsz[v] += dsz[u];
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , ans = 1 , cnt = 0;
	cin>>n>>m>>md;
	iota(ds , ds + n , 0);
	fill(dsz , dsz + n , 1);
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		merge(v , u);
	}
	for(ll i = 0 ; i < n ; i++){
		if(ds[i] != i) continue;
		ans *= dsz[i]; ans %= md;
		cnt++;
	}
	if(cnt == 1){
		cout<<1 % md<<"\n";
		return 0;
	}
	ans *= tav(n , cnt - 2); ans %= md;
	cout<<ans<<'\n';
	return 0;
}