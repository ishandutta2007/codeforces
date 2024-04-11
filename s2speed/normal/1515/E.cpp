#include<bits/stdc++.h>
#include<fstream>
 
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
struct plll { ll x , y , z; };
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 4e2 + 16 , inf = 2e17;
ll md;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k >>= 1;
	}
	return res;
}

ll fact[maxn] , fact_md[maxn];

void fact_build(){
	fact[0] = 1;
	fact_md[0] = 1;
	for(int i = 1 ; i < maxn ; i++){
		fact[i] = 1ll * fact[i - 1] * i % md;
		fact_md[i] = tav(fact[i] , md - 2);
	}
}

ll chs(ll n , ll k){
	if(k > n || k < 0) return 0;
	return (((fact[n] * fact_md[k]) % md) * fact_md[n - k]) % md;
}

ll hc[maxn][maxn] , ch[maxn][maxn];
ll dp[maxn][maxn] , pd[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(dp , 0 , sizeof(dp));
	ll n;
	cin>>n>>md;
	fact_build();
	for(ll i = 0 ; i <= n ; i++){
		for(ll j = 0 ; j <= i ; j++){
			ch[i][j] = chs(i , j);
			hc[i][j] = tav(ch[i][j] , md - 2);
		}
	}
	pd[1][0] = 1;
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 1 ; j <= n ; j++){
			for(ll k = 0 ; k < i ; k++){
				dp[j][k] = pd[j - 1][k];
				dp[j][k] *= hc[j - 1][i - k]; dp[j][k] %= md;
				dp[j][k] *= ch[j][i - k + 1] << 1; dp[j][k] %= md;
			}
			for(ll k = 0 ; k < i ; k++){
				dp[j][i + 1] += pd[j][k]; if(dp[j][i + 1] >= md) dp[j][i + 1] -= md;
			}
			dp[j][i] = 1ll * j * pd[j - 1][i] % md;
		}
		memcpy(pd , dp , sizeof(pd));
	}
	ll ans = 0;
	for(ll j = 1 ; j <= n ; j++){
		for(ll k = 0 ; k < n ; k++){
			ans += dp[j][k];
		}
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}