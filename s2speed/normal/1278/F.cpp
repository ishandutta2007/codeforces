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

const ll maxn = 5e3 + 16 , md = 998244353 , inf = 2e16;

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

ll chs[maxn][maxn] , dp[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(chs , 0 , sizeof(chs));
	chs[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			chs[i][j] = chs[i - 1][j - 1] + chs[i - 1][j];
			chs[i][j] -= (chs[i][j] >= md) * md;
		}
	}
	ll n , m , k;
	cin>>n>>m>>k;
	for(ll i = 1 ; i <= k ; i++){
		dp[i] = tav(i , k);
		for(ll j = 1 ; j < i ; j++){
			ll h = dp[j] * chs[i][j] % md;
			dp[i] -= h;
		}
		dp[i] %= md; dp[i] += (dp[i] < 0) * md;
	}
	ll z = 1 , p = 1 , im = tav(m , md - 2) , ans = 0;
	for(ll i = 1 ; i <= k ; i++){
		z *= (n - i + 1); z %= md;
		z *= tav(i , md - 2); z %= md;
		p *= im; p %= md;
		ll h = z * p % md * dp[i] % md;
		ans += h;
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}