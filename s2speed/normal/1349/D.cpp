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

const ll maxn = 3e5 + 16 , md = 998244353 , inf = 2e16;

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

ll dv(ll a , ll b){
	return 1ll * a * tav(b , md - 2) % md;
}

ll a[maxn] , x[maxn] , y[maxn] , z[maxn] , f[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m = 0 , d;
	cin>>n; d = dv(1 , n - 1);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; m += a[i];
	}
	for(ll i = 0 ; i <= m ; i++){
		x[i] = dv(i , m);
		z[i] = 1ll * dv(m - i , m) * d % md;
		y[i] = 1 - x[i] - z[i];
		y[i] %= md; if(y[i] < 0) y[i] += md;
	}
	f[m] = 0;
	for(ll i = 0 ; i < m ; i++){
		f[i] = 1;
		ll h = z[i];
		if(i){
			f[i] += 1ll * x[i] * f[i - 1] % md;
		}
		f[i] *= tav(h , md - 2); f[i] %= md;
	}
	for(ll i = m - 1 ; i >= 0 ; i--){
		f[i] += f[i + 1]; if(f[i] >= md) f[i] -= md;
	}
//	for(ll i = 0 ; i <= m ; i++){
//		cout<<f[i]<<' ';
//	}
//	cout<<'\n';
	ll h = 0 , o = 1ll * f[0] * (n - 1);
	for(ll i = 0 ; i < n ; i++){
		h += f[a[i]];
	}
	h -= o;
	h %= md; if(h < 0) h += md;
	h = dv(h , n);
	cout<<h<<'\n';
	return 0;
}