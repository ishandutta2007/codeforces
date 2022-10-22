#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e6 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

struct item {

	db mn;
	ll cnt;

	friend item operator + (item a , item b){
		item res;
		if(a.mn == b.mn){
			res.mn = a.mn;
			res.cnt = a.cnt + b.cnt;
		} else {
			if(a.mn < b.mn){
				res = a;
			} else {
				res = b;
			}
		}
		return res;
	}

};

struct segtree {

	ll sz = 1;
	vector<db> laz;
	vector<item> vl;
	item def = {0.5 , 1} , zero = {inf , 0};

	void init(ll n){
		while(sz < n) sz *= 2;
		laz.assign(2 * sz , 0);
		vl.assign(2 * sz , def);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		if(laz[x] == 0) return;
		db h = laz[x];
		laz[x] = 0;
		vl[x].mn += h;
		if(rx - lx == 1) return;
		ll ln = 2 * x + 1 , rn = ln + 1;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void add(ll l , ll r , db k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		vl[x] = vl[ln] + vl[rn];
		return;
	}

	void add(ll l , ll r , db k){
		if(l == -1 || l >= r) return;
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	item cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return zero;
		if(rx <= r && lx >= l) return vl[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		item a , b;
		a = cal(l , r , ln , lx , m); b = cal(l , r , rn , m , rx);
		return a + b;
	}

	item cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
ll a[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	st.init(MAXN);
	ll n , q;
	cin>>n>>q>>a[0];
	st.add(a[0] , a[0] + 1 , -0.5);
	for(int i = 1 ; i <= n ; i++){
		if(i == n){
			a[i] = -1;
		} else {
			cin>>a[i];
		}
		st.add(a[i] , a[i] + 1 , -0.5);
		if(a[i] < a[i - 1]){
			st.add(a[i] + 1 , a[i - 1] + 1 , 1);
		}
	}
	while(q--){
		ll i , v;
		cin>>i>>v; i--;
		if(i > 0){
			if(a[i] < a[i - 1]){
				st.add(a[i] + 1 , a[i - 1] + 1 , -1);
			}
		}
		if(i < n){
			if(a[i] > a[i + 1]){
				st.add(a[i + 1] + 1 , a[i] + 1 , -1); 
			}
		}
		st.add(a[i] , a[i] + 1 , 0.5);
		a[i] = v;
		st.add(v , v + 1 , -0.5);
		if(i > 0){
			if(a[i] < a[i - 1]){
				st.add(a[i] + 1 , a[i - 1] + 1 , 1);
			}
		}
		if(i < n){
			if(a[i] > a[i + 1]){
				st.add(a[i + 1] + 1 , a[i] + 1 , 1);
			}
		}
		item h = st.cal(0 , a[0] + 1);
		cout<<h.cnt<<'\n';
	}
	return 0;
}

/*

*/