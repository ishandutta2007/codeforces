#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll ps[maxn] , a[maxn];
map<ll , ll> t;

void solve(){
	t.clear();
	ll n , ans = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ps[0] = a[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + a[i];
	}
	ans = 1;
	t[0] = 1;
	for(ll i = 1 ; i < n ; i++){
		ll h = ans;
		h -= t[-ps[i - 1]];
		if(h < 0) h += md;
		t[-ps[i - 1]] += h; if(t[-ps[i - 1]] >= md) t[-ps[i - 1]] -= md;
		ans += h; if(ans >= md) ans -= md;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}