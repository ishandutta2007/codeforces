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

const ll maxn = 2e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxn] , dv = tav(2 , md - 2);

void solve(){
	ll n , m , k;
	cin>>n>>m>>k;
	dp[0][0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		dp[i][0] = 0;
		ll lm = min(i , m + 1);
		for(ll j = 1 ; j < lm ; j++){
			ll h = (dp[i - 1][j] + dp[i - 1][j - 1]) * dv % md;
			dp[i][j] = h;
		}
		if(i <= m){
			dp[i][i] = dp[i - 1][i - 1] + k;
			dp[i][i] -= (dp[i][i] >= md) * md;
		}
	}
	cout<<dp[n][m]<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}