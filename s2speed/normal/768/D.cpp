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

const ll maxn = 1e3 + 16 , maxd = 7.5e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

db dp[maxn][maxd];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	ll k , q;
	cin>>k>>q;
	dp[0][0] = 1;
	for(ll j = 1 ; j < maxd ; j++){
		dp[0][j] = 0;
		for(ll i = 1 ; i <= k ; i++){
			dp[i][j] = dp[i - 1][j - 1] * (k - i + 1) + dp[i][j - 1] * i;
			dp[i][j] /= k;
		}
	}
	for(ll e = 0 ; e < q ; e++){
		db p;
		cin>>p;
		p /= (db)2000;
		for(ll j = 1 ; j < maxd ; j++){
			if(dp[k][j] >= p){
				cout<<j<<'\n';
				break;
			}
		}
	}
	return 0;
}