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

const ll maxn = 1e5 + 16 , md = 998244353 , inf = 2e18;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

ll n , k;
vector<ll> t;

struct segtree {

	ll sz = 1;
	vector<ll> val , cnt;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		cnt.assign(sz << 1 , 0);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			cnt[x] = k;
			val[x] = 1ll * k * t[lx];
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		cnt[x] = cnt[ln] + cnt[rn];
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll bs(ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			return lx;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(val[ln] > k){
			return bs(k , ln , lx , m);
		}
		return bs(k - val[ln] , rn , m , rx);
	}

	ll bs(ll k){
		if(val[0] <= k) return n;
		return bs(k , 0 , 0 , sz);
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		if(l >= r) return 0;
		return cal(l , r , 0 , 0 , sz);
	}

	ll get(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return cnt[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = get(l , r , ln , lx , m) , b = get(l , r , rn , m , rx);
		return a + b;
	}

	ll get(ll l , ll r){
		if(l >= r) return 0;
		return get(l , r , 0 , 0 , sz);
	}

};

segtree st;
ll a[maxn] , b[maxn] , c[maxn] , w[maxn] , f[maxn] , dp[maxn] , dep = 0;
vector<ll> adj[maxn];
vector<pll> v;

void fDFS(ll r){
	st.set(b[r] , c[r]);
	dep += w[r];
	ll h = k - 2ll * dep;
	if(h < 0){
		f[r] = 0;
	} else {
		ll j = st.bs(h) , g , o;
		g = st.cal(0 , j); o = st.get(0 , j);
		h -= g;
		o += h / t[j];
		f[r] = o;
	}
	for(auto i : adj[r]){
		fDFS(i);
	}
	st.set(b[r] , 0);
	dep -= w[r];
	return;
}

void dDFS(ll r){
	ll m1 = -1 , m2 = -1;
	for(auto i : adj[r]){
		dDFS(i);
		if(dp[i] > m2){
			m2 = dp[i];
		}
		if(dp[i] > m1){
			m2 = m1;
			m1 = dp[i];
		}
	}
	dp[r] = max(f[r] , m2 + !(bool)(r) * (m1 - m2));
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>c[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back({a[i] , i});
		t.push_back(a[i]);
	}
	sort(all(v)); sort(all(t)); t.push_back(inf);
	for(ll i = 0 ; i < n ; i++){
		b[v[i].second] = i;
	}
	w[0] = 0;
	for(ll i = 1 ; i < n ; i++){
		ll p;
		cin>>p>>w[i]; p--;
		adj[p].push_back(i);
	}
	fDFS(0);
	dDFS(0);
	wall;
	for(ll i = 0 ; i < n ; i++){
		cerr<<f[i]<<' ';
	}
	cerr<<endl;
	wall;
	for(ll i = 0 ; i < n ; i++){
		cerr<<dp[i]<<' ';
	}
	cerr<<endl;
	wall;
	cout<<dp[0]<<'\n';
	return 0;
}