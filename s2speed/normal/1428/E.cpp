#include<bits/stdc++.h>

typedef long long ll;
typedef double db;

using namespace std;

const ll MAX_N = 1e5;

vector<ll> va;
ll n , ar[MAX_N] , p[MAX_N] , d[MAX_N];

struct segtree{
	
	ll size;
	vector<ll> values;
	
	ll NORMAL_item = n;
	
	ll single(ll v){
		return v;
	}
	
	ll merge(ll a , ll b){
		if(va[a] >= va[b]){
			return a;
		} else {
			return b;
		}
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		values.assign(2 * size - 1 , NORMAL_item);
	}
	
	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()) values[x] = lx;
			return;
		}
		ll m = (lx + rx) / 2;
		build(a , 2 * x + 1 , lx , m); build(a , 2 * x + 2 , m , rx);
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
		return;
	}
	
	void build(vector<ll> &a){
		build(a , 0 , 0 , size);
	}
	
	void set(ll i , ll v , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			values[x] = i;
			return;
		}
		ll m = (rx + lx) / 2;
		if(i < m){
			set(i , v , 2 * x + 1 , lx , m);
		} else {
			set(i , v , 2 * x + 2 , m , rx);
		}
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
	}
	
	void set(ll i , ll v){
		set(i , v , 0 , 0 , size);
		return;
	}
	
	ll calc(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_item;
		if(lx >= l && rx <= r){
			return values[x];
		}
		ll m = (lx + rx) / 2;
		ll i1 = calc(l , r , 2 * x + 1 , lx , m) , i2 = calc(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	ll calc(ll l , ll r){
		return calc(l , r , 0 , 0 , size);
	}
	
};

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	segtree st;
	ll ans = 0 , y;
	cin>>n>>y; y -= n;
	st.init(n + 1);
	va.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>va[i];
		p[i] = 1;
	}
	va.push_back(-1);
	sort(va.begin() , va.end() , greater<ll>());
	for(int i = 0 ; i < n ; i++){
		ar[i] = va[i];
		ll h = ar[i] , q = ar[i] / 2 , u = (ar[i] + 1) / 2;;
		h *= ar[i];
		q *= ar[i] / 2;
		u *= (ar[i] + 1) / 2;
		q += u;
		va[i] = h - q;
		d[i] = q;
	}
	st.build(va);
	for(int e = 0 ; e < y ; e++){
		int i = st.calc(0 , n);
		p[i]++;
		ll a = (ar[i] + p[i]) / (p[i] + 1) , h = a , q = ar[i] / (p[i] + 1);
		h *= ar[i] % (p[i] + 1);
		q *= (p[i] + 1) - ar[i] % (p[i] + 1);
		h *= a;
		q *= ar[i] / (p[i] + 1);
		h += q;
		va[i] = d[i] - h;
		d[i] = h;
		st.set(i , va[i]);
	}
	for(int i = 0 ; i <= n ; i++){
//		cout<<p[i]<<" ";
//		cout<<va[i]<<" ";
	}
	for(int i = 0 ; i < n ; i++){
		ll a = (ar[i] + p[i] - 1) / p[i] , h = a , q = ar[i] / p[i];
		h *= (ar[i] % p[i]);
		q *= p[i] - ar[i] % p[i];
		h *= a;
		q *= ar[i] / p[i];
		h += q;
		ans += h;
//		cout<<ans<<" ";
	}
	cout<<ans<<"\n";
	return 0;
}