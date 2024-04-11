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

ll lcm(ll a , ll b){
	return 1ll * a * b / gcd(a , b);
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

ll dv(ll a , ll b){
	return 1ll * a * tav(b , md - 2) % md;
}

vector<ll> v;

void solve(){
	v.clear();
	ll n , m , a , b , c , d , p;
	cin>>n>>m>>a>>b>>c>>d>>p; p = dv(100 - p , 100);
	ll t = lcm(2 * n - 2 , 2 * m - 2) , z[2] , s , x;
	bool r = false;
	if(a <= c){
		s = c - a;
		z[0] = 2 * (n - c);
		z[1] = 2 * (c - 1);
	} else {
		s = 2 * n - a - c;
		z[0] = 2 * (c - 1);
		z[1] = 2 * (n - c);
	}
	x = s;
	while(x < t){
		v.push_back(x);
		x += z[r];
		r ^= 1;
	}
	r = false;
	if(b <= d){
		s = d - b;
		z[0] = 2 * (m - d);
		z[1] = 2 * (d - 1);
	} else {
		s = 2 * m - d - b;
		z[0] = 2 * (d - 1);
		z[1] = 2 * (m - d);
	}
	x = s;
	while(x < t){
		v.push_back(x);
		x += z[r];
		r ^= 1;
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	ll q = 1 , o = 0 , vs = sze(v);
	x = 0;
	for(ll i = 0 ; i < vs ; i++){
		ll h = q * (v[i] - x) % md;
		o += h;
		x = v[i];
		q *= p; q %= md;
	}
	ll h = q * (t - x) % md;
	o += h;
	q = 1 - q; q += (q < 0) * md;
	o %= md;
	ll ans = dv(o , q);
	cout<<ans<<'\n';
	return;
}

/*
1
10 10 1 1 10 10 75
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}