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

ll a[maxn];

void solve(){
	ll n , ans = inf;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll z = 0;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] % 3){
			z = inf;
			break;
		}
		z = max(z , a[i] / 3);
	}
	ans = min(ans , z);
	z = 0;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] % 3 == 2){
			z = inf;
			break;
		}
		z = max(z , a[i] / 3);
	}
	ans = min(ans , z + 1);
	z = 0;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] % 3 == 1){
			z = inf;
			break;
		}
		z = max(z , a[i] / 3);
	}
	ans = min(ans , z + 1);
	z = 0;
	for(ll i = 0 ; i < n ; i++){
		z = max(z , (a[i] - 1) / 3);
	}
	ans = min(ans , z + 2);
	z = 0;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] == 1){
			z = inf;
			break;
		}
		if(a[i] % 3 == 1){
			z = max(z , a[i] / 3 - 1);
		} else {
			z = max(z , a[i] / 3);
		}
	}
	ans = min(ans , z + 2);
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