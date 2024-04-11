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

const ll MAXN = 3e5 + 15 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

vector<ll> v;

ll bs(ll x){
	if(x < 5) return 0;
	ll l = 0 , r = v.size();
	while(l < r - 1){
		ll m = (r + l) / 2;
		if(v[m] > x){
			r = m;
		} else {
			l = m;
		}
	}
	return l + 1;
}

void solve(){
	ll n;
	cin>>n;
	cout<<bs(n)<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll i = 3 ; i < inf ; i += 2){
		ll h = 1ll * i * i;
		if(h > 1e10) break;
		v.push_back(h / 2 + 1);
	}
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/