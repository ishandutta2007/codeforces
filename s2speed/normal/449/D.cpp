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

const ll maxn = 2e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll cnt[maxn] , f[maxn] , tv[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = tv[i - 1] << 1; if(tv[i] > md) tv[i] -= md;
	}
	memset(cnt , 0 , sizeof(cnt));
	ll n , lm = (1 << 20);
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		h ^= (lm - 1);
		cnt[h]++;
	}
	for(ll i = 0 ; i < lm ; i++){
		f[i] = cnt[i];
	}
	for(ll j = 0 ; j < 20 ; j++){
		for(ll mask = 0 ; mask < lm ; mask++){
			if(mask & (1 << j)) f[mask] += f[mask ^ (1 << j)];
		}
	}
	ll ans = 0;
	for(ll mask = 0 ; mask < lm ; mask++){
		ll j = __builtin_popcount(mask) & 1;
		if(j){
			ans -= tv[f[mask]] - 1;
		} else {
			ans += tv[f[mask]] - 1;
		}
	}
	ans %= md;
	if(ans < 0) ans += md;
	cout<<ans<<'\n';
	return 0;
}