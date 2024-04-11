#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,no-stack-protector")

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

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 1e18;

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

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , k , ans = 0;
	cin>>n>>m>>k; k += 2;
	if(k > n + m){
		cout<<"-1\n";
		return 0;
	}
	ll sq = sqrt(n);
	for(ll i = 1 ; i <= sq ; i++){
		ll h = n / i , o = k - i;
		h *= m / (o > 0 ? o : 1);
		ans = max(ans , h);
	}
	for(ll i = 1 ; i <= sq ; i++){
		ll h = i , q = n / i , o = k - q;
		h *= m / (o > 0 ? o : 1);
		ans = max(ans , h);
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/