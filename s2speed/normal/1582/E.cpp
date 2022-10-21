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

const ll maxn = 1e5 + 16 , maxsq = 460 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxsq] , a[maxn] , ps[maxn];

void solve(){
	ll n , k;
	cin>>n;
	for(ll j = 1 ; j * (j + 1) / 2 <= n ; j++){
		for(ll i = 1 ; i <= n ; i++){
			dp[i][j] = -1;
		}
		k = j;
	}
	dp[1][k + 1] = -1;
	ps[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	dp[n][1] = a[n];
	for(ll i = n - 1 ; i ; i--){
		dp[i][1] = max(a[i] , dp[i + 1][1]);
		for(ll j = 2 ; j <= k && i + j * (j + 1) / 2 <= n + 1 ; j++){
			ll h = -1;
			if(ps[i + j - 1] - ps[i - 1] < dp[i + j][j - 1]){
				h = ps[i + j - 1] - ps[i - 1];
			}
			dp[i][j] = max(h , dp[i + 1][j]);
		}
	}
	for(ll i = 1 ; i <= k + 1 ; i++){
		if(dp[1][i] == -1){
			cout<<i - 1<<'\n';
			break;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}