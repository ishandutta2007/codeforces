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

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , h , m;
	cin>>n>>h>>m;
	for(ll i = 0 ; i < n ; i++){
		a[i] = h;
	}
	for(ll i = 0 ; i < m ; i++){
		ll l , r , w;
		cin>>l>>r>>w; l--;
		for(ll j = l ; j < r ; j++){
			a[j] = min(a[j] , w);
		}
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		ans += 1ll * a[i] * a[i];
	}
	cout<<ans<<endl;
	return 0;
}