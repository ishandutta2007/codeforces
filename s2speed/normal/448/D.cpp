#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	return ((b == 0) ? a : gcd(b , a % b));
}

const ll MAXN = 2e5 + 15 , md = 1e6 + 3 , inf = 1e18;

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

ll n , m , k;

bool check(ll x){
	ll cnt = 0;
	for(ll i = 1 ; i <= n ; i++){
		ll h = min(m , x / i);
		cnt += h;
	}
	return (cnt >= k);
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m>>k;;
	ll l = 0 , r = 1ll * n * m + 1;
	while(l < r - 1){
		ll mid = 1ll * (l + r) / 2;
		if(check(mid)){
			r = mid;
		} else {
			l = mid;
		}
	}
	cout<<l + 1<<'\n';
	return 0;
}

/*

*/