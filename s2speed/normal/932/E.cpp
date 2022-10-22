#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e3 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll dv(ll a , ll b){
	return 1ll * a * tav(b , md - 2) % md;
}

ll chs[maxn] , ch[maxn][maxn] , dp[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ch , 0 , sizeof(ch));
	ll n , k;
	cin>>n>>k;
	chs[0] = 1;
	for(ll i = 1 ; i <= k ; i++){
		chs[i] = 1ll * chs[i - 1] * (n - i + 1) % md;
		chs[i] = dv(chs[i] , i);
	}
	ch[0][0] = 1;
	for(ll i = 1 ; i <= k ; i++){
		ch[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			ch[i][j] = ch[i - 1][j - 1] + ch[i - 1][j]; if(ch[i][j] >= md) ch[i][j] -= md;
		}
	}
	dp[1] = 1;
	for(ll i = 2 ; i <= k ; i++){
		dp[i] = tav(i , k);
		for(ll j = 1 ; j < i ; j++){
			ll h = 1ll * dp[i - j] * ch[i][j] % md;
			dp[i] -= h;
		}
		dp[i] %= md;
		if(dp[i] < 0) dp[i] += md;
	}
	ll lm = min(n , k);
	ll ans = 0 , o = tav(2 , n - lm);
	for(ll i = lm ; i > 0 ; i--){
		ll h = 1ll * dp[i] * chs[i] % md * o % md;
		ans += h;
		o <<= 1; if(o >= md) o -= md;
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}