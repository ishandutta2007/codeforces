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

ll cnt[26][2];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	string s , t;
	cin>>s>>t;
	ll n = s.size() , m = t.size();
	for(ll i = 0 ; i < n ; i++){
		cnt[s[i] - 'a'][0]++;
	}
	for(ll i = 0 ; i < m ; i++){
		cnt[t[i] - 'a'][1]++;
	}
	bool ch = true;
	for(ll i = 0 ; i < 26 ; i++){
		ch &= (cnt[i][0] == cnt[i][1]);
	}
	if(ch){
		cout<<"array\n";
		return 0;
	}
	ll x = 0;
	for(ll i = 0 ; i < n && x < m ; i++){
		if(s[i] == t[x]) x++;
	}
	if(x == m){
		cout<<"automaton\n";
		return 0;
	}
	ch = true;
	for(ll i = 0 ; i < 26 ; i++){
		ch &= (cnt[i][0] >= cnt[i][1]);
	}
	if(ch){
		cout<<"both\n";
	} else {
		cout<<"need tree\n";
	}
	return 0;
}

/*

*/