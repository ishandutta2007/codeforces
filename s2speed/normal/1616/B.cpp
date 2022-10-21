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

string s , h;

void solve(){
	h.clear();
	ll n , t;
	cin>>n>>s; t = n;
	if(n == 1){
		cout<<s<<s<<'\n';
		return;
	}
	if(s[0] <= s[1]){
		cout<<s[0]<<s[0]<<'\n';
		return;
	}
	for(ll i = 1 ; i < n ; i++){
		if(s[i] > s[i - 1]){
			t = i;
			break;
		}
	}
	for(ll i = 0 ; i < t ; i++){
		h += s[i];
	}
	for(ll i = t - 1 ; i >= 0 ; i--){
		h += s[i];
	}
	cout<<h<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}