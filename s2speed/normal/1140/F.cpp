#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 998244353 , inf = 2e17;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

ll ans[maxn << 1];

struct segtree {

	ll sz = 1 , cur = 0;
	vector<vector<pll>> val;
	vector<vector<ll>> und;
	vector<ll> par , dsz[2];

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.resize(sz << 1);
		und.resize(sz << 1);
		par.assign(6e5 , -1);
		dsz[0].assign(3e5 , 1);
		dsz[1].assign(3e5 , 0);
		for(ll i = 0 ; i < 3e5 ; i++){
			dsz[0].push_back(0); dsz[1].push_back(1);
		}
		return;
	}

	void add(ll l , ll r , pll k , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x].push_back(k);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		return;
	}

	void add(ll l , ll r , pll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	void walk(ll x , ll lx , ll rx){
		for(auto p : val[x]){
			ll v = p.first , u = p.second;
			while(par[v] != -1) v = par[v];
			while(par[u] != -1) u = par[u];
			if(v == u) continue;
			if(dsz[0][v] + dsz[1][v] < dsz[0][u] + dsz[1][u]) swap(v , u);
			cur -= 1ll * dsz[0][v] * dsz[1][v] + 1ll * dsz[0][u] * dsz[1][u];
			par[u] = v; dsz[0][v] += dsz[0][u]; dsz[1][v] += dsz[1][u];
			cur += 1ll * dsz[0][v] * dsz[1][v];
			und[x].push_back(u);
		}
		if(rx - lx == 1){
			ans[lx] = cur;
		} else {
			ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
			walk(ln , lx , m); walk(rn , m , rx);
		}
		reverse(all(und[x]));
		for(auto u : und[x]){
			ll v = par[u];
			cur -= 1ll * dsz[0][v] * dsz[1][v];
			dsz[0][v] -= dsz[0][u]; dsz[1][v] -= dsz[1][u];
			par[u] = -1;
			cur += 1ll * dsz[0][v] * dsz[1][v] + 1ll * dsz[0][u] * dsz[1][u];
		}
		return;	
	}

	void walk(){
		walk(0 , 0 , sz);
		return;
	}

};

segtree st;
map<pll , ll> s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		ll x , y;
		cin>>x>>y; x--; y += 3e5 - 1;
		if(s.count({x , y})){
			st.add(s[{x , y}] , i , {x , y});
			s.erase({x , y});
		} else {
			s[{x , y}] = i;
		}
	}
	auto it = s.begin() , et = s.end();
	while(it != et){
		plll p = *it;
		st.add(p.second , n , p.first);
		it++;
	}
	st.walk();
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}