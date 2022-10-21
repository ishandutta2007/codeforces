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
typedef pair<ll , pll> plll;
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

	ll sz = 1 , cur;
	vector<ll> val , ual , rt , t , ls , ln , rn;

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		ls[x] = x;
		if(rx - lx == 1){
			if(lx < sze(a)){
				val[x] = a[lx];
			}
			return;
		}
		ll m = (rx + lx) >> 1; ln[x] = (x << 1) + 1; rn[x] = ln[x] + 1;
		build(a , ln[x] , lx , m); build(a , rn[x] , m , rx);
		val[x] = val[ln[x]] + val[rn[x]];
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
		return;
	}

	void init(ll n , vector<ll> &a){
		while(sz < n) sz <<= 1;
		cur = (sz << 1);
		val.assign(sz << 1 , 0);
		ual.assign(sz << 1 , 0);
		ls.assign(sz << 1 , 0);
		ln.resize(sz << 1); rn.resize(sz << 1);
		t.assign(sz << 1 , 0);
		rt.push_back(0);
		build(a);
		return;
	}

	void set(ll i , ll a , ll b , ll tx , ll x , ll lx , ll rx , ll bx){
		val.push_back(0); ual.push_back(0); ln.push_back(0); rn.push_back(0); t.push_back(tx);
		ls[bx] = x;
		if(rx - lx == 1){
			val[x] = a; ual[x] = b;
			return;
		}
		ll m = (rx + lx) >> 1;
		if(i < m){
			ln[x] = cur++;
			rn[x] = ls[(bx + 1) << 1];
			set(i , a , b , tx , ln[x] , lx , m , (bx << 1) + 1);
		} else {
			ln[x] = ls[(bx << 1) + 1];
			rn[x] = cur++;
			set(i , a , b , tx , rn[x] , m , rx , (bx + 1) << 1);
		}
		val[x] = val[ln[x]] + 1ll * (t[x] - t[ln[x]]) * ual[ln[x]] + val[rn[x]] + 1ll * (t[x] - t[rn[x]]) * ual[rn[x]];
		ual[x] = ual[ln[x]] + ual[rn[x]];
		return;
	}

	void set(ll i , ll a , ll b , ll tx){
		rt.push_back(cur);
		set(i , a , b , tx , cur++ , 0 , sz , 0);
		return;
	}

	ll cal(ll l , ll r , ll tx , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x] + 1ll * (tx - t[x]) * ual[x];
		ll m = (rx + lx) >> 1;
		ll a = cal(l , r , tx , ln[x] , lx , m) , b = cal(l , r , tx , rn[x] , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r , ll q , ll tx){
		return cal(l , r , tx , rt[q] , 0 , sz);
	}

};

segtree st;
ll x1[maxn] , x2[maxn] , a[maxn] , b[maxn] , y3[maxn] , y2[maxn];
vector<ll> v;
vector<pllll> w;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>x1[i]>>x2[i]>>y3[i]>>a[i]>>b[i]>>y2[i];
		v.push_back(y3[i]);
		w.push_back({{x1[i] + 1 , i} , {a[i] * (x1[i] + 1) + b[i] , a[i]}});
		w.push_back({{x2[i] + 1 , i} , {y2[i] , 0}});
	}
	st.init(n , v);
	sort(all(w));
	for(auto q : w){
		ll t = q.first.first , i = q.first.second , v = q.second.first , u = q.second.second;
		st.set(i , v , u , t);
	}
	ll pr = 0 , q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll l , r , x;
		cin>>l>>r>>x; l--; x += pr; x %= (ll)1e9;
		pllll h = {{x , inf} , {inf , inf}};
		ll j = lower_bound(all(w) , h) - w.begin();
		pr = st.cal(l , r , j , x);
		cout<<pr<<'\n';
	}
	return 0;
}