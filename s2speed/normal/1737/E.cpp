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

const ll maxn = 1e6 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn] , f[maxn];

void solve(){
	ll n , cur = 0;
	cin>>n;
	fill(f , f + n + 1 , 0);
	if(n == 1){
		cout<<"1\n";
		return;
	}
	ll z = 1;
	for(ll i = n ; i > 1 ; i--){
		cur <<= 1; cur += f[i]; cur %= md;
		ll h = z - cur;
		h += (h < 0) * md;
		z <<= 1; z -= (z >= md) * md;
		if(i == n){
			h <<= 1; h -= (h >= md) * md;
		}
		dp[i] = h;
		f[(i >> 1)] += dp[i];
	}
	z <<= 1; z -= (z >= md) * md;
	z = tav(z , md - 2);
	for(ll i = 1 ; i <= n ; i++){
		ll h = tav(2 , (i >> 1)) * dp[i] % md * z % md;
		cout<<h<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}