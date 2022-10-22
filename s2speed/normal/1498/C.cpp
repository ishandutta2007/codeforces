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

const ll MAXN = 1e3 + 15 , md = 1e9 + 7 , inf = 2e15;

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

ll dp[MAXN][MAXN][2] , pd[MAXN][MAXN][2];

void solve(){
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		dp[0][i][0] = 1;
		pd[0][i][0] = i;
		dp[0][i][1] = 1;
		pd[0][i][1] = n - i - 1;
	}
	for(ll i = 1 ; i < k ; i++){
		for(ll j = 0 ; j < n ; j++){
			dp[i][j][0] = pd[i - 1][max(0ll , j - 1)][1] + 1 + (j == 0); dp[i][j][0] %= md;
			dp[i][j][1] = pd[i - 1][min(n - 1 , j + 1)][0] + 1 + (j == n - 1); dp[i][j][1] %= md;
		}
		pd[i][0][0] = 0;
		for(ll j = 1 ; j < n ; j++){
			pd[i][j][0] = pd[i][j - 1][0] + dp[i][j][0]; pd[i][j][0] %= md;
		}
		pd[i][n - 1][1] = 0;
		for(ll j = n - 2 ; j >= 0 ; j--){
			pd[i][j][1] = pd[i][j + 1][1] + dp[i][j][1]; pd[i][j][1] %= md;
		}
	}
	cout<<dp[k - 1][0][0]<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}