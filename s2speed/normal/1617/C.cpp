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

vector<ll> v , u;
bitset<maxn> mark;

void solve(){
	v.clear(); u.clear();
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++) mark[i] = false;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		if(h > n){
			v.push_back(h);
			continue;
		}
		if(mark[h]){
			v.push_back(h);
		}
		mark[h] = true;
	}
	for(ll i = 1 ; i <= n ; i++){
		if(mark[i]) continue;
		u.push_back(i);
	}
	sort(all(v));
	ll ans = 0 , vs = sze(v);
	for(ll e = 0 ; e < vs ; e++){
		ll h = v[e] , i = u[e];
		if(h == i) continue;
		if(h <= 2 * i){
			cout<<"-1\n";
			return;
		}
		ans++;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}