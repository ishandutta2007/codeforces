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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , dp[maxn][3] , pd[maxn];

void solve(){
	ll n , k;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		dp[i][0] = dp[i][1] = dp[i][2] = inf;
	}
	cin>>k;
	pd[0] = dp[0][0] = 0; dp[0][1] = 1;
	dp[1][1] = dp[1][2] = pd[1] = 1;
	if(a[0] + a[1] >= 2 * k) dp[1][0] = pd[1] = 0;
	for(ll i = 2 ; i < n ; i++){
		dp[i][1] = pd[i - 1] + 1;
		dp[i][2] = dp[i - 1][1];
		if(a[i] + a[i - 1] >= 2 * k){
			dp[i][0] = dp[i - 1][2];
			if(a[i] + a[i - 1] + a[i - 2] >= 3 * k){
				dp[i][0] = min(dp[i][0] , dp[i - 1][0]);
			}
		}
		pd[i] = min(dp[i][0] , min(dp[i][1] , dp[i][2]));
	}
	cout<<n - pd[n - 1]<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}