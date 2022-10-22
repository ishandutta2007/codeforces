#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e18;
 
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

ll n , m , k , p;
ll a[maxn] , h[maxn];
vector<ll> v;

bool check(ll x){
	v.clear();
	ll cnt = 0 , mk = m * k;
	for(ll i = 0 ; i < n ; i++){
		ll o = h[i] + 1ll * m * a[i] , c = x;
		while(c < o){
			ll u = min(m , c / a[i]);
			c += p;
			cnt++;
			if(cnt > mk) return false;
			v.push_back(u);
		}
	}
	v.push_back(inf);
	sort(all(v));
	if(!v[0]) return false;
	cnt = 0;
	for(ll i = 1 ; i < m ; i++){
		while(v[cnt] == i) cnt++;
		if(cnt > i * k) return false;
	}
	return true;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m>>k>>p;
	ll y = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>h[i]>>a[i];
		y = max(y , a[i]);
	}
	ll l = 0 , r = inf;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<l + 1<<'\n';
	return 0;
}