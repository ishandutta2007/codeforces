#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
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

string t[64] , s;

ll find_dif(ll j){
	ll x = 0 , sz = sze(s) , ts = sze(t[j]);
	for(ll i = 0 ; i < sz && x < ts ; i++){
		if(s[i] == t[j][x]) x++;
	}
	return sz - x + ts - x;
}

void solve(){
	cin>>s;
	ll ans = inf;
	for(ll i = 0 ; i < 60 ; i++){
		ans = min(ans , find_dif(i));
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll i = 0 ; i < 60 ; i++){
		ll h = (1ll << i);
		while(h){
			t[i] += h % 10 + '0';
			h /= 10;
		}
		reverse(all(t[i]));
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}