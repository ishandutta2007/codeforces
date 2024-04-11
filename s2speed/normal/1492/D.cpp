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

string s , h;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a , b , k;
	cin>>a>>b>>k;
	if(k == 0){
		for(ll i = 0 ; i < b ; i++){
			s += '1';
		}
		for(ll i = 0 ; i < a ; i++){
			s += '0';
		}
		cout<<"Yes\n"<<s<<'\n'<<s<<'\n';
		return 0;
	}
	if(a == 0 || b == 1){
		cout<<"No\n";
		return 0;
	}
	if(k > a + b - 2){
		cout<<"No\n";
		return 0;
	}
	ll lm = a + b;
	for(ll i = 0 ; i < lm ; i++){
		s += '0';
	}
	h = s;
	s[0] = '1'; s[1] = '1';
	h[0] = '1';
	ll x = 1 + k;
	h[x] = '1';
	b -= 2;
	ll cnt = 0;
	for(ll i = 2 ; cnt < b ; i++){
		if(i == x) continue;
		s[i] = '1';
		h[i] = '1';
		cnt++;
	}
	cout<<"Yes\n"<<s<<'\n'<<h<<'\n';
	return 0;
}

/*

*/