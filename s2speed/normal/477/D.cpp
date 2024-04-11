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

const ll maxn = 5e3 + 16 , md = 1e9 + 7;
ll inf;

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

bitset<maxn> mark , cmp[maxn];
ll rl[maxn][maxn] , dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin>>s;
	ll n = sze(s);
	for(ll i = 0 ; i < n ; i++){
		mark[i] = (s[i] == '1');
	}
	for(ll j = 1 ; j < n ; j++){
		rl[n - j][j] = 1e12;
		for(ll i = n - 1 - j ; i >= 0 ; i--){
			if(mark[i] == mark[i + j]){
				rl[i][j] = rl[i + 1][j] + 1;
			} else {
				rl[i][j] = 0;
			}
		}
	}
	for(ll j = 1 ; j < n ; j++){
		cmp[n - j][j] = true;
		for(ll i = n - 1 - j ; i >= 0 ; i--){
			if(mark[i] && !mark[i + j]){
				cmp[i][j] = true;
				continue;
			}
			if(!mark[i] && mark[i + j]){
				cmp[i][j] = false;
				continue;
			}
			if(rl[i][j] >= j){
				cmp[i][j] = false;
			} else {
				cmp[i][j] = cmp[i + 1][j];
			}
		}
	}
	memset(dp , 0 , sizeof(dp));
	dp[0][0] = 1;
	for(ll i = 0 ; i < n - 1 ; i++){
		for(ll j = 0 ; j <= i ; j++){
			dp[i][j] %= md;
			dp[i + 1][j] += dp[i][j];
			if(mark[i + 1]){
				if(cmp[j][i - j + 1] && i + i - j + 2 < n){
					dp[i + i - j + 2][i + 1] += dp[i][j];
				} else if(!cmp[j][i - j + 1]){
					dp[i + i - j + 1][i + 1] += dp[i][j];
				}
			}
		}
	}
	ll ans = 0;
	for(ll j = 0 ; j < n ; j++){
		ans += dp[n - 1][j];
	}
	ans %= md;
	cout<<ans<<'\n';
	memset(dp , 63 , sizeof(dp)); inf = dp[0][0];
	dp[0][0] = 1;
	for(ll i = 0 ; i < n - 1 ; i++){
		for(ll j = 0 ; j <= i ; j++){
			dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j]);
			if(mark[i + 1]){
				if(cmp[j][i - j + 1] && i + i - j + 2 < n){
					dp[i + i - j + 2][i + 1] = min(dp[i][j] + 1 , dp[i + i - j + 2][i + 1]);
				} else if(!cmp[j][i - j + 1]){
					dp[i + i - j + 1][i + 1] = min(dp[i][j] + 1 , dp[i + i - j + 1][i + 1]);
				}
			}
		}
	}
	ans = inf;
	ll cur = 0 , o = 1;
	bool ch = false;
	for(ll j = n - 1 ; j >= 0; j--){
		ll h = dp[n - 1][j];
		cur += o * mark[j];
		if(cur >= md){
			if(ans != inf) break;
			cur -= md;
			ch = true;
		}
		o <<= 1; if(o >= md) o -= md;
		if(h == inf) continue;
		if(ch){
			ans = h + cur;
			break;
		}
		ans = min(ans , h + cur);
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}