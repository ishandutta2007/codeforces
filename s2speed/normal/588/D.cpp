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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll a[maxn];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k , l;
	l = 1e18; n = 5;
	cin>>n>>l>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < n ; i++){
		a[i] = lower_bound(all(v) , a[i]) - v.begin();
	}
	v.clear();
	for(ll i = 0 ; i < n ; i++) v.push_back(a[i]);
	sort(all(v)); v.push_back(inf);
	ll dp[n + 5][k + 5] , pd[k + 5];
	memset(dp , 0 , sizeof(dp));
	memset(pd , 0 , sizeof(pd));
	for(ll i = 0 ; i < n ; i++) dp[i][1] = 1;
	pd[1] = n;
	for(ll j = 2 ; j <= k ; j++){
		ll cur = 0 , x = 0;
		for(ll i = 0 ; i < n ; i++){
			while(v[x] == i){
				cur += dp[i][j - 1]; cur %= md;
				x++;
			}
			dp[i][j] = cur;
		}
		for(ll i = 0 ; i < n ; i++){
			pd[j] += dp[a[i]][j];
		}
		pd[j] %= md;
	}
	ll ans = 0 , c = l / n , lm = l % n;
	for(ll j = 1 ; j <= k && j <= c ; j++){
		ll h = 1ll * (c - j + 1) % md * pd[j] % md;
		ans += h;
	}
	ans %= md;
	for(ll j = 1 ; j <= k && j <= c + 1 ; j++){
		for(ll i = 0 ; i < lm ; i++){
			ans += dp[a[i]][j];
		}
		ans %= md;
	}
	cout<<ans<<'\n';
	return 0;
}