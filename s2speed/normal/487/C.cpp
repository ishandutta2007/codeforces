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

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 1e15;

ll n;

ll tav(ll x , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= x; res %= n;
		}
		x *= x; x %= n;
		k /= 2;
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	if(n == 1){
		cout<<"YES\n1\n";
		return 0;
	}
	if(n == 4){
		cout<<"YES\n1\n3\n2\n4\n";
		return 0;
	}
	db sq = sqrt(n);
	for(ll i = 2 ; i <= sq ; i++){
		if(n % i == 0){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n1\n";
	for(ll i = 2 ; i <= n ; i++){
		ll h = 1ll * i * tav(i - 1 , n - 2); h %= n; if(h == 0) h += n;
		cout<<h<<'\n';
	}
	return 0;
}

/*

*/