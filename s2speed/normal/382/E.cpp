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

const ll maxn = 57 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxn][2] , chs[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	chs[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j < maxn ; j++){
			chs[i][j] = chs[i - 1][j - 1] + chs[i - 1][j]; chs[i][j] -= (chs[i][j] >= md) * md;
		}
	}
	dp[0][0][1] = dp[1][0][0] = 1;
	ll n , k , dv = tav(2 , md - 2);
	cin>>n>>k;
	for(ll i = 2 ; i <= n ; i++){
		ll lm = i >> 1;
		for(ll j = 0 ; j <= lm ; j++){
			ll res = 0;
			for(ll s = 0 ; s < i ; s++){
				for(ll k = 0 ; k <= j ; k++){
					ll h = dp[s][k][1] * dp[i - s - 1][j - k][1] % md * chs[i - 1][s] % md;
					res += h;
				}
			}
			res %= md;
			res *= dv; res %= md;
			dp[i][j][0] = res * i % md;
			res = 0;
			for(ll s = 0 ; s <= i ; s++){
				for(ll k = 0 ; k < j ; k++){
					ll h = ((dp[s][k][0] + dp[s][k][1]) * (dp[i - s - 1][j - k - 1][0] + dp[i - s - 1][j - k - 1][1]) - dp[s][k][1] * dp[i - s - 1][j - k - 1][1]) % md * chs[i - 1][s] % md;
					res += h;
				}
			}
			res %= md;
			res *= dv; res %= md;
			dp[i][j][1] = res * i % md;
		}
	}
	ll ans = dp[n][k][0] + dp[n][k][1];
	ans *= tav(n , md - 2); ans %= md;
	cout<<ans<<'\n';
	return 0;
}