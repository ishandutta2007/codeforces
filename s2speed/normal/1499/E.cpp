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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e3 + 16 , md = 998244353 , inf = 2e18;

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

ll dp[maxn][maxn][2] , pd[maxn][maxn][2] , cd[maxn][maxn][2] , ad[maxn] , bd[maxn];

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	ll n , m;
	string a , b;
	cin>>a>>b; n = a.size(); m = b.size();
	ad[0] = 1;
	for(ll i = 1 ; i < n ; i++){
		ad[i] = ad[i - 1] * (a[i] != a[i - 1]) + 1;
	}
	bd[0] = 1;
	for(ll j = 1 ; j < m ; j++){
		bd[j] = bd[j - 1] * (b[j] != b[j - 1]) + 1;
	}	
	for(ll i = 0 ; i < n ; i++){
		pd[i][0][0] = pd[i][0][1] = (a[i] != b[0]);
		for(ll j = 1 ; j < m ; j++){
			pd[i][j][0] = bd[j] * (a[i] != b[j]);
			pd[i][j][1] = pd[i][j - 1][1] * (b[j] != b[j - 1]) + pd[i][j - 1][0] * (a[i] != b[j]) + (a[i] != b[j]);
		}
	}
	for(ll j = 0 ; j < m ; j++){
		cd[0][j][0] = cd[0][j][1] = (b[j] != a[0]);
		for(ll i = 1 ; i < n ; i++){
			cd[i][j][1] = ad[i] * (a[i] != b[j]);
			cd[i][j][0] = cd[i - 1][j][0] * (a[i] != a[i - 1]) + cd[i - 1][j][1] * (a[i] != b[j]) + (a[i] != b[j]);
		}
	}
	dp[0][0][0] = dp[0][0][1] = (a[0] != b[0]);
	for(ll j = 1 ; j < m ; j++){
		dp[0][j][1] = pd[0][j][1];
		dp[0][j][0] = pd[0][j][0];
	}
	for(ll i = 1 ; i < n ; i++){
		dp[i][0][0] = cd[i][0][0];
		dp[i][0][1] = cd[i][0][1];
		for(ll j = 1 ; j < m ; j++){
			dp[i][j][0] = dp[i - 1][j][0] * (a[i] != a[i - 1]) + dp[i - 1][j][1] * (a[i] != b[j]) + pd[i][j][0]; dp[i][j][0] %= md;
			dp[i][j][1] = dp[i][j - 1][0] * (a[i] != b[j]) + dp[i][j - 1][1] * (b[j] != b[j - 1]) + cd[i][j][1]; dp[i][j][1] %= md;
		}
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			ans += dp[i][j][0] + dp[i][j][1];
//			cout<<dp[i][j][0] + dp[i][j][1]<<' ';
		}
//		cout<<'\n';
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}