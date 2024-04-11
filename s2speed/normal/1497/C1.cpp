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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 2e9;

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
	cin>>n>>k; n -= k; n += 3;
	for(ll i = 3 ; i < k ; i++){
		cout<<"1 ";
	}
	if(n % 3 == 0){
		cout<<n / 3<<' '<<n / 3<<' '<<n / 3<<'\n';
		return;
	}
	if(n % 4 == 0){
		cout<<n / 4<<' '<<n / 4<<' '<<n / 2<<'\n';
		return;
	}
	if(n % 2 == 1){
		cout<<"1 "<<n / 2<<' '<<n / 2<<'\n';
		return;
	}
	cout<<"2 "<<n / 2 - 1<<' '<<n / 2 - 1<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/