#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 3e5;

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
	
	ll NORMAL_ll = -1;
	
	ll merge(ll a , ll b){
		if(a != -1){
			return a;
		} else {
			return b;
		}
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		values.assign(2 * size - 1 , NORMAL_ll);
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
			values[x] = -1;
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
ll t[MAX_N];
vector< pair<ll , ll> > c;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	segtree st;
	ll n , k , ans = 0;
	cin>>n>>k;
	st.init(n);
	a.assign(n , 0);
	st.build(a);
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		c.push_back( {inp , i} );
	}
	sort(c.begin() , c.end() , greater< pair<ll , ll> >());
	for(int i = 0 ; i < n ; i++){
		ll v = c[i].first , ind = c[i].second , o;
		o = st.calc(max(0LL , ind - k) , n);
		t[ind] = o;
		st.set(o , -1);
		ans += (o + k - ind) * v;
	}
	cout<<ans<<"\n";
	for(int i = 0 ; i < n ; i++){
		cout<<t[i] + k + 1<<" ";
	}
	return 0;
}