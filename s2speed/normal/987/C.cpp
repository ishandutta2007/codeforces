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

ll a[maxn] , b[maxn] , p[maxn] , s[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	for(ll i = 0 ; i < n ; i++){
		ll m = inf;
		for(ll j = 0 ; j < i ; j++){
			if(a[j] < a[i]){
				m = min(m , b[j]);
			}
		}
		p[i] = m;
	}
	for(ll i = 0 ; i < n ; i++){
		ll m = inf;
		for(ll j = i + 1 ; j < n ; j++){
			if(a[j] > a[i]){
				m = min(m , b[j]);
			}
		}
		s[i] = m;
	}
	ll ans = inf;
	for(ll i = 0 ; i < n ; i++){
		ans = min(ans , p[i] + s[i] + b[i]);
	}
	cout<<(ans == inf ? -1 : ans)<<'\n';
	return 0;
}