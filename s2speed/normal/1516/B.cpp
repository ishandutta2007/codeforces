#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

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

ll a[maxn];

void solve(){
	ll n , x = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		x ^= a[i];
	}
	if(x == 0){
		cout<<"YES\n";
		return;
	}
	ll cnt = 0 , y = 0;
	for(ll i = 0 ; i < n ; i++){
		y ^= a[i];
		if(y == x){
			cnt++;
			y = 0;
		}
	}
	cout<<(cnt > 1 ? "YES\n" : "NO\n");
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}