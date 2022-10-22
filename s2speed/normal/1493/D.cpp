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
typedef pair<pll , ll> plll;
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

const ll MAXN = 2e5 + 15 , MAXP = 2e4 , md = 1e9 + 7 , inf = 1e18;

unordered_map<ll , ll , custom_hash> cnt[MAXN];
unordered_map<ll , ll , custom_hash> t;
ll lp[MAXN] , ps;
set<pll> pcnt[MAXP];
vector<ll> p , tav[MAXP];
bitset<MAXN> gh;

void prime(){
	ll x = 0;
	gh.set();
	for(ll i = 2 ; i < MAXN ; i++){
		if(gh[i]){
			t[i] = x++;
			p.push_back(i);
			lp[i] = i;
			for(ll j = 2 * i ; j < MAXN ; j += i){
				lp[j] = i;
				gh[j] = false;
			}
		}
	}
	return;
}

void tav_build(){
	for(ll i = 0 ; i < ps ; i++){
		ll h = 1;
		while(h < MAXN){
			tav[i].push_back(h);
			h *= p[i];
		}
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	ps = p.size();
	tav_build();
	ll n , q , cur = 1;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		ll h , g = 0 , k;
		cin>>h;
		while(h > 1){
			g = lp[h];
			k = 0;
			while(h % g == 0){
				h /= g;
				k++;
			}
			cnt[i][g] = k;
			pcnt[t[g]].insert({cnt[i][g] , i});
		}
	}
	for(ll i = 0 ; i < ps ; i++){
		if(pcnt[i].size() < n) continue;
		auto it = pcnt[i].begin();
		pll e = *it;
		cur *= tav[t[p[i]]][e.first]; cur %= md;
	}
	while(q--){
		ll i , x;
		cin>>i>>x; i--;
		while(x > 1){
			ll g = lp[x] , k = 0 , o;
			auto it = pcnt[t[g]].begin();
			pll e = *it;
			o = (pcnt[t[g]].size() < n ? 0 : e.first);
			while(x % g == 0){
				k++;
				x /= g;
			}
			pcnt[t[g]].erase({cnt[i][g] , i});
			cnt[i][g] += k;
			pcnt[t[g]].insert({cnt[i][g] , i});
			it = pcnt[t[g]].begin();
			e = *it;
			o = (pcnt[t[g]].size() < n ? 0 : e.first) - o;
			cur *= tav[t[g]][o]; cur %= md;
		}
		cout<<cur<<'\n';
	}
	return 0;
}

/*

*/