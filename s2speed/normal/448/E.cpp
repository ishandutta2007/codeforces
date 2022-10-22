#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	return ((b == 0) ? a : gcd(b , a % b));
}

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

const ll MAXN = 2e5 + 15 , MAXD = 1e4 + 15 , md = 1e6 + 3 , inf = 1e18;

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

vector<ll> v , f[MAXD] , d[MAXD] , del;
set<ll> s;
ll ans[MAXN];

void solve(ll i , ll k , ll h , ll st){
	if(k == 0){
		ans[st] = v[i];
		return;
	}
	if(h == 1){
		ans[st] = 1;
		return;
	}
	ll q = 0;
	for(auto j : d[i]){
		ll dis = inf;
		if(f[j].size() >= k){
			dis = f[j][k - 1];
		}
		solve(j , k - 1 , min(dis , h - q) , st + q);
		q += dis;
		if(q >= h) break;
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k;
	cin>>n>>k;
	if(n == 1){
		cout<<"1\n";
		return 0;
	}
	if(k >= 1e5){
		for(ll i = 0 ; i < 1e5 ; i++){
			cout<<"1 ";
		}
		cout<<'\n';
		return 0;
	}
	db sq = sqrt(n);
	for(ll i = 1 ; i <= sq ; i++){
		if(n % i == 0){
			v.push_back(i);
			if(i != sq){
				v.push_back(n / i);
			}
		}
	}
	sort(all(v));
	ll vs = v.size();
	for(ll i = 0 ; i < vs ; i++){
		s.insert(i);
		f[i].push_back(1);
	}
	for(ll i = 0 ; i < vs ; i++){
		for(ll j = i ; j < vs ; j++){
			if(v[j] % v[i] == 0){
				d[j].push_back(i);
			}
		}
	}
	for(ll l = 1 ; l <= k ; l++){
		auto et = s.end(); del.clear();
		for(auto it = s.begin() ; it != et ; it++){
			ll i = *it;
			ll h = 0;
			for(auto j : d[i]){
				h += f[j][l - 1];
				if(h > 1e5) break;
			}
			if(h > 1e5){
				del.push_back(i);
				continue;
			}
			f[i].push_back(h);
		}
		for(auto j : del){
			s.erase(j);
		}
	}
	ll lm = 1e5;
	if(f[vs - 1].size() >= k + 1){
		lm = f[vs - 1][k];
	}
	solve(vs - 1 , k , lm , 1);
	for(ll i = 1 ; i <= lm ; i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

/*

*/