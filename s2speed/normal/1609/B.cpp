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

vector<ll> v;
string s;

void solve(){
	ll cur = 0 , n , q;
	cin>>n>>q>>s;
	for(ll i = 0 ; i < n - 2 ; i++){
		if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') cur++;
	}
	for(ll e = 0 ; e < q ; e++){
		ll i;
		char c;
		cin>>i>>c; i--;
		for(ll j = i - 2 ; j <= i ; j++){
			if(j < 0) continue;
			if(s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'c') cur--;
		}
		s[i] = c;
		for(ll j = i - 2 ; j <= i ; j++){
			if(j < 0) continue;
			if(s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'c') cur++;
		}
		cout<<cur<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	ll T;
//	cin>>T;
//	while(T--) solve();
	solve();
	return 0;
}