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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

void solve(){
	string s;
	ll n;
	cin>>s; n = s.size();
	bool ans = true , ch = true;
	for(ll i = 1 ; i < n ; i++){
		if(s[i] == s[i - 1]){
			if(s[i] == '1'){
				ch = false;
			} else {
				ans &= ch;
			}
		}
	}
	ch = true;
	for(ll i = n - 2 ; i >= 0 ; i--){
		if(s[i] == s[i + 1]){
			if(s[i] == '0'){
				ch = false;
			} else {
				ans &= ch;
			}
		}
	}
	cout<<(ans ? "YES\n" : "NO\n");
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}