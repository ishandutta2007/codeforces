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

const ll maxn = 3e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll fact[maxn] , _fact[maxn];

void fact_build(){
	fact[0] = 1;
	_fact[0] = 1;
	for(int i = 1 ; i < maxn ; i++){
		fact[i] = 1ll * fact[i - 1] * i % md;
		_fact[i] = tav(fact[i] , md - 2);
	}
}

ll chs(ll n , ll k){
	if(k > n || k < 0 || n < 0) return 0;
	return 1ll * fact[n] * _fact[k] % md * _fact[n - k] % md;
}

ll dv(ll n , ll k){
	return 1ll * n * tav(k , md - 2) % md;
}


ll dp[maxn][3];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	ll n , q;
	cin>>n>>q; n *= 3;
	dp[n][0] = 1; dp[n][1] = n + 1; dp[n][2] = 1ll * (n + 1) * (n + 2) / 2 % md;
	for(ll i = n - 1 ; i > 0 ; i--){
		dp[i][0] = chs(n + 1 , i + 1) - dp[i + 1][0] + dp[i + 1][1] - chs(n + 1 , i + 1);
		dp[i][1] = chs(n + 2 , i + 1) - dp[i + 1][1] + dp[i + 1][2] - chs(n + 2 , i + 1);
		dp[i][2] = chs(n + 3 , i + 1) - dp[i + 1][2] + dp[i + 1][0];
		dp[i][0] %= md; dp[i][1] %= md; dp[i][2] %= md;
		if(dp[i][0] < 0) dp[i][0] += md;
		if(dp[i][1] < 0) dp[i][1] += md;
		if(dp[i][2] < 0) dp[i][2] += md;
	}
	for(ll i = 0 ; i < q ; i++){
		ll x;
		cin>>x;
		cout<<dp[x][0]<<'\n';
	}
	return 0;
}