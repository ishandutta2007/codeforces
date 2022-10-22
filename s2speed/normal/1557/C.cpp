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

ll tv[maxn];

void solve(){
	ll n , k , cur = 1 , ans = 0 , w , d;
	cin>>n>>k;
	if(n & 1){
		w = 0;
	} else {
		w = 1;
	}
	if(n & 1){
		d = 1 + tv[n - 1];
	} else {
		d = tv[n - 1] - 1;
	}
	for(ll i = k - 1 ; i >= 0 ; i--){
		ll h = 1ll * w * cur * tav(2 , 1ll * i * n) % md;
		ans += h;
		cur *= d; cur %= md;
	}
	ans += cur;
	ans %= md;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = (tv[i - 1] << 1); if(tv[i] >= md) tv[i] -= md;
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}