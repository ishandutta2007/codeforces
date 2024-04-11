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

const ll maxn = 2e2 + 16 , maxk = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

int dp[maxn][maxn][maxk];
vector<ll> v;
// 636F
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	dp[0][0][0] = 1;
	ll n , k;
	cin>>n>>k;
	v.push_back(0);
	for(ll i = 1 ; i <= n ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
	}
	sort(all(v));
	for(ll i = 1 ; i <= n ; i++){
		ll b = v[i] - v[i - 1];
		for(ll j = 0 ; j <= i ; j++){
			for(ll q = 0 ; q <= k ; q++){
				ll res = 0 , h;
				if(q >= j * b){
					h = dp[i - 1][j][q - j * b] * (j + 1) % md;
					res += h;
				}
				if(j > 0 && q >= (j - 1) * b){
					h = dp[i - 1][j - 1][q - (j - 1) * b];
					res += h;
				}
				if(q >= (j + 1) * b){
					h = dp[i - 1][j + 1][q - (j + 1) * b] * (j + 1) % md;
					res += h;
				}
				res %= md;
				dp[i][j][q] = res;
			}
		}
	}
	ll ans = 0;
	for(ll q = 0 ; q <= k ; q++) ans += dp[n][0][q];
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}