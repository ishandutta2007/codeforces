#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

void solve(){
	ll n , x , h , p , g = 0;
	cin>>n>>x>>p;
	for(int i = 1 ; i < n ; i++){
		cin>>h;
		g = gcd(g , abs(h - p));
		p = h;
	}
	h = p % g; h += g; h %= g;
	x %= g; x += g; x %= g;
	cout<<(x == h ? "YES\n" : "NO\n");
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

/*

*/