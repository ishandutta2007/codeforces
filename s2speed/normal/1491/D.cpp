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

const ll MAXN = 2e5 + 15 , md = 998244353 , inf = 1e15;

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

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll a , b , h = 0 , o = 0;
		cin>>a>>b;
		if(a > b){
			cout<<"NO\n";
			continue;
		}
		bool ans = true;
		for(ll j = 0 ; j < 30 ; j++){
			if(a & 1) h++;
			if(b & 1) o++;
			a >>= 1;
			b >>= 1;
			ans &= (h >= o);
		}
		cout<<(ans ? "YES\n" : "NO\n");
	}
	return 0;
}

/*

*/