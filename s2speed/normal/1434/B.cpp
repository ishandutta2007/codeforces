#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5;

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
	
	ll calc(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_ll;
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
struct segtr{
	
	ll size;
	vector<ll> values;
	
	ll NORMAL_ll = -1;
	
	ll single(ll v , ll lx){
		if(v != -1){
			return -1;
		} else {
			return lx;
		}
	}
	
	ll merge(ll a , ll b){
		if(b != -1){
			return b;
		} else {
			return a;
		}
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		values.assign(2 * size - 1 , NORMAL_ll);
	}
	
	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()) values[x] = single(a[lx] , lx);
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
			values[x] = single(v , lx);
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
		if(lx >= r || rx <= l) return NORMAL_ll;
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

vector<ll> a;
ll t[MAX_N] , ans[MAX_N] , q[2 * MAX_N];
set<ll> se;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	segtree st;
	segtr mt;
	ll n , s = 0 , x = 0 , g = -1;
	cin>>n;
	st.init(n);
	mt.init(n);
	a.assign(n , 1);
	st.build(a);
	a.clear();
	a.assign(n , -1);
	mt.build(a);
	for(int i = 0 ; i < 2 * n ; i++){
		char c;
		cin>>c;
		if(c == '+'){
			q[i] = -1;
			s++;
			x++;
		} else {
			ll inp;
			cin>>inp; inp--;
			q[i] = inp;
			if(s == 0){
				cout<<"NO\n";
				return 0;
			}
			t[inp] = x - 1;
			ll h = st.calc(inp , n);
			if(h < s){
				cout<<"NO\n";
				return 0;
			}
			st.set(inp , 0);
			s--;
			if(g != -1){
				if(t[g] == t[inp] && inp < g){
					cout<<"NO\n";
					return 0;
				}
			}
			g = inp;
		}
	}
	for(int i = 0 ; i < n ; i++){
		ll e = mt.calc(0 , t[i] + 1);
		ans[e] = i;
		mt.set(e , 0);
	}
	x = 0;
	for(int i = 0 ; i < 2 * n ; i++){
		if(q[i] == -1){
			se.insert(ans[x]);
			x++;
		} else {
			set<ll>::iterator it = se.begin();
			if(*it != q[i]){
				cout<<"NO\n";
				return 0;
			} else {
				se.erase(it);
			}
		}
	}
	cout<<"YES\n";
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i] + 1<<" ";
	}
	cout<<"\n";
	return 0;
}