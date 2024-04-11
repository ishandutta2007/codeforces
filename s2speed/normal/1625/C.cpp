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

const ll maxn = 5e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxn] , x[maxn] , a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	dp[0][1] = 0;
	ll n , k;
	cin>>n>>x[n]>>k; k = n - k + 1;
	for(ll i = 0 ; i < n ; i++){
		cin>>x[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	n++;
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 2 ; j <= i + 1 ; j++){
			ll sum = 0;
			for(ll q = i - 1 ; q >= 0 ; q--){
				sum += x[q + 1] - x[q];
				dp[i][j] = min(dp[i][j] , dp[q][j - 1] + sum * a[q]);
			}
		}
	}
	ll ans = inf;
	for(ll j = k ; j <= n ; j++){
		ans = min(ans , dp[n - 1][j]);
	}
	cout<<ans<<'\n';
	return 0;
}