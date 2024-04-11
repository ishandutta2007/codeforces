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

const ll maxn = 64 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxn];

ll ps(ll k){
	memset(dp , 0 , sizeof(dp));
	ll l;
	for(ll j = 60 ; ~j ; j--){
		if(k & (1ll << j)){
			l = j + 1;
			break;
		}
	}
	ll res = 0;
	for(ll i = 1 ; i < l ; i++){
		ll j , t = 1 + (1ll << i) , o = (1ll << (i - 1));
		for(j = 2 * i ; j < l ; j += i){
			ll h = o;
			for(ll k = 1 ; k < i ; k++){
				if(i % k) continue;
				h -= dp[j][k];
			}
			dp[j][i] = h;
			res += h;
			t <<= i; t ^= 1;
		}
		if(j == l){
			ll g = k >> (l - i);
			ll h = g - o;
			h += (1ll * g * t <= k);
			for(ll k = 1 ; k < i ; k++){
				if(i % k) continue;
				h -= dp[j][k];
			}
			dp[j][i] = h;
			res += h;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll l , r;
	cin>>l>>r;
	ll ans = ps(r);
	if(l > 1) ans -= ps(l - 1);
	cout<<ans<<'\n';
	return 0;
}