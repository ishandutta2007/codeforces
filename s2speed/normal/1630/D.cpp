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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , b[maxn] , ps[maxn];
bool c[maxn];
vector<ll> v;

void solve(){
	v.clear();
	ll n , m , k = 0 , sum = 0 , res = inf;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		c[i] = (a[i] <= 0);
		sum += abs(a[i]);
	}
	ps[0] = abs(a[0]);
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + abs(a[i]);
	}
	for(ll i = 0 ; i < m ; i++){
		ll h;
		cin>>h;
		k = gcd(k , h);
	}
	b[0] = c[0];
	for(ll i = 1 ; i < n ; i++){
		b[i] = c[i] ^ c[i - 1];
	}
	b[n] = c[n - 1];
	bool z;
	for(ll i = 0 ; i < k ; i++){
		z = false;
		for(ll j = i ; j <= n ; j += k){
			z ^= b[j];
		}
		if(z) v.push_back(i);
	}
	if(v.empty()){
		cout<<sum<<'\n';
		return;
	}
	ll q = 0;
	for(ll i = 0 ; i < k ; i++){
		ll o = inf;
		for(ll j = i ; j < n ; j += k){
			o = min(o , abs(a[j]));
		}
		q += o;
	}
	ll h = 0 , vs = sze(v);
	for(ll i = 0 ; i < vs ; i += 2){
		ll l = v[i] , r = v[i + 1] , o;
		for(ll j = l ; j < r ; j++){
			o = inf;
			for(ll t = j ; t < n ; t += k){
				o = min(o , abs(a[t]));
			}
			h += o;
		}
	}
	res = min(h , q - h);
	cout<<sum - res * 2<<'\n';
	return;
}

/*
1
6 1
-1 3 3 3 -1 3
3
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}