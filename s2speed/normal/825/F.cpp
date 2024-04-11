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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 8e3 + 16 , md = 2000000357 , inf = 63 * 257;

 
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

ll t[maxn] , h[maxn] , d[maxn];
short int cnt[maxn][maxn] , dp[maxn][maxn] , pd[maxn];

void d_build(){
	d[1] = 1;
	ll q = 10;
	for(ll i = 2 ; i < maxn ; i++){
		d[i] = d[i - 1] + (i == q);
		if(i == q) q *= 10;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	memset(cnt , 0 , sizeof(cnt));
	memset(pd , 63 , sizeof(pd));
	d_build();
	ll n , P = 131;
	string s;
	t[0] = 1;
	for(int i = 1 ; i < maxn ; i++){
		t[i] = 1ll * P * t[i - 1] % md;
	}
	cin>>s; n = sze(s);
	h[n - 1] = s[n - 1];
	for(ll i = n - 2 ; i >= 0 ; i--){
		h[i] = (1ll * P * h[i + 1] + s[i]) % md;
	}
	dp[n - 1][1] = pd[n - 1] = 2; cnt[n - 1][1] = 1; pd[n] = 0;
	for(ll i = n - 2 ; i >= 0 ; i--){
		ll lm = n - i;
		for(ll j = 1 ; j <= lm ; j++){
			dp[i][j] = pd[i + j] + j + 1;
			cnt[i][j] = 1;
			pd[i] = min(pd[i] , dp[i][j]);
			if(dp[i + j][j] == inf) continue; 
			ll a = (h[i] - 1ll * t[j] * h[i + j] % md + md) % md , b = (h[i + j] - 1ll * t[j] * h[i + (j << 1)] % md + md) % md , o = dp[i][j];
			if(a != b) continue;
			cnt[i][j] = cnt[i + j][j] + 1;
			for(ll k = 2 ; k <= cnt[i][j] ; k++){
				o = min(o , pd[i + k * j] + d[k] + j);
			}
			dp[i][j] = o;
			pd[i] = min(pd[i] , dp[i][j]);
		}
	}
	cout<<pd[0]<<'\n';
	return 0;
}