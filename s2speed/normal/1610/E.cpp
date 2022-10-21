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

ll a[maxn];
vector<pll> v;

void solve(){
	v.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	v.push_back({a[0] , 1});
	for(ll i = 1 ; i < n ; i++){
		if(a[i] != a[i - 1]){
			v.push_back({a[i] , 1});
		} else {
			v.back().second++;
		}
	}
	ll ans = 0 , vs = sze(v);
	for(auto p : v){
		ll cur = p.second;
		ll b = p.first , h = b + 1;
		while(true){
			ll j = lower_bound(all(v) , mp(h , -1ll)) - v.begin();
			if(j == vs) break;
			cur++;
			h = 2 * v[j].first - b;
		}
		ans = max(ans , cur);
	}
	cout<<n - ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}