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

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n; 
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i += 2){
		ll cur = 0 , mn = 0;
		for(ll j = i + 1 ; j < n ; j += 2){
			if(j != i + 1){
				cur -= a[j - 2];
				mn = min(cur , mn);
				cur += a[j - 1];
			}
			if(-mn > a[i]) break;
			ll h = a[i] + mn , o = cur - mn;
			if(o > a[j]) continue;
			ll k = a[j] - o;
			ans += min(h , k) + (mn < 0);
		}
	}
	cout<<ans<<'\n';
	return 0;
}