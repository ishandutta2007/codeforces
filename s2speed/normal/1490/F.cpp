#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

const ll MAXN = 2e5 + 15 , MAX = 1e6 + 15 , md = 998244353 , inf = 1e15;
// check problem statement

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

unordered_map<ll , ll , custom_hash> cnt;
set<ll> s;
vector<ll> v;
ll ps[MAXN] , sf[MAXN];

void solve(){
	cnt.clear(); v.clear(); s.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		if(s.count(h)){
			cnt[h]++;
		} else {
			s.insert(h);
			cnt[h] = 1;
		}
	}
	auto et = s.end();
	for(auto it = s.begin() ; it != et ; ++it){
		v.push_back(cnt[*it]);
	}
	sort(all(v));
	ll vs = v.size();
	ps[0] = v[0];
	for(ll i = 1 ; i < vs ; i++){
		ps[i] = ps[i - 1] + v[i];
	}
	sf[vs - 1] = v[vs - 1];
	for(ll i = vs - 2 ; i >= 0 ; i--){
		sf[i] = sf[i + 1] + v[i];
	}
	ll ans = inf;
	for(ll i = 0 ; i < vs ; i++){
		ll h = (i == 0 ? 0 : ps[i - 1]) , q = sf[i] - 1ll * (vs - i) * v[i];
		ans = min(ans , h + q);
	}
	cout<<ans<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/