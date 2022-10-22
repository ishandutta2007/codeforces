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

const ll maxn = 4e6 + 16 , inf = 2e16;
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
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

int dp[maxn];
vector<short int> v[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	ll n , cur = 0 , ps , sq;
	cin>>n>>md; sq = sqrt(n);
	ps = dp[1] = 1;
	for(ll i = 100 ; i <= sq ; i++){
		for(ll j = i + 1 ; 1ll * j * i <= n ; j++){
			v[j * i].push_back(i);
		}
	}
	for(ll i = 2 ; i <= n ; i++){
		dp[i]++;
		if(2 * i <= n) dp[2 * i]--;
		for(auto j : v[i]){
			ll o = i / j;
			dp[i] += dp[o]; dp[i] %= md;
			if(i + j <= n){
				dp[i + j] -= dp[o]; dp[i + j] %= md;
			}
		}
		cur += dp[i]; cur %= md;
		dp[i] = cur + ps;
		dp[i] %= md;
		ps += dp[i]; ps %= md;
		for(ll j = 2 ; j <= i && j * i <= n ; j++){
			ll o = j * i;
			dp[o] += dp[j]; dp[o] %= md;
			if(o + i <= n){
				dp[o + i] -= dp[j]; dp[o + i] %= md;
			}
		}
		for(ll j = 2 ; j < 100 && j < i ; j++){
			ll o = j * i;
			if(o > n) break;
			dp[o] += dp[i]; dp[o] %= md;
			if(o + j <= n){
				dp[o + j] -= dp[i]; dp[o + j] %= md;
			}
		}
	}
	ll ans = dp[n];
	if(ans < 0) ans += md;
	cout<<ans<<'\n';
	return 0;
}