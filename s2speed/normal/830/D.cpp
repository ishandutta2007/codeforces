#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 4e2 + 15 , md = 1e9 + 7 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

ll dp[MAXN][MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		dp[i][0] = 1;
	}
	dp[1][1] = 1;
	for(ll i = 2 ; i <= n ; i++){
		for(ll j = 1 ; j <= n - i + 1 ; j++){
			for(ll q = 0 ; q <= j ; q++){
				ll h = 1ll * dp[i - 1][q] * dp[i - 1][j - q] % md;
				dp[i][j] += h;
			}
			for(ll q = 0 ; q < j ; q++){
				ll h = 1ll * dp[i - 1][q] * dp[i - 1][j - q - 1] % md;
				dp[i][j] += h;
			}
			for(ll q = 0 ; q <= j ; q++){
				ll h = 2ll * dp[i - 1][q] * dp[i - 1][j - q] % md * j % md;
				dp[i][j] += h;
			}
			for(ll q = 0 ; q <= j + 1 ; q++){
				ll h = 1ll * dp[i - 1][q] * dp[i - 1][j - q + 1] % md * j * (j + 1) % md;
				dp[i][j] += h;
			}
			dp[i][j] %= md;
		}
	}
	cout<<dp[n][1]<<'\n';
	return 0;
}

/*

*/