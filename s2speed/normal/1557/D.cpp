#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<ll> laz;
	vector<pll> val , las;
	pll def = {-1 , -1};

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , {0 , -1});
		laz.assign(sz << 1 , 0);
		las.assign(sz << 1 , def);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll ln = (x << 1) + 1 , rn = ln + 1;
		pll p = las[x];
		las[x] = def;
		if(p != def){
			val[x] = p;
			if(rx - lx != 1){
				las[ln] = las[rn] = p;
				laz[ln] = laz[rn] = 0;
			}
		}
		ll h = laz[x];
		laz[x] = 0;
		val[x].first += h;
		if(rx - lx == 1) return;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void set(ll l , ll r , pll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			las[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(l , r , k , ln , lx , m); set(l , r , k , rn , m , rx);
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void set(ll l , ll r , pll k){
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	void add(){
		laz[0]++;
		return;
	}

	pll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return {inf , -1};
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		pll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return min(a , b);
	}

	pll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
vector<ll> v , q[maxn];
ll l[maxn] , r[maxn] , par[maxn];
bitset<maxn> mark;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll j;
		cin>>j>>l[i]>>r[i]; j--; l[i]--;
		q[j].push_back(i);
		v.push_back(l[i]); v.push_back(r[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < m ; i++){
		l[i] = lower_bound(all(v) , l[i]) - v.begin();
		r[i] = lower_bound(all(v) , r[i]) - v.begin();
	}
	st.init(sze(v));
	for(ll i = 0 ; i < n ; i++){
		pll m = {i , -1};
		for(auto j : q[i]){
			m = min(m , st.cal(l[j] , r[j]));
		}
		st.add();
		for(auto j : q[i]){
			st.set(l[j] , r[j] , {m.first , i});
		}
		par[i] = m.second;
	}
	pll o = st.cal(0 , sze(v));
	ll cur = o.second;
	while(cur != -1){
		mark[cur] = true;
		cur = par[cur];
	}
	cout<<o.first<<'\n';
	for(ll i = 0 ; i < n ; i++){
		if(!mark[i]){
			cout<<i + 1<<' ';
		}
	}
	cout<<'\n';
	return 0;
}