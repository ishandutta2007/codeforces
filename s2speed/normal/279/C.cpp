#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

struct item {
	ll sum;
};

struct segtree{
	
	ll size;
	vector<item> values;
	
	item NORMAL_item = {0};
	
	item single(ll v){
		return {
			v
		};
	}
	
	item merge(item a , item b){
		return {
			a.sum + b.sum
		};
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

ll a[100000] , p[100001];
vector<ll> builder , v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	segtree st;
	ll n , m , s;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	p[1] = 1;
	v.push_back(a[0]);
	for(int i = 1 ; i < n ; i++){
		if(a[i] == a[i - 1]){
			p[i + 1] = p[i];
		} else {
			v.push_back(a[i]);
			p[i + 1] = p[i] + 1;
		}
	}
	s = v.size();
	st.init(s);
	builder.assign(s , 0);
	st.build(builder);
	for(int i = 1 ; i < s - 1 ; i++){
		if((v[i] > v[i - 1] && v[i] > v[i + 1]) || (v[i] < v[i - 1] && v[i] < v[i + 1])){
			st.set(i , 1);
		}
	}
/*	for(int i = 0 ; i < s ; i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	for(int i = 1 ; i <= n ; i++){
		cout<<p[i]<<" ";
	}
	cout<<"\n";*/
	while(m--){
		ll l , r , h;
		cin>>l>>r;
		l = p[l]; r = p[r]; l--;
		if(r - l <= 1){
			cout<<"Yes\n";
		} else {
			h = st.calc(l + 1 , r - 1).sum;// cout<<h<<" "<<v[l]<<" "<<v[l + 1]<<"\n";
			if(h == 0 || h == 1 && v[l] < v[l + 1]){
				cout<<"Yes\n";
			} else {
				cout<<"No\n";
			}
		}
	}
	return 0;
}