#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 320 , md = 1e9 + 7 , inf = 2e17;

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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , x;
	cin>>n>>m>>x; x--;
	if(n > m){
		cout<<"0\n";
		return 0;
	}
	ll dp[m + 5][n + 5][n + 5];
	memset(dp , 0 , sizeof(dp));
	dp[0][1][0] = dp[0][1][1] = 1;
	if(0 != x) dp[0][0][0] = 1;
	for(ll j = 1 ; j < m ; j++){
		dp[j][0][0] = (j < x);
		ll lm = min(n , j + 1);
		for(ll i = 1 ; i <= lm ; i++){
			dp[j][i][0] = dp[j - 1][i - 1][0];
			if(j != x) dp[j][i][0] += dp[j - 1][i][0];
			dp[j][i][0] %= md;
			for(ll k = 1 ; k <= i ; k++){
				dp[j][i][k] = dp[j - 1][i - 1][k] + dp[j - 1][i - 1][k - 1];
				if(j != x) dp[j][i][k] += dp[j - 1][i][k] + dp[j - 1][i][k - 1];
				dp[j][i][k] %= md;
			}
		}
	}
	ll ans = dp[m - 1][n][n];
	for(ll i = 1 ; i <= n ; i++){
		ans *= i; ans %= md;
	}
	cout<<ans<<'\n';
	return 0;
}