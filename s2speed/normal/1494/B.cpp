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

const ll MAXN = 4e2 + 15 , md = 1e9 + 7 , inf = 1e9;

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

void solve(){
	ll n , a , b , c , d , e , f;
	cin>>n>>a>>b>>c>>d; e = b ; f = d;
	for(ll j = 0 ; j < 16 ; j++){
		ll o = 1;
		if(j & o){
			a--; b--;
		}
		o <<= 1;
		if(j & o){
			b--; c--;
		}
		o <<= 1;
		if(j & o){
			c--; d--;
		}
		o <<= 1;
		if(j & o){
			d--; a--;
		}
		if(a >= 0 && a <= n - 2 && b >= 0 && b <= n - 2 && c >= 0 && c <= n - 2 && d >= 0 && d <= n - 2){
			cout<<"YES\n";
			return;
		}
		o = 1;
		if(j & o){
			a++; b++;
		}
		o <<= 1;
		if(j & o){
			b++; c++;
		}
		o <<= 1;
		if(j & o){
			c++; d++;
		}
		o <<= 1;
		if(j & o){
			d++; a++;
		}
	}
	cout<<"NO\n";
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
3 3 3 1
1 2 7 2
1 3 3 1
2 3 7 2
2
1 5
1 7
*/