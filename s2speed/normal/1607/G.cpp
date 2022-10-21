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

ll a[maxn] , b[maxn];

void solve(){
	ll n , m , g = 0 , d = 0 , ca = 0 , cb = 0;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]>>b[i];
		g += min(min(m , a[i] + b[i] - m) , min(a[i] , b[i]));
		ll ha = a[i] - max(0ll , m - b[i]) , hb = b[i] - max(0ll , m - a[i]);
		d += ha - hb;
	}
	ll ans;
	if(g < abs(d)){
		if(d > 0){
			ca = g;
		} else {
			cb = g;
		}
		ans = abs(d) - g;
	} else {
		if(d > 0){
			ca = d;
			g -= d;
		} else {
			cb = -d;
			g += d;
		}
		ca += g / 2;
		cb += (g + 1) / 2;
		ans = g & 1;
	}
	cout<<ans<<'\n';
	for(ll i = 0 ; i < n ; i++){
		ll sa = max(0ll , m - b[i]) , sb = max(0ll , m - a[i]) , o = m - sa - sb;
		ll h = min(o , ca);
		sa += h;
		ca -= h;
		o -= h;
		h = min(o , cb);
		sb += h;
		cb -= h;
		o -= h;
		cout<<sa<<' '<<sb<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}