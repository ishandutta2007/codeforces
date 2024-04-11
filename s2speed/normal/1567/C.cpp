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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[11][5] , a[11];

void solve(){
	memset(dp , 0 , sizeof(dp));
	string s;
	cin>>s;
	ll n = sze(s);
	for(ll i = 0 ; i < n ; i++){
		a[n - i] = s[i] - '0';
	}
	dp[0][0] = 1;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < 4 ; j++){
			for(ll k = 0 ; k < 10 ; k++){
				for(ll q = 0 ; q < 10 ; q++){
					ll h = k + q + (j & 1);
					if(h % 10 != a[i + 1]) continue;
					dp[i + 1][(j >> 1) + 2 * (h >= 10)] += dp[i][j];
				}
			}
		}
	}
	cout<<dp[n][0] - 2<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}