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
bitset<maxn> h;

void solve(){
	ll n , ans = 0;
	cin>>n>>s>>t; for(ll i = 0 ; i < n ; i++) h[i] = false;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] != t[i]){
			ans += 2;
			h[i] = true;
			continue;
		}
		if(s[i] == '0'){
			ll o = (((i ? s[i - 1] : 'h') == '1') && (i ? !h[i - 1] : false));
			ans += 1 + o;
			h[i] = o;
		}
		if(s[i] == '1'){
			ll o = (((i ? s[i - 1] : 'h') == '0') && (i ? !h[i - 1] : false));
			ans += o;
			h[i] = o;
		}
	}
	cout<<ans<<'\n';
	return;
}

/*
1
7
0101000
1101100
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}