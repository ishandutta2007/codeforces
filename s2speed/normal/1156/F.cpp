#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;

const ll MAXN = 5e3 + 20 , md = 998244353;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

ll dp[MAXN][MAXN] , cnt[MAXN] , last[MAXN] , ps[MAXN][MAXN];
vector<ll> a;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(dp , 0 , sizeof(dp));
	memset(ps , 0 , sizeof(ps));
	ll n;
	cin>>n;
	a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		cnt[a[i]]++;
	}
	sort(all(a));
	last[0] = -1;
	for(ll i = 1 ; i < n ; i++){
		last[i] = last[i - 1];
		if(a[i] != a[i - 1]){
			last[i] = i - 1;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		dp[0][i] = 1;
		ps[0][i] = i + 1;
	}
	ll ans = 0 , h = tav(n , md - 2) * tav(n - 1 , md - 2) % md;
	for(ll i = 0 ; i < n ; i++){
		ll res = 1ll * (cnt[a[i]] - 1) * h % md;
		ans += res;
	}
	for(ll j = 1 ; j < n - 1 ; j++){
		h *= tav(n - j - 1 , md - 2); h %= md;
		for(ll i = 1 ; i < n ; i++){
			if(last[i] == -1){
				dp[j][i] = 0;
				ps[j][i] = ps[j][i - 1];
				continue;
			}
			dp[j][i] = ps[j - 1][last[i]];
			ll res = 1ll * dp[j][i] * (cnt[a[i]] - 1) % md; res *= h; res %= md;
			ans += res;
			ps[j][i] += ps[j][i - 1] + dp[j][i]; ps[j][i] %= md;
		}
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}