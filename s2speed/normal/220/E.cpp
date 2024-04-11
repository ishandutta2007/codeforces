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
	ll val[4 * maxn][2];

	void init(ll n){
		while(sz < n) sz <<= 1;
		memset(val , 0 , sizeof(val));
		return;
	}

	void add(ll i , ll k , bool c , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x][c] += k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			add(i , k , c , ln , lx , m);
		} else {
			add(i , k , c , rn , m , rx);
		}
		val[x][c] = val[ln][c] + val[rn][c];
		return;
	}

	void add(ll i , ll k , bool c){
		add(i , k , c , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , bool c , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x][c];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , c , ln , lx , m) , b = cal(l , r , c , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r , bool c){
		return cal(l , r , c , 0 , 0 , sz);
	}

};

ll n , vs , k , cur;
segtree st;
ll a[maxn];
vector<ll> v;

void add(ll i){
	cur += st.cal(0 , a[i] , 1);
	cur += st.cal(a[i] + 1 , vs , 0);
	st.add(a[i] , 1 , 0);
	return;
}

void del(ll i){
	cur -= st.cal(a[i] + 1 , vs , 0);
	cur -= st.cal(0 , a[i] , 1);
	st.add(a[i] , -1 , 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < n ; i++){
		a[i] = lower_bound(all(v) , a[i]) - v.begin();
	}
	vs = sze(v);
	st.init(vs);
	cur = 0;
	for(ll i = 0 ; i < n ; i++){
		cur += st.cal(a[i] + 1 , vs , 1);
		st.add(a[i] , 1 , 1);
	}
	ll x = 0 , ans = 0;
	for(ll i = 0 ; i < n ; i++){
		add(i);
		while(x == i || cur > k && x < n){
			del(x++);
		}
		if(x == n) break;
		ans += n - x;
	}
	cout<<ans<<'\n';
	return 0;
}