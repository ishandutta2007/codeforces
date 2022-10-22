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

	string s , h;
	ll n;
	cin>>n>>s; h.resize(n);
	ll x = n / 2 - 1;
	if(n % 2){
		h[n / 2] = s[0];
	}
	for(ll i = 0 + n % 2 ; i < n ; i += 2){
		h[x--] = s[i];
	}
	x = n / 2 + n % 2;
	for(ll i = 1 + n % 2 ; i < n ; i += 2){
		h[x++] = s[i];
	}
	cout<<h<<'\n';
	return 0;
}

/*

*/