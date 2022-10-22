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

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , par , h , l , r;
	cin>>n;
	cout<<"? 1 "<<n<<endl;
	cin>>par;
	if(par > 1){
		cout<<"? 1 "<<par<<endl;
		cin>>h;
	} else {
		h = -1;
	}
	if(h == par){
		l = 1; r = par;
	} else {
		l = par + 1; r = n + 1;
	}
	while(l < r - 3){
		ll m = (l + r) / 2;
		if(par < l){
			cout<<"? "<<par<<' '<<m - 1<<endl;
		} else {
			cout<<"? "<<m<<' '<<par<<endl;
		}
		cin>>h;
		if(h == par){
			if(par < l){
				r = m;
			} else {
				l = m;
			}
		} else {
			if(par < l){
				l = m;
			} else {
				r = m;
			}
		}
	}
	if(r - l == 1){
		cout<<"! "<<l<<'\n';
		return 0;
	}
	ll ans;
	if(r - l == 3){
		cout<<"? "<<l<<' '<<r - 1<<endl;
		cin>>ans;
		if(ans == l + 1){
			cout<<"? "<<l<<' '<<l + 1<<endl;
			cin>>h;
			if(h == ans){
				cout<<"! "<<l<<'\n';
				return 0;
			} else {
				cout<<"! "<<l + 2<<'\n';
				return 0;
			}
		} else {
			if(ans == l + 2) r--;
			if(ans == l) l++;
		}
	}
	if(r - l == 2){
		cout<<"? "<<l<<' '<<r - 1<<endl;
		cin>>ans;
		if(ans == l){
			cout<<"! "<<l + 1<<'\n';
			return 0;
		} else {
			cout<<"! "<<l<<'\n';
			return 0;
		}
	}
	return 0;
}

/*

*/