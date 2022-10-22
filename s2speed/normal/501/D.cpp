#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

struct segtree{
	
	int size;
	vector<int> val;
	
	int NORMAL_int = 1;
	
	int single(ll v){
		return v;
	}
	
	int merge(int a , int b){
		return a + b;
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		val.assign(2 * size - 1 , NORMAL_int);
	}
	
	void build(ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = 1;
			return;
		}
		ll m = (lx + rx) / 2;
		build(2 * x + 1 , lx , m); build(2 * x + 2 , m , rx);
		val[x] = merge(val[2 * x + 1] , val[2 * x + 2]);
		return;
	}
	
	void build(){
		build(0 , 0 , size);
		return;
	}
	
	void set(ll i , ll v , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = single(v);
			return;
		}
		ll m = (rx + lx) / 2;
		if(i < m){
			set(i , v , 2 * x + 1 , lx , m);
		} else {
			set(i , v , 2 * x + 2 , m , rx);
		}
		val[x] = merge(val[2 * x + 1] , val[2 * x + 2]);
	}
	
	void set(ll i , ll v){
		set(i , v , 0 , 0 , size);
		return;
	}
	
	int cal(ll k , ll x , ll lx , ll rx){
		ll ln = 2 * x + 1 , rn = 2 * x + 2;
		if(rx - lx == 1){
			return lx;
		}
		ll m = (lx + rx) / 2;
		if(val[ln] > k){
			return cal(k , ln , lx , m);
		} else {
			return cal(k - val[ln] , rn , m , rx);
		} 
	}
	
	int cal(ll k){
		return cal(k , 0 , 0 , size);
	}

	void clear(){
		val.clear();
		size = 0;
	}
	
};

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct sumtree{
	
	ll size;
	vector<int> val;
	
	int NORMAL_int = 0;
	
	int single(ll v){
		return v;
	}
	
	int merge(int a , int b){
		return a + b;
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		val.assign(2 * size - 1 , NORMAL_int);
	}
	
	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()) val[x] = single(a[lx]);
			return;
		}
		ll m = (lx + rx) / 2;
		build(a , 2 * x + 1 , lx , m); build(a , 2 * x + 2 , m , rx);
		val[x] = merge(val[2 * x + 1] , val[2 * x + 2]);
		return;
	}
	
	void build(vector<ll> &a){
		build(a , 0 , 0 , size);
	}
	
	void set(ll i , ll v , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = single(v);
			return;
		}
		ll m = (rx + lx) / 2;
		if(i < m){
			set(i , v , 2 * x + 1 , lx , m);
		} else {
			set(i , v , 2 * x + 2 , m , rx);
		}
		val[x] = merge(val[2 * x + 1] , val[2 * x + 2]);
	}
	
	void set(ll i , ll v){
		set(i , v , 0 , 0 , size);
		return;
	}
	
	int cal(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_int;
		if(lx >= l && rx <= r){
			return val[x];
		}
		ll m = (lx + rx) / 2;
		int i1 = cal(l , r , 2 * x + 1 , lx , m) , i2 = cal(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	int cal(ll l , ll r){
		if(l >= r){
			return 0;
		}
		return cal(l , r , 0 , 0 , size);
	}

	void clear(){
		val.clear();
		size = 0;
	}
	
};

vector<ll> v , a;
segtree st;
sumtree ts;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	v.assign(n , 0);
	a.resize(n);
	ts.init(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++){
		int h = ts.cal(0 , a[i]);
		v[i] += a[i] - h;
		ts.set(a[i] , 1);
	}
	ts.clear();
	ts.init(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++){
		int h = ts.cal(0 , a[i]);
		v[i] += a[i] - h;
		ts.set(a[i] , 1);
	}
	ts.clear();
	for(int i = n - 1 , j = 1 ; i > 0 ; i-- , j++){
		int k = v[i] / j;
		v[i] %= j;
		v[i - 1] += k;
	}
	v[0] %= n;
	st.init(n); st.build();
	for(int i = 0 ; i < n ; i++){
		int ans = st.cal(v[i]);
		st.set(ans , 0);
		v[i] = ans;
	}
	for(int i = 0 ; i < n ; i++){
		cout<<v[i]<<' ';
	}
	cout<<'\n';
	return 0;
}