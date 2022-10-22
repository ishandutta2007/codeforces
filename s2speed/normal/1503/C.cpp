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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz *= 2;
		val.assign(2 * sz , inf);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
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

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return inf;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return min(a , b);
	}

	ll cal(ll l , ll r){
		if(l >= r) return inf;
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

vector<pll> v , q;
ll dp[maxn] , r[maxn] , a[maxn] , c[maxn] , o[maxn];
segtree st , ts;

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	ll n , ans = 0;
	cin>>n;
	v.resize(n); st.init(n); ts.init(n);
	for(ll i = 0 ; i < n ; i++){
		ll a , c;
		cin>>a>>c; ans += c;
		v.push_back({a , c});
	}
	sort(all(v) , greater<pll>());
	for(ll i = 0 ; i < n ; i++){
		q.push_back({v[i].first + v[i].second , i});
		a[i] = v[i].first;
		c[i] = v[i].second;
	}
	sort(all(q) , greater<pll>());
	ll x = 0;
	for(ll j = 0 ; j < n ; j++){
		while(a[x] > q[j].first) x++;
		ll i = q[j].second;
		o[i] = x;
	}
	dp[0] = 0;
	st.set(0 , a[0]);
	ts.set(0 , 0);
	for(ll i = 1 ; i < n ; i++){
		dp[i] = min(ts.cal(o[i] , i) , st.cal(0 , o[i]) - a[i] - c[i]);
		st.set(i , dp[i] + a[i]);
		ts.set(i , dp[i]);
	}
	ans += dp[n - 1];
	cout<<ans<<'\n';
	return 0;
}