#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 1e6 + 20;
 
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
	ll a0 , a1 , b0 , b1;
};

struct segtree {

	ll size = 0;
	vector<item> val;
	vector<ll> laz;

	item merge(item a , item b){
		item c;
		c.a0 = a.a0 + b.a0;
		c.a1 = a.a1 + b.a1;
		c.b0 = max(a.b0 + b.a1 , a.a0 + b.b0);
		c.b1 = max(a.b1 + b.a0 , a.a1 + b.b1);
		return c;
	}

	void init(ll n){
		size = 1;
		while(size < n){
			size *= 2;
		}
		val.assign(2 * size , {0 , 0 , 0 , 0});
		laz.assign(2 * size , 0);
	}

	void build(string &a , ll x , ll lx , ll rx){
		ll ln = 2 * x + 1 , rn = 2 * x + 2;
		if(rx - lx == 1){
			if(lx < a.size()){
				if(a[lx] == '4'){
					val[x] = {1 , 0 , 1 , 1};
				} else {
					val[x] = {0 , 1 , 1 , 1};
				}
			}
			return;
		}
		ll m = (rx + lx) / 2;
		build(a , ln , lx , m);
		build(a , rn , m , rx);
		val[x] = merge(val[ln] , val[rn]);
		return;
	}

	void build(string &a){
		build(a , 0 , 0 , size);
		return;
	}

	void set(ll l , ll r , ll x , ll lx , ll rx){
		ll ln = 2 * x + 1 , rn = 2 * x + 2;
		if(laz[x]){
			swap(val[x].a0 , val[x].a1);
			swap(val[x].b0 , val[x].b1);
			if(rx - lx > 1){
				laz[ln] ^= 1;
				laz[rn] ^= 1;
			}
			laz[x] = 0;
		}
		if(rx <= r && lx >= l){
			swap(val[x].a0 , val[x].a1);
			swap(val[x].b0 , val[x].b1);
			if(rx - lx > 1){
				laz[ln] ^= 1;
				laz[rn] ^= 1;
			}
			return;
		}
		if(rx <= l || lx >= r){
			return;
		}
		ll m = (lx + rx) / 2;
		set(l , r , ln , lx , m);
		set(l , r , rn , m , rx);
		val[x] = merge(val[ln] , val[rn]);
		return;
	}

	void set(ll l , ll r){
		set(l , r , 0 , 0 , size);
		return;
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	ll n , q;
	cin>>n>>q>>s;
	st.init(n);
	st.build(s);
	while(q--){
		cin>>s;
		if(s == "count"){
			cout<<st.val[0].b0<<'\n';
		} else {
			ll l , r;
			cin>>l>>r; l--;
			st.set(l , r);
		}
	}
	return 0;
}