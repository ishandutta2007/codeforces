#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

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

const ll MAX_N = 0;

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

segtree st;
vector<ll> p[26];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , ans = 0;
	string s , h;
	cin>>n>>s;
	st.init(n);
	for(int i = 0 ; i < n ; i++){
		p[s[i] - 'a'].push_back(i);
	}
	h = s;
	reverse(h.begin() , h.end());
	for(int i = n - 1 ; i >= 0 ; i--){
		ll q = h[i] - 'a' , ps = p[q].size() , e = p[q][ps - 1] , o = st.calc(0 , e);
		ans += i - e + o;
		st.set(e , 1);
		p[q].pop_back();
	}
	cout<<ans<<"\n";
	return 0;
}