#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,no-stack-protector")

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

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 1e18;

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

bitset<MAXN> gh;
ll lp[MAXN] , nt[MAXN];
vector<ll> p;

void prime(){
	gh.set();
	for(ll i = 2 ; i < MAXN ; i++){
		if(gh[i]){
			lp[i] = i;
			p.push_back(i);
			for(ll j = 2 * i ; j < MAXN ; j += i){
				lp[j] = i;
				gh[j] = false;
			}
		}
	}
	for(ll i = 2 ; i < MAXN ; i++){
		ll h = i;
		while(h % lp[i] == 0) h /= lp[i];
		nt[i] = h;
	}
	return;
}

vector<pll> ans , d[MAXN] , o;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	lp[1] = 1;
	ll x;
	cin>>x;
	for(ll i = 2 ; i <= x ; i++){
		d[lp[i]].push_back({i , i});
	}
	ll ps = p.size();
	for(ll e = ps - 1 ; e >= 0 ; e--){
		o.clear();
		ll i = p[e];
		for(auto p : d[i]){
			ll j = p.first;
			if(nt[j] == 1){
				o.push_back(p);
			}
		}
		for(auto p : d[i]){
			ll j = p.first;
			if(nt[j] != 1){
				o.push_back(p);
			}
		}
		ll os = o.size();
		for(ll j = 1 ; j < os ; j += 2){
			ans.push_back({o[j].second , o[j - 1].second});
		}
		if(os % 2 == 1){
			pll u = o.back();
			u.first = nt[u.first];
			d[lp[u.first]].push_back(u);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto p : ans){
		cout<<p.first<<' '<<p.second<<'\n';
	}
	return 0;
}

/*

*/