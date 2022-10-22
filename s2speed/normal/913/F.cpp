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

const ll maxn = 2e3 + 16 , md = 998244353 , inf = 2e17;

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

ll q , p;
ll str[maxn] , pd[maxn][maxn] , tv[maxn] , vt[maxn] , dp[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(pd , 0 , sizeof(pd));
	ll n , h , o;
	cin>>n>>h>>o;
	q = dv(h , o); p = (md - q + 1) % md;
	tv[0] = vt[0] = 1;
	for(ll i = 1 ; i <= n ; i++){
		tv[i] = 1ll * tv[i - 1] * p % md;
		vt[i] = 1ll * vt[i - 1] * q % md;
	}
	str[1] = 1; pd[1][0] = pd[1][1] = 1;
	for(ll i = 2 ; i <= n ; i++){
		pd[i][i] = pd[i][0] = 1;
		o = 0;
		for(ll j = 1 ; j < i ; j++){
			h = 1ll * tv[j] * pd[i - 1][j] % md;
			pd[i][j] += h;
			h = 1ll * vt[i - j] * pd[i - 1][j - 1] % md;
			pd[i][j] += h; if(pd[i][j] >= md) pd[i][j] -= md;
			o += 1ll * pd[i][j] * str[j] % md;
		}
		o %= md;
		str[i] = (md - o + 1) % md;
	}
	dp[1] = 0;
	for(ll i = 2 ; i <= n ; i++){
		o = 0;
		for(ll j = 1 ; j < i ; j++){
			h = dp[j] + dp[i - j] + 1ll * j * (j - 1) / 2 + 1ll * j * (i - j);
			h %= md;
			h = 1ll * h * pd[i][j] % md * str[j] % md;
			o += h;
		}
		o %= md;
		h = (1 + md - str[i]) % md;
		o += 1ll * i * (i - 1) / 2 * str[i];
		o %= md;
		dp[i] = dv(o , h);
	}
	cout<<dp[n]<<'\n';
	return 0;
}