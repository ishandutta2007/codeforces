#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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
		val[x] = max(val[ln] , val[rn]);
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
		a = cal(l , r , ln , lx , m); b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
vector<pll> v;
ll l[maxn] , c[maxn] , r[maxn] , jad[maxn][20] , w[maxn][20];
vector<ll> a;

ll find_jad(ll v , ll u){
	ll res = 0;
	if(r[v] >= a[u]) return 0;
	for(ll j = 19 ; j >= 0 ; j--){
		if(jad[v][j] <= u){
			res += w[v][j];
			v = jad[v][j];
		}
	}
//	res += w[v][0];
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n; a.resize(n);
	for(ll i = 0 ; i <= n ; i++){
		for(ll j = 0 ; j < 20 ; j++){
			jad[i][j] = n; w[i][j] = 0;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]>>l[i];
		v.push_back({a[i] + l[i] , i});
	};
	sort(all(v) , greater<pll>());
	ll x = n - 1;
	for(ll i = 0 ; i < n ; i++){
		while(true){
			if(v[i].first >= a[x]) break;
			x--;
		}
		c[v[i].second] = x;
	}
	st.init(n);
	for(ll i = n - 1 ; i >= 0 ; i--){
		ll h = max(a[i] + l[i] , st.cal(i , c[i] + 1));
		r[i] = h;
		st.set(i , r[i]);
	}
	for(ll i = n - 1 ; i >= 0 ; i--){
		ll u = upper_bound(all(a) , r[i]) - a.begin();
		jad[i][0] = u; w[i][0] = (u != n ? a[u] - r[i] : 0);
		for(ll j = 1 ; j < 20 ; j++){
			jad[i][j] = jad[jad[i][j - 1]][j - 1];
			w[i][j] = w[i][j - 1] + w[jad[i][j - 1]][j - 1];
		}
	}
	ll q;
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		cout<<find_jad(v , u)<<'\n';
	}
	return 0;
}