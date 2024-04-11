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

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 2e15;

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

bool check(ll n){
	ll k = 0 , h = n;
	while(h > 0){
		k += h % 10;
		h /= 10;
	}
	return (gcd(n , k) > 1);
}

void solve(){
	ll n;
	cin>>n;
	if(check(n)){
		cout<<n<<'\n';
		return;
	}
	n++;
	if(check(n)){
		cout<<n<<'\n';
		return;
	}
	n++;
	if(check(n)){
		cout<<n<<'\n';
		return;
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}