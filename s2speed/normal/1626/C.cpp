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

ll h[maxn] , k[maxn];
vector<pll> v;

void solve(){
	v.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>k[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>h[i];
		v.push_back({h[i] - k[i] , i});
	}
	ll x = 0 , p = 0 , ans = 0;
	sort(all(v) , greater<pll>());
	for(ll e = 0 ; e < n ; e++){
		ll i = v[e].second , z = v[e].first;
		if(k[i] <= x) continue;
		if(-z >= x){
			p = h[i];
			ans += p * (p + 1);
			x = k[i];
			continue;
		}
		ans -= p * (p + 1);
		p += k[i] - x;
		ans += p * (p + 1);
		x = k[i];
	}
	cout<<ans / 2<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}