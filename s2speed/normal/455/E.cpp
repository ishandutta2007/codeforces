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
		val.assign(sz << 1 , -inf);
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
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(val[x] < k) return -1;
		if(rx <= l || lx >= r) return -1;
		if(rx - lx == 1){
			return lx;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , k , rn , m , rx);
		if(a != -1) return a;
		return cal(l , r , k , ln , lx , m);
	}

	ll cal(ll l , ll r , ll k){
		return cal(l , r , k , 0 , 0 , sz);
	}

};

segtree st;
ll a[maxn] , c[maxn] , ps[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ps[0] = a[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + a[i];
	}
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		ll l = 1 , r = i + 2;
		while(l < r - 1){
			ll m = (r + l) >> 1;
			ll j = st.cal(0 , i , m - i);
			if(j < 0){
				r = m;
				continue;
			}
			ll h = ps[i] - ps[j] + 1ll * (m - (i - j)) * a[j];
			if(h < 1ll * m * a[i]){
				r = m;
			} else {
				l = m;
			}
		}
		c[i] = l;
		st.set(i , c[i] - i);
	}
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll i , m;
		cin>>m>>i; i--;
		ll j = st.cal(0 , i + 1 , m - i);
		ll h = ps[i] - ps[j] + 1ll * (m - (i - j)) * a[j];
		cout<<h<<'\n';
	}
	return 0;
}