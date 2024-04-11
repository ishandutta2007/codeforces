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

const ll maxn = 1e3 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxn] , f[maxn];
string s[52];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = 1 ; j <= i ; j++){
			ll h = dp[i - 1][j - 1] + dp[i - 1][j] * j;
			dp[i][j] = h % md;
		}
	}
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = 1 ; j <= i ; j++) f[i] += dp[i][j];
		f[i] %= md;
	}
	ll m , n;
	cin>>m>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>s[i];
	}
	for(ll j = 0 ; j < m ; j++){
		ll h = 0;
		for(ll i = 0 ; i < n ; i++){
			ll o = s[i][j] ^ '0';
			h += (1ll << i) * o;
		}
		v.push_back(h);
	}
	sort(all(v));
	ll cur = 1 , ans = 1;
	for(ll i = 1 ; i < m ; i++){
		if(v[i] != v[i - 1]){
			ans *= f[cur]; ans %= md;
			cur = 0;
		}
		cur++;
	}
	ans *= f[cur]; ans %= md;
	cout<<ans<<'\n';
	return 0;
}