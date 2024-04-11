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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	vector<vector<ll>> val , var;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.resize(sz << 1);
		var.resize(sz << 1);
		return;
	}

	void add(ll l , ll r , pll p , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x].push_back(p.first);
			var[x].push_back(p.second);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , p , ln , lx , m); add(l , r , p , rn , m , rx);
		return;
	}

	void add(ll l , ll r , pll p){
		if(l == r) return;
		add(l , r , p , 0 , 0 , sz);
		return;
	}

	void ready(ll x , ll lx , ll rx){
		sort(all(val[x]));
		sort(all(var[x]));
		if(rx - lx == 1) return;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ready(ln , lx , m); ready(rn , m , rx);
		return;
	}

	void ready(){
		ready(0 , 0 , sz);
		return;
	}

	ll cal(ll t , ll i , ll j , ll x , ll lx , ll rx){
		ll vs = sze(val[x]) , res = vs , h;
		h = upper_bound(all(val[x]) , i + j) - val[x].begin();
		res -= vs - h;
		h = upper_bound(all(var[x]) , i - j) - var[x].begin();
		res -= vs - h;
		if(rx - lx == 1) return res;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(t < m){
			return cal(t , i , j , ln , lx , m) + res;
		} else {
			return cal(t , i , j , rn , m , rx) + res;
		}
	}

	ll cal(ll t , ll i , ll j){
		return cal(t , i , j , 0 , 0 , sz);
	}

};

segtree st;
ll b[maxn] , p[maxn] , s[maxn] , c[maxn] , d[maxn];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>m>>n;
	for(ll i = 0 ; i < m ; i++){
		cin>>p[i];
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>s[i];
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>c[i];
		v.push_back(c[i]);
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>d[i];
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	st.init(sze(v));
	for(ll i = 0 ; i < m ; i++){
		ll l = lower_bound(all(v) , p[i]) - v.begin() , r = upper_bound(all(v) , s[i]) - v.begin();
		st.add(l , r , {p[i] + b[i] , p[i] - b[i]});
	}
	st.ready();
	for(ll i = 0 ; i < n ; i++){
		ll t = lower_bound(all(v) , c[i]) - v.begin();
		cout<<st.cal(t , c[i] , d[i])<<' ';
	}
	cout<<'\n';
	return 0;
}