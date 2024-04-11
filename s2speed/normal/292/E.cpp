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

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll cnt = 0;

struct segtree {

	ll sz = 1;
	vector<pll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , {-1 , -inf});
		return;
	}

	void set(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x] = {cnt , k + lx - l};
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(l , r , k , ln , lx , m); set(l , r , k , rn , m , rx);
		return;
	}

	void set(ll l , ll r , ll k){
		set(l , r , k , 0 , 0 , sz);
		cnt++;
		return;
	}

	pll cal(ll i , ll x , ll lx , ll rx){
		if(rx - lx == 1) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		pll a;
		if(i < m){
			a = cal(i , ln , lx , m);
		} else {
			a = cal(i , rn , m , rx);
		}
		return max(a , {val[x].first , val[x].second + i - lx});
	}

	ll cal(ll i){
		return cal(i , 0 , 0 , sz).second;
	}

};

segtree st;
ll a[maxn] , b[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t;
		if(t == 1){
			ll k , l , y;
			cin>>k>>l>>y; k--; l--;
			st.set(l , l + y , k);
		} else {
			ll i , h;
			cin>>i; i--;
			h = st.cal(i);
			if(h < 0){
				cout<<b[i]<<'\n';
			} else {
				cout<<a[h]<<'\n';
			}
		}
	}
	return 0;
}