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

ll get(ll x){
	ll l = 1 , r = md;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(1ll * m * (m - 1) / 2 <= x){
			l = m;
		} else {
			r = m;
		}
	}
	if(1ll * l * (l - 1) / 2 != x) return -1;
	return l;
}

void solve(){
	ll n , i , j , k;
	cin>>n;
	ll l = 1 , r = n , t;
	cout<<"? 1 "<<n<<endl;
	cin>>t;
	while(true){
		ll m = (r + l + 1) >> 1 , h , o;
		cout<<"? "<<l<<' '<<m - 1<<endl;
		cin>>h;
		if(h == 0){
			l = m - 1;
			continue;
		}
		if(h == t){
			r = m;
			continue;
		}
		cout<<"? "<<m<<' '<<r<<endl;
		cin>>o;
		ll g = get(h);
		bool lf = false;
		if(g == -1){
			lf = false;
		} else {
			ll w;
			cout<<"? "<<l<<' '<<m - 2<<endl;
			cin>>w;
			lf = ((h - w) == (g - 1));
		}
		if(lf){
			i = m - g;
			ll y = (t - h - o) / g;
			j = m + y;
			k = j + get(o - 1ll * y * (y - 1) / 2) - 1;
		} else {
			g = get(o);
			k = m + g - 1;
			ll y = (t - h - o) / g;
			j = m - y;
			i = j - get(h - 1ll * y * (y - 1) / 2);
		}
		cout<<"! "<<i<<' '<<j<<' '<<k<<endl;
		return;
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