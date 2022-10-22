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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

struct segtree {

	ll sz = 1;
	vector<ll> val;
	ll v[MAXN];

	void init(ll n){
		while(sz < n) sz *= 2;
		val.assign(2 * sz , -inf);
		return;
	}

	void build(ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = lx;
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		build(ln , lx , m); build(rn , m , rx);
		if(v[val[ln]] >= v[val[rn]]){
			val[x] = val[ln];
		} else {
			val[x] = val[rn];
		}
		return;
	}
	
	void build(){
		build(0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return -1;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		if(a == -1){
			return b;
		}
		if(b == -1){
			return a;
		}
		if(v[a] >= v[b]){
			return a;
		}
		return b;
	}

	ll cal(ll l , ll r){
		if(l >= r) return -1;
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

ll d[MAXN] , h[MAXN] , f[MAXN] , s[MAXN] , ps[MAXN];
segtree st , ft;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>d[i];
		d[i + n] = d[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>h[i]; h[i] *= 2;
		h[i + n] = h[i];
	}
	partial_sum(d , d + 2 * n , ps);
	st.init(2 * n); ft.init(2 * n);
	f[0] = h[0]; s[0] = f[0]; st.v[0] = s[0]; ft.v[0] = f[0];
	for(ll i = 1 ; i < 2 * n ; i++){
		f[i] = ps[i - 1] + h[i];
		s[i] = h[i] - ps[i - 1];
		ft.v[i] = f[i];
		st.v[i] = s[i];
	}
	st.build(); ft.build();
	for(ll e = 0 ; e < q ; e++){
		ll a , b , i , j , h = 0;
		cin>>a>>b;
		if(a <= b) a += n;
		a--;
		i = ft.cal(b , a);
		j = st.cal(b , a);
		if(i != j){
			cout<<f[i] + s[j]<<'\n';
			continue;
		}
		j = ft.cal(i + 1 , a);
		if(j != -1){
			h = s[i] + f[j];
		}
		j = st.cal(b , i);
		if(j != -1){
			h = max(h , s[j] + f[i]);
		}
		cout<<h<<'\n';
	}
	return 0;
}

/*

*/