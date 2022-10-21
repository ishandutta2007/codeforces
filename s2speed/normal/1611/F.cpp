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

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , inf);
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
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll k , ll x , ll lx , ll rx){
		if(rx <= l) return -1;
		if(val[x] >= k) return -1;
		if(rx - lx == 1) return lx;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , k , ln , lx , m);
		if(a != -1) return a;
		return cal(l , k , rn , m , rx);
	}

	ll cal(ll l , ll k){
		return cal(l , k , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

segtree st;
ll ps[maxn];

void solve(){
	st.clear();
	ll n , s;
	cin>>n>>s;
	st.init(n + 2);
	ps[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		ll h;
		cin>>h;
		ps[i] = ps[i - 1] + h;
	}
	for(ll i = 0 ; i <= n ; i++){
		st.set(i , ps[i]);
	}
	st.set(n + 1 , -inf);
	ll ans = 0 , ind = -1;
	for(ll i = 1 ; i <= n ; i++){
		ll j = st.cal(i , ps[i - 1] - s);
		ans = max(ans , j - i);
		if(j - i == ans) ind = i;
	}
	if(ans == 0){
		cout<<"-1\n";
		return;
	}
	cout<<ind<<' '<<ind + ans - 1<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}