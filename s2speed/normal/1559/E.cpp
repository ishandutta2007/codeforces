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

const ll maxn = 1e5 + 16 , md = 998244353 , inf = 2e16;

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

ll n , m , l[52] , r[52] , dp[52][maxn] , dl[52] , dr[52] , g[maxn] , f[maxn];

ll calc_dp(ll d){
	ll dm = m / d;
	for(ll i = 0 ; i < n ; i++){
		dl[i] = (l[i] + d - 1) / d;
		dr[i] = r[i] / d;
		for(ll j = 0 ; j <= dm ; j++) dp[i][j] = 0;
	}
	for(ll j = dl[0] ; j <= dr[0] ; j++) dp[0][j] = 1;
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 0 ; j <= dm ; j++){
			ll jl = j + dl[i] , jr = j + dr[i];
			if(jl <= dm){
				dp[i][jl] += dp[i - 1][j];
			}
			if(jr < dm){
				dp[i][jr + 1] -= dp[i - 1][j];
			}
		}
		for(ll j = 1 ; j <= dm ; j++){
			dp[i][j] += dp[i][j - 1];
			dp[i][j] %= md;
			if(dp[i][j] < 0) dp[i][j] += md;
		}
	}
	ll res = 0;
	for(ll j = 1 ; j <= dm ; j++) res += dp[n - 1][j];
	res %= md;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>l[i]>>r[i];
	}
	for(ll j = 1 ; j <= m ; j++){
		g[j] = calc_dp(j);
	}
	for(ll i = m ; i ; i--){
		f[i] = g[i];
		for(ll j = 2 * i ; j <= m ; j += i) f[i] -= f[j];
		f[i] %= md; if(f[i] < 0) f[i] += md;
	}
	cout<<f[1]<<'\n';
	return 0;
}