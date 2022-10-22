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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 20 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

void solve(){
	ll x , y , r = 0 , u = 0 , d = 0 , l = 0;
	cin>>x>>y;
	string s;
	cin>>s; ll n = s.size();
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == 'U'){
			u++;
		}
		if(s[i] == 'D'){
			d++;
		}
		if(s[i] == 'L'){
			l++;
		}
		if(s[i] == 'R'){
			r++;
		}
	}
	if(x < 0){
		if(l < abs(x)){
			cout<<"NO\n";
			return;
		}
	} else {
		if(r < x){
			cout<<"NO\n";
			return;
		}
	}
	if(y < 0){
		if(d < abs(y)){
			cout<<"NO\n";
			return;
		}
	} else {
		if(u < y){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/