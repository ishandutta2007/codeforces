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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 5e3 + 15 , md = 1e9 + 7 , inf = 2e9;

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

ll dp[MAXN] , tag[MAXN] , s[MAXN];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>tag[i];
		dp[i] = 0;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>s[i];
	}
	for(ll i = 1 ; i < n ; i++){
		ll h = 0;
		for(ll j = i - 1 ; j >= 0 ; j--){
			if(tag[j] == tag[i]) continue;
			ll o = h;
			dp[i] = max(dp[i] , dp[j] + abs(s[i] - s[j]));
			h = max(h , abs(s[i] - s[j]) + dp[j]);
			dp[j] = max(dp[j] , o + abs(s[i] - s[j]));
		}
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		ans = max(ans , dp[i]);
	}
	cout<<ans<<'\n';
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/