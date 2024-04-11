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

const ll maxn = 1e6 + 16 , md = 998244353 , inf = 2e16;

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

bitset<maxn> cnt;
ll ps[maxn];

void solve(){
	ll n , c;
	cin>>n>>c;
	for(ll i = 0 ; i <= c ; i++){
		cnt[i] = false;
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; cnt[h] = true;
	}
	ps[0] = true;
	for(ll i = 1 ; i <= c ; i++){
		ps[i] = ps[i - 1] + cnt[i];
	}
	for(ll z = 1 ; z <= c ; z++){
		if(cnt[z]) continue;
		ll lm = c / z;
		for(ll y = 1 ; y <= lm ; y++){
			if(!cnt[y]) continue;
			ll x = y * z , r = min(c + 1 , x + y) , h = ps[r - 1] - ps[x - 1];
			if(h){
				cout<<"No\n";
				return;
			}
		}
	}
	cout<<"Yes\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}