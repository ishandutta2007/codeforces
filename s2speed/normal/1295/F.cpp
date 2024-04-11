#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e2 + 15 , MAX = 1e6 + 15 , md = 998244353 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

ll w[MAXN] , t[MAXN] , p[MAXN] , chs[MAXN][MAXN] , dp[MAXN][MAXN] , ps[MAXN][MAXN] , l[MAXN] , r[MAXN];
vector<pll> v;

ll dv(ll x , ll i){
	ll res = 1ll * x * t[i] % md;
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(l , -1 , sizeof(l));
	memset(dp , 0 , sizeof(dp));
	ll n , o = 1;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		p[i] = tav(i , md - 2);
	}
	for(ll i = 0 ; i < n ; i++){
		ll l , r;
		cin>>l>>r; r++;
		o *= r - l; o %= md;
		v.push_back({l , n - i - 1}); v.push_back({r , n - i - 1});
	}
	sort(all(v));
	for(ll i = 0 ; i < 2 * n ; i++){
		pll p = v[i];
		ll x = p.first , j = p.second;
		if(l[j] == -1){
			l[j] = i;
		} else {
			r[j] = i;
		}
		if(i + 1 < 2 * n){
			w[i] = v[i + 1].first - x;
			t[i] = tav(w[i] , md - 2);
		}
	}
	t[2 * n] = tav(2 , md - 2);
	for(ll i = 0 ; i < 2 * n - 1 ; i++){
		chs[i][1] = w[i];
		for(ll j = 2 ; j <= n ; j++){
			ll h = chs[i][j - 1];
			h *= w[i] + j - 1; h %= md;
			h *= p[j]; h %= md;
			chs[i][j] = h;
		}
	}
	for(ll j = l[0] ; j < r[0] ; j++){
		dp[0][j] = w[j];
	}
	ps[0][0] = dp[0][0];
	for(ll j = 1 ; j < 2 * n - 1 ; j++){
		ps[0][j] = (ps[0][j - 1] + dp[0][j]) % md;
	}
	for(ll i = 1 ; i < n ; i++){
		for(ll j = l[i] ; j < r[i] ; j++){
			ll h = 0;
			bool br = false;
			for(ll q = i ; q >= 0 ; q--){
				if(j < l[q] || j >= r[q]){
					br = true;
					break;
				}
				ll e = 1;
				if(q > 0 && j > 0){
					e *= ps[q - 1][j - 1];
				}
				e *= chs[j][i - q + 1];
				h += e % md;
			}
			if(br && j == 0){
				h = 0;
			}
			h %= md;
			dp[i][j] = h;
		}
		ps[i][0] = dp[i][0];
		for(ll j = 1 ; j < 2 * n - 1 ; j++){
			ps[i][j] = (ps[i][j - 1] + dp[i][j]) % md;
		}
	}
	ll ans = ps[n - 1][2 * n - 2];
	ans %= md;
	ans = 1ll * ans * tav(o , md - 2) % md;
	cout<<ans<<'\n';
	return 0;
}

/*

*/