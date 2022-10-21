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

const ll maxn = 1e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a > b) swap(a , b);
	return (a == 0 ? b : gcd(b % a , a));
}

bitset<maxn> sqfr , g;
ll pnt[maxn];

void prime(){
	g.set(); sqfr.set();
	for(ll i = 2 ; i < maxn ; i++){
		if(!g[i]) continue;
		ll i2 = i * i;
		for(ll j = i2 ; j < maxn ; j += i){
			g[j] = false;
		}
		for(ll j = i ; j < maxn ; j += i){
			pnt[j]++;
		}
		for(ll j = i2; j < maxn ; j += i2){
			sqfr[j] = false;
		}
	}
	return;
}

vector<ll> v , dv[maxn] , c[maxn] , a , r;
ll cnt[maxn];

inline void add(ll x){
	for(auto i : dv[x]){
		cnt[i]++;
	}
	return;
}

inline void del(ll x){
	for(auto i : dv[x]){
		cnt[i]--;
	}
	return;
}

ll cop(ll x){
	ll res = 0;
	for(auto i : dv[x]){
		if(!sqfr[i]) continue;
		ll h = cnt[i] * (1 - ((pnt[i] & 1) << 1));
		res += h;
	}
	return res;
}

ll fixed_gcd(ll x){
	if(sze(c[x]) <= 1) return 0;
	ll res = 0;
	a.clear();
	for(auto i : c[x]){
		a.push_back(i / x);
	}
	r.clear();
	for(auto i : a){
		ll cp = cop(i);
		while(cp){
			ll h = r.back();
			del(h);
			r.pop_back();
			if(gcd(h , i) == 1){
				cp--;
				if(!cp){
					res = max(res , i * h);
				}
			}
		}
		r.push_back(i);
		add(i);
	}
	while(!r.empty()){
		del(r.back()); r.pop_back();
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = i ; j < maxn ; j += i){
			dv[j].push_back(i);
		}
	}
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
	}
	sort(all(v) , greater<ll>());
	v.resize(distance(v.begin() , unique(all(v))));
	if(sze(v) == 1){
		cout<<v[0]<<'\n';
		return 0;
	}
	n = sze(v);
	for(auto i : v){
		for(auto j : dv[i]){
			c[j].push_back(i);
		}
	}
	ll ans = 0;
	for(ll i = 1 ; i < maxn ; i++){
		ans = max(ans , fixed_gcd(i) * i);
	}
	cout<<ans<<'\n';
	return 0;
}