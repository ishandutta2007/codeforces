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

const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	vector<ll> val , xal , laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		xal.assign(sz << 1 , 0);
		laz.assign(sz << 1 , 0);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = 0;
		val[x] += 1ll * h * (rx - lx);
		xal[x] += h;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] += h; 
		laz[rn] += h;
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
		xal[x] = min(xal[ln] , xal[rn]);
		return;
	}

	void add(ll l , ll r , ll k){
		if(l == -1) return;
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(xal[x] >= k) return -1;
		if(rx - lx == 1){
			return lx;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(k , ln , lx , m);
		if(a != -1) return a;
		return cal(k , rn , m , rx);
	}

	ll cal(ll k){
		return cal(k , 0 , 0 , sz);
	}

	ll sum(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = sum(l , r , ln , lx , m) , b = sum(l , r , rn , m , rx);
		return a + b;
	}

	ll sum(ll l , ll r){
		return sum(l , r , 0 , 0 , sz);
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , cur = 0 , ans = 0;
	string s;
	cin>>n>>s;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '0'){
			cur = 0;
		} else {
			cur++;
		}
		ll j = st.cal(cur);
		st.add(j , i + 1 , 1);
		ans += st.sum(0 , i + 1);
	}
	cout<<ans<<'\n';
	return 0;
}