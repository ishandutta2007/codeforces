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

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

vector<ll> x , y;

void solve(){
	x.clear(); y.clear();
	ll n , k = 1 , h;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll a , b;
		cin>>a>>b;
		x.push_back(a); y.push_back(b);
	}
	sort(all(x)); sort(all(y));
	h = x[n / 2] - x[(n - 1) / 2] + 1;
	k *= h;
	h = y[n / 2] - y[(n - 1) / 2] + 1;
	k *= h;
	cout<<k<<'\n';
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