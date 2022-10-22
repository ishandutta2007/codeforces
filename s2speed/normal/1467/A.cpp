#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7 , inf = 1e17;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

void solve(){
	int n;
	cin>>n;
	string s;
	if(n == 1){
		cout<<9<<'\n';
		return;
	}
	s += '9';
	s += '8';
	char c = '9';
	for(int i = 2 ; i < n ; i++){
		s += c;
		if(c == '9'){
			c = '0';
		} else {
			c++;
		}
	}
	cout<<s<<'\n';
}

int main(){ // check MAX_N
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

/*

*/