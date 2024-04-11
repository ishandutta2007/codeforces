#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------"<<endl
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
	string s , t , h;
	cin>>s>>t; n = sze(s); m = sze(t);
	for(ll i = 0 ; i < n ; i++){
		for(ll k = i ; k < n ; k++){
			ll j = k - i + 1;
			j = k - m + j;
			if(j < 0 || j > k) continue;
			h.clear();
			for(ll q = i ; q <= k ; q++){
				h += s[q];
			}
			for(ll q = k - 1 ; q >= j ; q--){
				h += s[q];
			}
			if(t == h){
				cout<<"YES\n";
				return;
			}
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}