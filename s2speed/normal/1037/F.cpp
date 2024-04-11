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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e6 + 15 , md = 1e9 + 7 , inf = 2e16;

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
	vector<pll> val;
	
	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(2 * sz , {-1 , -1});
		return;
	}

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				val[x] = {a[lx] , lx};
			}
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
		return;
	}

	pll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return {-1 , -1};
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		pll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	pll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
ll t[MAXN];
vector<ll> a;
ll n , k;
ll ans = 0;

void solve(ll l , ll r){
	if(l >= r) return;
	pll p = st.cal(l , r);
	ll i = p.second - l , j = r - l , h = i / (k - 1) , cnt = 0 , mot = 0 , e = j / (k - 1) + 1 , o = max(i + 1 - (j % (k - 1)) , 0ll) , g = o / (k - 1) , u = o % (k - 1);
//	if(l == 0 && r == 5){
//		cout<<i<<' '<<j<<' '<<h<<' '<<e<<' '<<o<<' '<<g<<' '<<u<<'\n';
//	}
	cnt += h + 1;
	cnt += 1ll * h * (h + 1) / 2 * (k - 1);
	cnt += 1ll * (e - h - 1) * (i + 1);
	mot += 1ll * u * (g + 1);
	mot += 1ll * g * (g + 1) / 2 * (k - 1);
//	if(l == 0 && r == 5){
//		cout<<cnt<<' '<<mot<<'\n';
//	}
	cnt -= mot; cnt %= md;
	ans += 1ll * cnt * p.first; ans %= md;
	solve(l , p.second); solve(p.second + 1 , r);
	return;
}

/*
6 4
6 1 1 1 1 6
*/

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll h = 2 , cnt = 0;
	for(ll i = 1 ; i < MAXN ; i++){
		if(i == h){
			cnt++;
			h <<= 1;
		}
		t[i] = cnt;
	}
	cin>>n>>k; a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		ans -= a[i];
	}
	st.init(n); st.build(a);
	solve(0 , n);
	cout<<ans<<'\n';
	return 0;
}