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
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e2 + 16 , md = 1e9 + 7;
ll inf;

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

ll dp[maxn][maxn][2] , a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(dp , 63 , sizeof(dp));
	inf = dp[0][0][0];
	ll n , k;
	cin>>n; k = n / 2;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		if(a[i] > -1) a[i] &= 1;
		if(a[i] == 1) k--;
	}
	if(a[0] == 1){
		dp[0][k][1] = 0;
	}
	if(a[0] == 0){
		dp[0][k][0] = 0;
	}
	if(a[0] == -1){
		dp[0][k][0] = dp[0][k - 1][1] = 0;
	}
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 0 ; j <= k ; j++){
			if(a[i] == 1){
				dp[i][j][1] = min(dp[i - 1][j][0] + 1 , dp[i - 1][j][1]);
			}
			if(a[i] == 0){
				dp[i][j][0] = min(dp[i - 1][j][0] , dp[i - 1][j][1] + 1);
			}
			if(a[i] == -1){
				dp[i][j][0] = min(dp[i - 1][j][0] , dp[i - 1][j][1] + 1);
				dp[i][j][1] = min(dp[i - 1][j + 1][0] + 1 , dp[i - 1][j + 1][1]);
			}
		}
	}
	cout<<min(dp[n - 1][0][0] , dp[n - 1][0][1])<<'\n';
	return 0;
}