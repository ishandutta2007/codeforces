#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
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

inline ll tav(ll n , ll k){
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

string s , t;

void solve(){
	ll n;
	cin>>s; n = sze(s);
	for(ll i = n - 1 ; i ; i--){
		ll h = s[i] + s[i - 1] - 2 * '0';
		if(h >= 10){
			s[i] = h % 10 + '0';
			s[i - 1] = h / 10 + '0';
			cout<<s<<'\n';
			return;
		}
	}
	char c = s[0] + s[1] - '0';
	t = c;
	for(ll i = 1 ; i < n - 1 ; i++){
		t += s[i + 1];
	}
	cout<<t<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}