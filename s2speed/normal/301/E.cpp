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

const ll maxn = 112 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxn][maxn] , pd[maxn][maxn][maxn] , chs[maxn][maxn];
// m[n][x][ls]

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(pd , 0 , sizeof(pd));
	memset(dp , 0 , sizeof(dp));
	memset(chs , 0 , sizeof(chs));
	chs[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j < maxn ; j++){
			chs[i][j] = chs[i - 1][j] + chs[i - 1][j - 1];
		}
	}
	ll n , m , x , ans = 0;
	cin>>n>>m>>x;
	for(ll i = 1 ; i <= n ; i++){
		pd[i][1][i] = 1;
	}
	for(ll j = 2 ; j <= m ; j++){
		for(ll i = 1 ; i <= n ; i++){
			for(ll k = 1 ; k <= x ; k++){
				for(ll l = 1 ; l + i <= n ; l++){
					dp[i + l][k][0] += pd[i][k][l];
					for(ll q = l + 1 ; q + i <= n ; q++){
						ll h = chs[q - 1][l] * k;
						if(h > x) break;
						dp[i + q][h][q - l] += pd[i][k][l];
					}
				}
			}
		}
		ll h = 0;
		for(ll i = 1 ; i <= n ; i++){
			for(ll k = 1 ; k <= x ; k++){
				for(ll l = 0 ; l <= n ; l++){
					dp[i][k][l] %= md;
				}
				h += dp[i][k][0];
			}
		}
		h *= m - j + 1; h %= md;
		ans += h;
		memcpy(pd , dp , sizeof(pd));
		memset(dp , 0 , sizeof(dp));
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}

/*
4 4 1
*/