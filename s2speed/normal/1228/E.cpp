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

struct custom_hash{
	static uint64_t splitmix64(uint64_t x){
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}

};

const ll MAXN = 250 + 15 , md = 1e9 + 7 , inf = 1e15;

unordered_map<ll , ll , custom_hash> t , y;

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

ll fact[MAXN] , fact_md[MAXN];

void fact_build(){
	fact[0] = 1;
	fact_md[0] = 1;
	for(ll i = 1 ; i < MAXN ; i++){
		fact[i] = 1ll * fact[i - 1] * i % md;
		fact_md[i] = tav(fact[i] , md - 2);
	}
	return;
}

ll chs(ll n , ll k){
	ll res = 1ll * fact[n] * fact_md[k] % md * fact_md[n - k] % md;
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	ll n , k , ans = 0 , cnt = 0;
	cin>>n>>k;
	for(ll i = 0 ; i <= n ; i++){
		for(ll j = 0 ; j <= n ; j++){
			ll res = 1 , h = n * (i + j) - i * j , o;
			if(!y.count(h)){
				y[h] = tav(k - 1 , h);
			}
			o = 1ll * chs(n , i) * y[h] % md;
			res *= o;
			h = n * n - h;
			if(!t.count(h)){
				t[h] = tav(k , h);
			}
			o = 1ll * chs(n , j) * t[h] % md;
			res *= o;
			res %= md;
			cnt++;
			if((i + j) % 2){
				res = md - res;
				cnt -= 2;
			}
			ans += res;
		}
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}

/*

*/