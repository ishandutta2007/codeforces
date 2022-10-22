#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 5e6 + 16 , md = 2000000357 , inf = 2e18;
 
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

ll dp[maxn];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	string s;
	ll n , p = 131 , q = p , h = 0 , g = 0 , ans = 0;
	cin>>s; n = sze(s);
	dp[0] = ans = 1;
	h = g = s[0];
	for(ll i = 1 ; i < n ; i++){
		h *= p; h += s[i]; h %= md;
		g += 1ll * q * s[i]; g %= md;
		q *= p; q %= md;
		if(g == h){
			dp[i] = dp[(i - 1) / 2] + 1;
		}
		ans += dp[i];
	}
	cout<<ans<<'\n';
	return 0;
}