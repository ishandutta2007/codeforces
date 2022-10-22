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
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e2 + 15 , MAXM = 1e5 + 15 , md = 1e9 + 7 , inf = 2e15;

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

ll dp[MAXN][MAXM];

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dp , -1 , sizeof(dp));
	dp[0][0] = 0;
	ll n , m;
	cin>>n>>m;
	for(ll i = 1 ; i <= n ; i++){
		ll t;
		cin>>t;
		if(t == 1){
			ll x , y;
			cin>>x>>y; x = (x + 99999ll) / 100000ll;
			for(ll j = 0 ; j <= m ; j++){
				if(dp[i - 1][j] != -1){
					dp[i][j] = 0;
					continue;
				}
				if(j - x < 0) continue;
				if(dp[i][j - x] != -1 && dp[i][j - x] < y){
					dp[i][j] = dp[i][j - x] + 1;
				}
			}
		} else {
			ll x , y , p , c = 0;
			cin>>x>>y;
			for(ll j = 0 ; j <= m ; j++){
				p = c; c = 100000ll * j / x;
				if(dp[i - 1][j] != -1){
					dp[i][j] = 0;
					continue;
				}
				for(ll q = p + 1 ; q <= c ; q++){
					if(dp[i][q] != -1 && dp[i][q] < y){
						if(dp[i][j] == -1){
							dp[i][j] = dp[i][q] + 1;
						} else {
							dp[i][j] = min(dp[i][j] , dp[i][q] + 1);
						}
					}
				}
			}
		}
	}
	for(ll j = 1 ; j <= m ; j++){
		bool ch = false;
		for(ll i = 1 ; i <= n ; i++){
			if(dp[i][j] != -1){
				cout<<i<<' ';
				ch = true;
				break;
			}
		}
		if(!ch){
			cout<<"-1 ";
		}
	}
	return 0;
}