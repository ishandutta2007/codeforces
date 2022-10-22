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

bool a[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q , cnt = 0;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		cnt += a[i];
	}
	for(ll e = 0 ; e < q ; e++){
		ll t , x;
		cin>>t>>x;
		if(t == 1){
			x--;
			if(a[x]){
				cnt--;
			} else {
				cnt++;
			}
			a[x] = 1 - a[x];
		} else {
			cout<<(cnt >= x)<<'\n';
		}
	}
	return 0;
}

/*

*/