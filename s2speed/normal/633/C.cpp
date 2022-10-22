#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll MAXN = 1e4 + 20 , md = 2000000357 , inf = 2e9 + 1;
// check problem statement

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

ll p = 31;
unordered_map<ll , ll , custom_hash> mp;
string s , h[1000020];
vector<string> ans;
pll par[MAXN];
bitset<MAXN> dp;

ll hsh(string h){
	ll q = 1 , hs = h.size() , res = 0 , o;
	for(ll i = 0 ; i < hs ; i++){
		if(h[i] < 97) h[i] += 32;
		o = 1ll * q * (h[i] - 95) % md;
		res += o;
		q *= p; q %= md;
	}
	return res % md;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(par , -1 , sizeof(par));
	ll n , m;
	cin>>n>>s>>m;
	for(ll i = 0 ; i < m ; i++){
		cin>>h[i];
		ll o = hsh(h[i]);
		mp[o] = i;
	}
	for(ll i = 0 ; i < n ; i++){
		ll lm = max(0ll , i - 1000);
		ll q = 1 , c = 0;
		for(ll j = i ; j >= lm ; j--){
			c = (c + 1ll * q * (s[j] - 95)) % md;
			q *= p; q %= md;
			if(mp.count(c)){
				if(j == 0){
					dp[i] = true;
					par[i] = {-1 , mp[c]};
					break;
				}
				if(dp[j - 1]){
					dp[i] = true;
					par[i] = {j - 1 , mp[c]};
					break;
				}
			}
		}
	}
	ll x = n - 1;
	while(x > -1){
		ans.push_back(h[par[x].second]);
		x = par[x].first;
	}
	ll as = ans.size();
	for(ll i = as - 1 ; i >= 0 ; i--){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

/*

*/