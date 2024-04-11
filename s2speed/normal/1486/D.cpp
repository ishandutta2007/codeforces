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

const int MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e9;

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz *= 2;
		val.assign(2 * sz , -inf);
		return;
	}

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(lx >= a.size()) return;
		if(rx - lx == 1){
			val[x] = a[lx];
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		val[x] = max(val[ln] , val[rn]);
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return -inf;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cal(ll l , ll r){
		if(l >= r) return -inf;
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

segtree st;
ll a[MAXN] , b[MAXN] , n , k;
vector<ll> ps;

bool check(ll x){
	for(ll i = 0 ; i < n ; i++){
		if(a[i] >= x){
			b[i] = 1;
		} else {
			b[i] = -1;
		}
	}
	ps[0] = b[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + b[i];
	}
	st.build(ps);
	ll lm = n - k;
	bool res = false;
	for(ll i = 0 ; i <= lm ; i++){
		ll h = st.cal(i + k - 1 , n);
		if(i > 0){
			h -= ps[i - 1];
		}
		if(h >= 1){
			res = true;
			break;
		}
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k; ps.resize(n); st.init(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll l = 1 , r = n + 1;
	while(l < r - 1){
		ll m = (r + l) / 2;
		if(check(m)){
			l = m;
		} else {
			r = m;
		}
	}
	cout<<l<<'\n';
	return 0;
}

/*

*/