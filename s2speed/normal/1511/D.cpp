#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define size(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e18;
 
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

string s;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , k;
	cin>>n>>k; k--;
	s = "aa";
	for(ll i = 1 ; i <= k ; i++){
		s += 'a' + i;
		s += 'a' + i;
		for(ll j = 1 ; j < i ; j++){
			s += 'a' + j;
			s += 'a' + i;
		}
		s += 'a';
	}
	ll sz = size(s) - 1;
	for(ll i = 0 ; i < n ; i++){
		cout<<s[i % sz];
	}
	cout<<'\n';
	return 0;
}