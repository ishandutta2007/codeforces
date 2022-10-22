#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2e5 + 20;

struct segtree{
	
	ll size;
	vector<ll> values;
	
	ll NORMAL_ll = 0;
	
	ll single(ll v){
		return v;
	}
	
	ll merge(ll a , ll b){
		return a + b;
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		values.assign(2 * size - 1 , NORMAL_ll);
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
	
	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_ll;
		if(lx >= l && rx <= r){
			return values[x];
		}
		ll m = (lx + rx) / 2;
		ll i1 = cal(l , r , 2 * x + 1 , lx , m) , i2 = cal(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , size);
	}

	void clear(){
		values.clear();
		size = 0;
	}
	
};

vector<pll> seg , e;
vector<ll> v;
set<ll> s;
segtree st;
ll n , ans[MAX_N];
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll l , r;
		cin>>l>>r;
		if(!s.count(l)){
			s.insert(l);
			v.push_back(l);
		}
		if(!s.count(r)){
			s.insert(r);
			v.push_back(r);
		}
		seg.push_back( {l , r} );
	}
	sort(v.begin() , v.end());
	for(int i = 0 ; i < n ; i++){
		ll l = seg[i].first , r = seg[i].second;
		l = (lower_bound(v.begin() , v.end() , l) - v.begin());
		r = (lower_bound(v.begin() , v.end() , r) - v.begin());
		seg[i] = {l , r};
		e.push_back(seg[i]);
	}
	sort(seg.begin() , seg.end() , greater<pll>());
	st.init(2 * n);
	for(int i = 0 ; i < n ; i++){
		ans[n - i - 1] = st.cal(seg[i].first , seg[i].second);
		st.set(seg[i].second , 1);
	}
	reverse(seg.begin() , seg.end());
	for(int i = 0 ; i < n ; i++){
		int j = (lower_bound(seg.begin() , seg.end() , e[i]) - seg.begin());
		cout<<ans[j]<<'\n';
	}
	return 0;
}