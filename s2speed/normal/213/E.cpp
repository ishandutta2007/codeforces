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
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
		return;
	}

};

segtree st;
ll f[maxn] , g[maxn] , a[maxn] , b[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>n>>m;
	if(n == 1){
		cout<<m<<'\n';
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		a[h] = i;
	}
	for(ll i = 0 ; i < m ; i++){
		ll h;
		cin>>h; h--;
		b[h] = i;
	}
	st.init(n);
	st.set(a[0] , 1);
	for(ll i = 1 ; i < n ; i++){
		g[i] = st.cal(0 , a[i]);
		st.set(a[i] , 1);
	}
	st.clear();
	st.init(n);
	f[0] = 0;
	ll x = 1;
	for(ll i = 1 ; i < n ; i++){
		f[i] = f[i - 1];
		while(st.cal(0 , a[i]) != g[f[i]]){
			f[i] = f[f[i] - 1];
			while(x < i - f[i]) st.set(a[x++] , 0);
		}
		st.set(a[i] , 1);
		f[i]++;
	}
	st.clear();
	st.init(m);
	x = 0;
	st.set(b[0] , 1);
	ll cur = 1 , ans = 0;
	for(ll i = 1 ; i < m ; i++){
		while(st.cal(0 , b[i]) != g[cur]){
			cur = f[cur - 1];
			while(x < i - cur) st.set(b[x++] , 0);
		}
		cur++;
		if(cur == n){
			ans++;
			cur = f[cur - 1];
			while(x <= i - cur) st.set(b[x++] , 0);
		}
		st.set(b[i] , 1);
	}
	cout<<ans<<'\n';
	return 0;
}