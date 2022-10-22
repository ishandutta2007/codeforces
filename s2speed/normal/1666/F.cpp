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

const ll maxn = 5e3 + 17 , md = 998244353 , inf = 2e18;

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

ll cnt[maxn] , dp[maxn] , pd[maxn] , fact[maxn] , _fact[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) dp[i] = pd[i] = cnt[i] = 0;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		cnt[h]++;
	}
	ll p = 0;
	ll lm = n >> 1;
	for(ll i = 0 ; i < n ; i++){
		if(!cnt[i]) continue;
		for(ll j = lm ; j ; j--){
			dp[j] += pd[j - 1] * cnt[i]; dp[j] %= md;
			ll h = max(0ll , p - (j << 1) + 1) * pd[j - 1] * cnt[i];
			pd[j] += h; pd[j] %= md;
		}
		p += cnt[i];
		pd[0] = p;
	}
	ll ans = dp[lm];
	for(ll i = 0 ; i < n ; i++){
		ans *= _fact[cnt[i]]; ans %= md;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = fact[i - 1] * i % md;
	}
	_fact[maxn - 1] = tav(fact[maxn - 1] , md - 2);
	for(ll i = maxn - 2 ; ~i ; i--){
		_fact[i] = _fact[i + 1] * (i + 1) % md;
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}