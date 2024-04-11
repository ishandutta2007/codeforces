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
	vector<ll> val , cnt;
 
	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		cnt.assign(sz << 1 , 0);
		return;
	}
 
	void add(ll i , bool k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(k){
				val[x] += lx;
				cnt[x]++;
			} else {
				val[x] -= lx;
				cnt[x]--;
			}
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			add(i , k , ln , lx , m);
		} else {
			add(i , k , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		cnt[x] = cnt[ln] + cnt[rn];
		return;
	}
 
	void add(ll i , bool k){
		add(i , k , 0 , 0 , sz);
		return;
	}
 
	pll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return {0 , 0};
		if(rx <= r && lx >= l) return {val[x] , cnt[x]};
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		pll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return {a.first + b.first , a.second + b.second};
	}
 
	pll cal(ll l , ll r){
		if(l >= r) return {0 , 0};
		return cal(l , r , 0 , 0 , sz);
	}
 
	ll bs(ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			return lx;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(val[ln] <= k){
			return bs(k - val[ln] , rn , m , rx);
		}
		return bs(k , ln , lx , m);
	}
 
	ll bs(ll k){
		return bs(k , 0 , 0 , sz);
	}
 
	void clear(){
		sz = 1;
		val.clear();
		cnt.clear();
	}
 
};

segtree st;
vector<pll> v;
vector<ll> a;

void solve(){
	v.clear(); a.clear(); st.clear();
	ll n , k;
	cin>>n>>k; a.resize(n);
	st.init(n + 1);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	sort(all(a));
	ll cur = 1;
	for(ll i = 1 ; i < n ; i++){
		if(a[i] != a[i - 1]){
			v.push_back({a[i - 1] , cur});
			cur = 0;
		}
		cur++;
	}
	v.push_back({a[n - 1] , cur});
	ll x = 0 , emp = 0;
	cur = sze(v);
	for(auto p : v){
		st.add(p.second , true);
	}
	ll ans = inf;
	for(ll i = 0 ; emp <= k && i <= n ; i++){
		if(st.val[0] <= k){
			ans = 0;
			break;
		}
		ll j = st.bs(k);
		pll p = st.cal(0 , j);
		ll h = p.second + (k - p.first) / j;
		ans = min(ans , cur - h);
		if(v[x].first == i){
			st.add(v[x++].second , false);
			cur--;
		} else {
			emp++;
		}
	}
	cout<<ans<<'\n';
	return;
}

/*
1
4 1
3 0 1 2
*/


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}