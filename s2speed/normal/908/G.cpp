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

const ll maxn = 7e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][12] , chs[maxn][maxn] , tv[12][maxn] , ps[maxn] , cnt[12] , res[12];
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	memset(cnt , 0 , sizeof(cnt));
	memset(res , 0 , sizeof(res));
	memset(chs , 0 , sizeof(chs));
	chs[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		chs[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			chs[i][j] = chs[i - 1][j - 1] + chs[i - 1][j];
			chs[i][j] -= (chs[i][j] >= md) * md;
		}
	}
	for(ll j = 0 ; j <= 10 ; j++){
		tv[j][0] = 1;
		for(ll i = 1 ; i < maxn ; i++){
			tv[j][i] = tv[j][i - 1] * j % md;
		}
	}
	ps[0] = 0;
	for(ll i = 1 ; i < maxn ; i++){
		ps[i] = ps[i - 1] + tv[10][i - 1];
		ps[i] -= (ps[i] >= md) * md;
	}
	ll n;
	cin>>s; n = sze(s);
	for(ll j = 0 ; j < 10 ; j++){
		dp[1][j] = 1;
	}
	for(ll i = 2 ; i < n ; i++){
		for(ll k = 0 ; k < 10 ; k++){
			for(ll j = 0 ; j < 10 ; j++){
				dp[i][j] += dp[i - 1][j] * (k > j ? 10 : 1);
			}
			for(ll q = 0 ; q < i ; q++){
				ll h = 1ll * chs[i - 1][q] * tv[10 - k][q] % md * tv[k][i - q - 1] % md * tv[10][q] % md;
				dp[i][k] += h;
			}
		}
		for(ll j = 0 ; j < 10 ; j++) dp[i][j] %= md;
	}
	for(ll i = 0 ; i < n ; i++){
		ll c = s[i] - '0';
		cnt[0]++;
		for(ll k = 0 ; k < c ; k++){
			ll o = 0;
			for(ll j = 9 ; j >= 0 ; j--){
				res[j] += dp[n - i - 1][j] * tv[10][o] % md;
				for(ll q = 0 ; q < n - i ; q++){
					ll h = 1ll * chs[n - i - 1][q] * tv[10 - j][q] % md * tv[j][n - i - 1 - q] % md * tv[10][q + o] % md * ps[cnt[j]] % md;
					res[j] += h;
				}
				o += cnt[j];
			}
			cnt[k]--;
			cnt[k + 1]++;
		}
	}
	ll ans = 0;
	for(ll j = 1 ; j < 10 ; j++){
		ans += res[j] * j % md;
	}
	sort(all(s));
	for(ll i = 0 ; i < n ; i++){
		ans += (s[i] - '0') * tv[10][n - i - 1];
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}