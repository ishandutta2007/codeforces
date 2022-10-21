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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dis[maxn] , b[maxn] , c[maxn] , dp[maxn];

void solve(){
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	ll sum = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>c[i];
		sum += c[i];
	}
	if(k >= 12 * n){
		cout<<sum<<'\n';
		return;
	}
	for(ll i = 0 ; i <= k ; i++) dp[i] = 0;
	for(ll i = 0 ; i < n ; i++){
		ll h = dis[b[i]] , w = c[i];
		for(ll j = k ; j >= h ; j--){
			dp[j] = max(dp[j] , dp[j - h] + w);
		}
	}
	cout<<dp[k]<<'\n';
	return;
}

/*
1
4 4
1 7 5 2
2 6 5 2
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	dis[1] = 0;
	ll lm = 1e3 , hm = 0;
	for(ll i = 1 ; i <= lm ; i++){
		for(ll j = 1 ; j <= i ; j++){
			ll h = i + i / j;
			dis[h] = min(dis[h] , dis[i] + 1);
		}
		hm = max(hm , dis[i]);
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}