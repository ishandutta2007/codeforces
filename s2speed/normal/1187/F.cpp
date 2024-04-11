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

ll dv(ll a , ll b){
	return 1ll * a * tav(b , md - 2) % md;
}

ll l[maxn] , r[maxn] , p[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , sum = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>l[i]; l[i]--;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>r[i];
	}
	p[0] = 1;
	for(ll i = 1 ; i < n ; i++){
		ll h = max(0ll , -max(l[i] , l[i - 1]) + min(r[i] , r[i - 1]));
		h = dv(h , 1ll * (r[i] - l[i]) * (r[i - 1] - l[i - 1]) % md);
		h = 1 - h; if(h < 0) h += md;
		p[i] = h;
		sum += h;
	}
	sum %= md;
	ll ans = sum * 3ll + 1;
	for(ll i = 1 ; i < n ; i++){
		ll q = sum;
		q -= p[i];
		if(i > 1){
			q -= p[i - 1];
		}
		if(i < n - 1 && i){
			q -= p[i + 1];
		}
		q %= md; if(q < 0) q += md;
		q *= p[i]; q %= md;
		ans += q;
	}
	for(ll i = 1 ; i < n - 1 ; i++){
		ll h = (1 - p[i]) + (1 - p[i + 1]) , o;
		o = min(min(r[i - 1] , r[i + 1]) , r[i]) - max(max(l[i - 1] , l[i + 1]) , l[i]);
		o = max(o , 0ll);
		o = dv(o , 1ll * (r[i - 1] - l[i - 1]) * (r[i] - l[i]) % md * (r[i + 1] - l[i + 1]) % md);
		h -= o;
		h %= md;
		h = 1 - h; if(h < 0) h += md;
		ans += 2ll * h;
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}