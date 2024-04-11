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

const ll maxn = 5e5 + 16 , md = 998244353 , inf = 2e18;

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

ll dp[maxn] , pd[maxn] , fp[maxn] , fd[maxn] , a[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) cin>>a[i];
	for(ll i = 0 ; i <= n ; i++){
		dp[i] = pd[i] = fp[i] = fd[i] = 0;
	}
	for(ll i = 0 ; i < n ; i++){
		ll r = a[i] , h = (r == 0);
		if(r > 0){
			h += fd[r - 1];
		}
		h += fd[r];
		dp[i] = h % md;
		h = (r == 1);
		if(r > 1){
			h += fd[r - 2];
		}
		h += fp[r];
		pd[i] = h % md;
		fp[r + 2] <<= 1; fp[r + 2] %= md;
		fd[r] += dp[i]; fd[r] %= md;
		fp[r] += pd[i]; fp[r] %= md;
	}
	ll ans = 0;
	for(ll i = 0 ; i <= n ; i++){
		ans += fd[i] + fp[i];
	}
	ans %= md;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}