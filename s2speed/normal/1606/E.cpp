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

const ll maxn = 5e2 + 16 , md = 998244353 , inf = 2e16;

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

ll chs[maxn][maxn] , tv[maxn][maxn] , dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(chs , 0 , sizeof(chs));
	memset(dp , 0 , sizeof(dp));
	for(ll i = 0 ; i < maxn ; i++){
		tv[i][0] = 1;
		for(ll j = 1 ; j < maxn ; j++){
			tv[i][j] = 1ll * i * tv[i][j - 1] % md;
		}
	}
	chs[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			chs[i][j] = chs[i - 1][j - 1] + chs[i - 1][j];
			if(chs[i][j] >= md) chs[i][j] -= md;
		}
	}
	ll n , k;
	cin>>n>>k;
	for(ll i = 2 ; i <= n ; i++){
		for(ll j = 1 ; j < i ; j++){
			dp[i][j] = tv[j][i];
		}
		for(ll j = i ; j <= k ; j++){
			ll o = tv[i - 1][i];
			for(ll q = 2 ; q <= i ; q++){
				ll h = 1ll * chs[i][q] * tv[i - 1][i - q] % md * dp[q][j - (i - 1)] % md;
				o += h;
			}
			dp[i][j] = o % md;
		}
	}
	cout<<dp[n][k]<<'\n';
	return 0;
}