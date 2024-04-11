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

const ll maxn = 2e3 + 17 , md = 998244353 , inf = 2e16;

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

ll dp[maxn][maxn] , fact[maxn];

void solve(){
	ll n , m , m2 , k , ans = 0 , cn = 1 , lm , res = 0;
	cin>>n>>m>>k;
	lm = min(n , k); m2 = (m + 1) / 2;
	for(ll i = 1 ; i <= lm ; i++){
		ll dv = tav(i , md - 2);
		cn *= (n - i + 1); cn %= md; cn *= dv; cn %= md;
		ll h = tav(m , n - i) * tav(m2 , i) % md * cn % md * dp[k][i] % md;
		res += h;
	}
	res %= md;
	cout<<res<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = fact[i - 1] * i % md;
	}
	dp[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = 1 ; j <= i ; j++){
			ll h = dp[i - 1][j] * j + dp[i - 1][j - 1];
			dp[i][j] = h % md;
		}
	}
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = 1 ; j <= i ; j++){
			dp[i][j] *= fact[j]; dp[i][j] %= md;
		}
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}