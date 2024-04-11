#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
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
	int sum , l1;
};

struct segtree{
	
	ll size;
	vector<item> val;
	
	item NORMAL_item = {0 , -1};
	
	item merge(item a , item b){
		item h;
		h.sum = a.sum + b.sum;
		if(a.l1 != -1){
			h.l1 = a.l1;
		} else {
			h.l1 = b.l1;
		}
		return h;
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		val.assign(2 * size - 1 , NORMAL_item);
	}
	
	void set(ll i , ll v , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = {1 , lx};
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
	
	item cal(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_item;
		if(lx >= l && rx <= r){
			return val[x];
		}
		ll m = (lx + rx) / 2;
		item i1 = cal(l , r , 2 * x + 1 , lx , m) , i2 = cal(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	item cal(ll l , ll r){
		return cal(l , r , 0 , 0 , size);
	}

	void clear(){
		val.clear();
		size = 0;
	}
	
};

int a[MAX_N] , p[MAX_N];
segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--; p[i] = 0;
	}
	st.init(n);
	for(int i = 0 ; i < n ; i++){
		item h = st.cal(a[i] , n);
		if(h.sum == 0){
			p[a[i]]--;
		} else if(h.sum == 1){
			p[h.l1]++;
		}
		st.set(a[i] , 1);
	}
	int ans = 1 , m = -1;
	for(int i = 0 ; i < n ; i++){
		if(p[i] > m){
			ans = i + 1;
			m = p[i];
		}
	}
	cout<<ans<<'\n';
	return 0;
}