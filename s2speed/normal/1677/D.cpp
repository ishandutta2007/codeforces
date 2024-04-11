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

const ll maxn = 1e6 + 17 , md = 998244353 , inf = 2e16;

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

ll a[maxn];

void solve(){
	ll n , k;
	cin>>n>>k;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	ll ans = 1;
	for(ll i = 1 ; i <= k + 1 ; i++){
		ans *= i; ans %= md;
	}
	for(ll i = k + 2 ; i <= n ; i++){
		if(a[i - k] > 0) continue;
		ans *= (a[i - k] == 0 ? k + 1 : i); ans %= md;
	}
	for(ll i = n - k + 1 ; i <= n ; i++){
		if(a[i] > 0){
			ans = 0;
		}
	}
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