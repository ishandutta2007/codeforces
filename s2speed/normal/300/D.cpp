#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e3 + 16 , md = 7340033 , inf = 2e16;

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

ll dp[32][maxn][5];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = 1;
	for(ll i = 1 ; i < 31 ; i++){
		dp[i][0][0] = dp[i][0][1] = dp[i][0][2] = dp[i][0][3] = 1;
		for(ll j = 1 ; j < maxn ; j++){
			dp[i][j][0] = dp[i - 1][j - 1][3];
			for(ll c = 1 ; c < 4 ; c++){
				for(ll k = 0 ; k <= j ; k++){
					ll h = dp[i][k][0] * dp[i][j - k][c - 1];
					dp[i][j][c] += h;
				}
				dp[i][j][c] %= md;
			}
		}
	}
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll n , k , cnt = 0;
		cin>>n>>k;
		while(n > 1 && n & 1){
			n >>= 1;
			cnt++;
		}
		cout<<dp[cnt][k][0]<<'\n';
	}
	return 0;
}