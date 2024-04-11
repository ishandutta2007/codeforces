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
	vector<ll> val , laz , cnt , sum;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , 0);
		cnt.assign(sz << 1 , 0);
		sum.assign(sz << 1 , 0);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		val[x] += cnt[x] * h;
		if(rx - lx == 1){
			sum[x] += h;
			return;
		}
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void set(ll i , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(i < lx || i >= rx) return;
		if(rx - lx == 1){
			cnt[x] ^= 1;
			val[x] ^= sum[x];
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(i , ln , lx , m); set(i , rn , m , rx);
		cnt[x] = cnt[ln] + cnt[rn];
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(ll i){
		set(i , 0 , 0 , sz);
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void add(ll l , ll r , ll k){
		l = max(l , 0ll); r = min(r , sz);
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		l = max(l , 0ll); r = min(r , sz);
		return cal(l , r , 0 , 0 , sz);
	}

};

struct sagtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		l = max(l , 0ll); r = min(r , sz);
		if(l >= r) return 0;
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

ll q , d;
segtree sj , sp;
sagtree st;
bitset<maxn> a;
ll res;

void add(ll i){
	ll x = st.cal(i - d , i) , y = st.cal(i + 1 , i + d + 1);
	x = x * (x - 1) / 2; y = y * (y - 1) / 2;
	ll h = sj.cal(i - d , i) + sp.cal(i + 1 , i + d + 1) - x - y;
	res += h / 2 + x + y;
	sj.add(i - d , i , 1); sp.add(i + 1 , i + d + 1 , 1);
	sj.set(i); sp.set(i);
	st.set(i , 1);
	return;
}

void del(ll i){
	sj.add(i - d , i , -1); sp.add(i + 1 , i + d + 1 , -1);
	sj.set(i); sp.set(i);
	st.set(i , 0);
	ll x = st.cal(i - d , i) , y = st.cal(i + 1 , i + d + 1);
	x = x * (x - 1) / 2; y = y * (y - 1) / 2;
	ll h = sj.cal(i - d , i) + sp.cal(i + 1 , i + d + 1) - x - y;
	res -= h / 2 + x + y;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	sj.init(2e5); sp.init(2e5); st.init(2e5);
	cin>>q>>d;
	for(ll e = 0 ; e < q ; e++){
		ll i;
		cin>>i;
		if(a[i]){
			del(i);
		} else {
			add(i);
		}
		a.flip(i);
		cout<<res<<'\n';
	}
	return 0;
}