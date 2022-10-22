#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

ll c;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= c;
		}
		n *= n; n %= c;
		k >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>c;
	ll p = 1 , cnt = 1;
	for(ll i = 2 ; i < c ; i++){
		if(gcd(i , c) == 1){
			cnt++;
			p *= i; p %= c;
		}
	}
	if(p == 1){
		cout<<cnt<<'\n';
		for(ll i = 1 ; i < c ; i++){
			if(gcd(i , c) == 1) cout<<i<<' ';
		}
		cout<<'\n';
		return 0;
	}
	cout<<cnt - 1<<'\n';
	for(ll i = 1 ; i < c ; i++){
		if(gcd(i , c) != 1) continue;
		if(1ll * tav(i , cnt - 1) * p % c == 1){
			p = 1;
		} else {
			cout<<i<<' ';
		}
	}
	cout<<'\n'; 
	return 0;
}