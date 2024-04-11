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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e18;

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

vector<ll> x , y;

void solve(){
	x.clear(); y.clear();
	db ans = 0;
	ll n;
	cin>>n;
	for(ll i = 0 ; i < 2 * n ; i++){
		ll a , b;
		cin>>a>>b;
		if(a == 0){
			x.push_back(abs(b));
		} else {
			y.push_back(abs(a));
		}
	}
	sort(all(x));
	sort(all(y));
	for(ll i = 0 ; i < n ; i++){
		ll h = 1ll * x[i] * x[i] + 1ll * y[i] * y[i];
		db res = sqrt(h);
		ans += res;
	}
	cout<< fixed << setprecision(10) << ans << '\n';
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