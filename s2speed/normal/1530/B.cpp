#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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
	ll n , m;
	cin>>n>>m;
	for(ll i = 1 ; i <= m ; i++){
		cout<<(i & 1 ? '1' : '0');
	}
	cout<<'\n';
	for(ll i = 1 ; i < n - 1 ; i++){
		if(i & 1){
			for(ll j = 0 ; j < m ; j++) cout<<'0';
			cout<<'\n';
			continue;
		}
		cout<<'1';
		for(ll j = 1 ; j < m - 1 ; j++) cout<<'0';
		cout<<"1\n";
	}
	if(n & 1){
		cout<<'1';
	} else {
		cout<<'0';
	}
	for(ll j = 1 ; j < m - 2 ; j++){
		cout<<(j & 1 ? '0' : '1');
	}
	if(n & 1 && m & 1){
		cout<<"01\n";
	}
	if(!(n & 1)){
		cout<<"00\n";
	}
	if(n & 1 && !(m & 1)){
		cout<<"10\n";
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}