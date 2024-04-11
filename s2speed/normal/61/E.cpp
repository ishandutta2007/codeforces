#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e6;

typedef ll item;
/*struct item {
	
};*/

struct segtree{
	
	ll size;
	vector<item> values;
	
	item NORMAL_item = 0;
	
	item single(ll v){
		return v;
	}
	
	item merge(item a , item b){
		return a + b;
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		values.assign(2 * size - 1 , NORMAL_item);
	}
	
	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()) values[x] = single(a[lx]);
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
			values[x] = single(v);
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
	
	item calc(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_item;
		if(lx >= l && rx <= r){
			return values[x];
		}
		ll m = (lx + rx) / 2;
		item i1 = calc(l , r , 2 * x + 1 , lx , m) , i2 = calc(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	item calc(ll l , ll r){
		return calc(l , r , 0 , 0 , size);
	}
	
};

vector<ll> v;
set<ll> s;

ll bs(ll k){
	ll l = 0 , r = v.size();
	while(l < r){
		ll m = (l + r) / 2;
		if(v[m] == k){
			return m;
		} else if(v[m] > k){
			r = m;
		} else {
			l = m + 1;
		}
	}
	return -1;
}

ll counter[2][MAX_N] , a[MAX_N] , b[MAX_N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		counter[0][i] = 0; counter[1][i] = 0;
		cin>>a[i];
		if(s.count(a[i]) == 0){
			s.insert(a[i]);
			v.push_back(a[i]);
		}
	}
	sort(v.begin() , v.end());
	for(int i = 0 ; i < n ; i++){
		a[i] = bs(a[i]);
	}
	for(int i = 0 ; i < n ; i++){
		b[n - i - 1] = a[i];
	}
	for(int i = 0 ; i < n ; i++){
		a[i] = b[i];
	}
	segtree inv1 , inv2;
	inv1.init(n); inv2.init(n);
	for(int i = 0 ; i < n ; i++){
		ll h1 , h2;
		h1 = inv1.calc(0 , a[i]); h2 = inv2.calc(0 , a[i]);
		ans += h2;
		counter[0][a[i]] += 1;
		counter[1][a[i]] += h1;
		inv1.set(a[i] , counter[0][a[i]]); inv2.set(a[i] , counter[1][a[i]]);
	}
	cout<<ans<<"\n";
	return 0;
}