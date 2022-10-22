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

const ll maxn = 16 , maxk = 5e6 , maxm = (1 << 14) + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , tv[maxn] , p[maxn][maxn];
ll w[maxk] , dp[maxm] , l[maxm][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++) tv[i] = tv[i - 1] * 3;
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		p[i][i] = 0;
		for(ll j = 0 ; j < n ; j++){
			if(i == j) continue;
			p[i][j] = dv(a[i] , a[i] + a[j]);
		}
	}
	ll lm = 1 << n;
	for(ll mask = 0 ; mask < lm ; mask++){
		for(ll i = 0 ; i < n ; i++){
			ll h = 1;
			for(ll j = 0 ; j < n ; j++){
				if(mask & (1 << j)){
					h *= p[j][i]; h %= md;
				}
			}
			l[mask][i] = h;
		}
	}
	lm = tv[n];
	for(ll mask = 0 ; mask < lm ; mask++){
		ll cnt[] = {0 , 0 , 0} , msk[] = {0 , 0 , 0} , a[maxn] , v;
		ll h = mask;
		for(ll j = 0 ; j < n ; j++){
			cnt[a[j] = h % 3]++;
			msk[a[j]] += 1 << j;
			if(a[j] == 1) v = j;
			h /= 3;
		}
		if(cnt[1] == 0){
			w[mask] = 1;
			continue;
		}
		w[mask] = w[mask - tv[v]] * l[msk[2]][v] % md;
	}
	lm = 1 << n;
	ll ans = 0;
	for(ll mask = 1 ; mask < lm ; mask++){
		dp[mask] = 1;
		for(ll sub = (mask - 1) & mask ; sub ; sub = (sub - 1) & mask){
			ll msk = 0 , h;
			for(ll j = 0 ; j < n ; j++){
				if(!(mask & (1 << j))) continue;
				msk += tv[j];
				if(sub & (1 << j)){
					msk += tv[j];
				}
			}
			h = 1ll * dp[sub] * w[msk] % md;
			dp[mask] -= h;
		}
		dp[mask] %= md; if(dp[mask] < 0) dp[mask] += md;
		ll h , msk = 0;
		for(ll j = 0 ; j < n ; j++){
			msk += tv[j];
			if(mask & (1 << j)){
				msk += tv[j];
			}
		}
		h = 1ll * dp[mask] * w[msk] % md * __builtin_popcount(mask) % md;
		ans += h;
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}