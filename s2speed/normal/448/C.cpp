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

ll a[MAXN];

ll dv(ll h , ll l , ll r){
	if(r == l) return 0;
	ll m = inf , res = r - l , e = 0;
	for(ll i = l ; i < r ; i++){
		m = min(m , a[i]);
	}
	e = m - h;
	ll o = l;
	for(ll i = l ; i < r ; i++){
		if(a[i] == m){
			e += dv(a[i] , o , i);
			o = i + 1;
		}
	}
	e += dv(m , o , r);
	res = min(res , e);
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	cout<<dv(0 , 0 , n)<<'\n';
	return 0;
}

/*
7
1 2 3 2 4 2 3 1
*/