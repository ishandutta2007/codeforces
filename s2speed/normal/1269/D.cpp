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

const ll MAXN = 3e5 + 15 , md = 1e9 + 7 , inf = 1e18;

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

	ll n , cnt = 0 , sum = 0;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		ll q = i % 2 - (i - 1) % 2 , h;
		cin>>h;
		sum += h;
		cnt += q * (h % 2);
	}
	sum -= abs(cnt);
	cout<<sum / 2<<'\n';
	return 0;
}

/*
4
3 3 3 3
*/