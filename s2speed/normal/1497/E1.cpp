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
typedef pair<pii , int> piii;
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

const ll MAXN = 2e5 + 15 , MAXA = 3163 , md = 1e9 + 7 , inf = 2e9;

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

bitset<MAXA> gh;
vector<int> pr;

void prime(){
	gh.set();
	for(int i = 2 ; i < MAXA ; i++){
		if(!gh[i]) continue;
		pr.push_back(i);
		for(int j = i * i ; j < MAXA ; j += i){
			gh[j] = false;
		}
	}
	return;
}

unordered_map<ll , ll , custom_hash> t;
ll x = 0 , a[MAXN];
set<ll> s;

void solve(){
	t.clear(); x = 0; s.clear();
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		for(auto j : pr){
			ll o = j * j;
			while(a[i] % o == 0){
				a[i] /= o;
			}
		}
		if(t.count(a[i]) == 0){
			t[a[i]] = x++;
		}
		a[i] = t[a[i]];
	}
	ll ans = 1;
	for(ll i = 0 ; i < n ; i++){
		if(s.count(a[i])){
			s.clear();
			ans++;
		}
		s.insert(a[i]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	prime();
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/