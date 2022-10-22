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

struct item {
	ll sum , inm , ma;
};

struct segtree{
	
	ll size;
	vector<item> values;
	
	item NORMAL_item = {0 , -1 , -1};
	
	item single(ll v){
		return {
			v,
			0,
			v
		};
	}
	
	item merge(item a , item b){
		item p;
		p.sum = a.sum + b.sum;
		if(a.ma >= b.ma){
			p.ma = a.ma;
			p.inm = a.inm;
		} else {
			p.ma = b.ma;
			p.inm = b.inm;
		}
		return p;
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		values.assign(2 * size - 1 , NORMAL_item);
	}
	
	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				values[x] = single(a[lx]);
				values[x].inm = lx;
			}
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
			values[x].inm = lx;
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
	
	item cal(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_item;
		if(lx >= l && rx <= r){
			return values[x];
		}
		ll m = (lx + rx) / 2;
		item i1 = cal(l , r , 2 * x + 1 , lx , m) , i2 = cal(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	item cal(ll l , ll r){
		return cal(l , r , 0 , 0 , size);
	}

	void clear(){
		values.clear();
		size = 0;
	}
	
};

vector<ll> v;
segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	st.init(n);
	v.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	st.build(v);
	while(q--){
		ll op;
		cin>>op;
		if(op == 1){
			ll l , r;
			item h;
			cin>>l>>r; l--;
			h = st.cal(l , r);
			cout<<h.sum<<'\n';
		} else if(op == 2){
			item h;
			ll l , r , m;
			cin>>l>>r>>m; l--;
			h = st.cal(l , r);
			while(h.ma >= m){
				ll i = h.inm;
				st.set(i , h.ma % m);
				h = st.cal(l , r);
			}
		} else {
			ll i , x;
			cin>>i>>x; i--;
			st.set(i , x);
		}
	}
	return 0;
}