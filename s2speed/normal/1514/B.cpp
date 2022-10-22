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

void solve(){
	ll n , k;
	cin>>n>>k;
	cout<<tav(n , k)<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}