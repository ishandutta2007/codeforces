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

vector<pll> v;
ll ans[maxn] , a[maxn];

void solve(){
	v.clear();
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		ll h;
		cin>>h;
		v.push_back({h , i});
		a[i] = h;
	}
	sort(all(v) , greater<pll>());
	ll x = 1;
	for(auto p : v){
		ans[p.second] = x;
		x = -x;
		x += (x > 0);
	}
	ll res = 0;
	for(ll i = 1 ; i <= n ; i++){
		res += 1ll * abs(ans[i]) * a[i];
	}
	cout<<2ll * res<<'\n';
	for(ll i = 0 ; i <= n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ans[0] = 0;
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}