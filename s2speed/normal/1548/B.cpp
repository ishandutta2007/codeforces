#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][20] , a[maxn] , b[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll j = 0 ; j < 20 ; j++){
		for(ll i = 0 ; i < n ; i++){
			dp[i][j] = 1;
		}
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		b[i] = abs(a[i + 1] - a[i]);
		dp[i][0] = b[i];
	}
	for(ll j = 1 ; j < 20 ; j++){
		ll q = (1 << j);
		for(ll i = 0 ; i + q < n ; i++){
			dp[i][j] = gcd(dp[i][j - 1] , dp[i + q / 2][j - 1]);
		}
	}
	ll ans = 0;
	for(ll i = 0 ; i < n - 1 ; i++){
		ll cur = 0 , res = 0 , h = i;
		for(ll j = 19 ; j >= 0 ; j--){
			ll o = gcd(cur , dp[h][j]);
			if(o > 1){
				res += (1 << j);
				cur = o;
				h = i + res;
			}
		}
		ans = max(ans , res);
	}
	cout<<ans + 1<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}