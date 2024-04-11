#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define size(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 2.5e5 + 16 , md = 998244353 , inf = 2e18;
 
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

ll t[maxn] , s[maxn];

void solve(){
	ll a , b , c , x , y , z;
	cin>>a>>b>>c;
	z = t[c];
	x = s[a - c + 1] * t[c];
	y = t[b] + t[c] * (b != c);
	cout<<x<<' '<<y<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	t[1] = 1;
	s[1] = 2;
	for(ll i = 2 ; i <= 9 ; i++){
		t[i] = t[i - 1] * 10;
		s[i] = s[i - 1];
		while(s[i] / t[i] == 0) s[i] <<= 1;
	}
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}