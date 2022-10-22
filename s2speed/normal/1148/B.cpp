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

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e9;

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

ll a[MAXN] , b[MAXN] , x = 0;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , t , g , k , ans = 0;
	cin>>n>>m>>t>>g>>k;
	if(n <= k || m <= k){
		cout<<"-1\n";
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i] += t;
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i];
	}
	for(ll i = 0 ; i <= k ; i++){
		while(b[x] < a[i]) x++;
		if(x + k - i >= m){
			cout<<"-1\n";
			return 0;
		}
		ans = max(ans , b[x + k - i]);
	}
	cout<<ans + g<<'\n';
	return 0;
}

/*

*/