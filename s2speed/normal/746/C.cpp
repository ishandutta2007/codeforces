#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e9;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll s , x1 , x2 , t1 , t2 , p , d , ans = inf , h , l;
	cin>>s>>x1>>x2>>t1>>t2>>p>>d;
	ans = abs(x1 - x2) * t2;
	if(x1 > x2){
		x1 = s - x1;
		x2 = s - x2;
		p = s - p;
		d = -d;
	}
	if(p <= x1 && d == 1){
		l = x2 - p;
	}
	if(p <= x1 && d == -1){
		l = x2 + p;
	}
	if(p > x1 && d == -1){
		l = p + x2;
	}
	if(p > x1 && d == 1){
		l = 2 * s - p + x2;
	}
	h = l * t1;
	ans = min(ans , h);
	cout<<ans<<'\n';
	return 0;
}

/*

*/