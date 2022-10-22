#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll {ll first , second , third;};
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

ll a[MAXN] , b[MAXN] , n , k;

bool check(ll x){
	ll h = k;
	for(ll i = 0 ; i < n ; i++){
		ll q = 1ll * a[i] * x;
		if(q <= b[i]) continue;
		h -= q - b[i];
		if(h < 0) return 0;
	}
	return 1;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	ll l = -1 , r = 2e9 + 1;
	while(l < r - 1){
		ll m = (l + r) / 2;
		if(check(m)){
			l = m;
		} else {
			r = m;
		}
	}
	cout<<l<<'\n';
	return 0;
}

/*

*/