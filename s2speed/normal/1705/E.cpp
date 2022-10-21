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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

struct segtree {
	
	ll sz = 1;
	vector<ll> val , laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , -1);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = -1;
		if(h == -1) return;
		val[x] = h * (rx - lx);
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] = laz[rn] = h;
		return;
	}

	void set(ll l , ll r , bool k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(l , r , k , ln , lx , m); set(l , r , k , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(ll l , ll r , bool k){
		if(l >= r) return;
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	ll bs(ll i , bool c , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= i) return -1;
		if(c){
			if(val[x] == 0) return -1;
		} else {
			if(val[x] == rx - lx) return -1;
		}
		if(rx - lx == 1){
			return lx;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = bs(i , c , ln , lx , m);
		if(a != -1) return a;
		return bs(i , c , rn , m , rx);
	}

	ll bs(ll i , bool c){
		return bs(i , c , 0 , 0 , sz);
	}

	void add(ll i){
		ll j = bs(i , false);
		set(i , j , 0);
		set(j , j + 1 , 1);
		return;
	}

	void del(ll i){
		ll j = bs(i , true);
		set(i , j , 1);
		set(j , j + 1 , 0);
		return;
	}

	ll cal(ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(val[x] == 0) return -1;
		if(rx - lx == 1) return lx;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(rn , m , rx);
		if(a != -1) return a;
		return cal(ln , lx , m);
	}

	ll cal(){
		return cal(0 , 0 , sz);
	}

};

segtree st;
ll a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	st.init(2.5e5);
	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		st.add(a[i]);
	}
	for(ll e = 0 ; e < q ; e++){
		ll i , k;
		cin>>i>>k; i--;
		st.del(a[i]);
		a[i] = k;
		st.add(a[i]);
		cout<<st.cal()<<'\n';
	}
	return 0;
}