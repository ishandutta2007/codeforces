#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;

struct segtree{
	
	ll size;
	vector<ll> val , rv;
	
	ll NORMAL_ll = -1;
	
	ll merge(ll a , ll b){
		if(a == -1 || b == -1){
			return max(a , b);
		}
		if(rv[a] >= rv[b]){
			return a;
		}
		return b;
	}
	
	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		val.assign(2 * size - 1 , NORMAL_ll);
		rv.assign(size , 0);
	}
	
	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()) val[x] = lx;
			return;
		}
		ll m = (lx + rx) / 2;
		build(a , 2 * x + 1 , lx , m); build(a , 2 * x + 2 , m , rx);
		val[x] = merge(val[2 * x + 1] , val[2 * x + 2]);
		return;
	}
	
	void build(vector<ll> &a){
		int as = a.size();
		for(int i = 0 ; i < as ; i++){
			rv[i] = a[i];
		}
		build(a , 0 , 0 , size);
	}
	
	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(lx >= r || rx <= l) return NORMAL_ll;
		if(lx >= l && rx <= r){
			return val[x];
		}
		ll m = (lx + rx) / 2;
		ll i1 = cal(l , r , 2 * x + 1 , lx , m) , i2 = cal(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , size);
	}

	void clear(){
		val.clear();
		size = 0;
	}
	
};
 
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

ll ne[MAX_N][30] , pe[MAX_N][30] , mot = 0;
vector<ll> a;
segtree st;

void solve(ll l , ll r){
	if(l >= r) return;
	ll o = st.cal(l , r) , lt = l - 1 , rt = r , h = 1;
	for(int j = 0 ; j < 30 ; j++){
		ll q = a[o] & h;
		if(q == 0){
			rt = min(rt , ne[o][j]);
			lt = max(lt , pe[o][j]);
		}
		h *= 2;
	}
	mot += 1ll * (o - lt) * (rt - o);
	solve(l , o); solve(o + 1 , r);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	a.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	st.init(n);
	st.build(a);
	int h = 1;
	for(int j = 0 ; j < 30 ; j++){
		if(a[0] & h){
			pe[0][j] = 0;
		} else {
			pe[0][j] = -1;
		}
		h *= 2;
	}
	h = 1;
	for(int j = 0 ; j < 30 ; j++){
		if(a[n - 1] & h){
			ne[n - 1][j] = n - 1;
		} else {
			ne[n - 1][j] = n;
		}
		h *= 2;
	}
	for(int i = 1 ; i < n ; i++){
		h = 1;
		for(int j = 0 ; j < 30 ; j++){
			if(a[i] & h){
				pe[i][j] = i;
			} else {
				pe[i][j] = pe[i - 1][j];
			}
			h *= 2;
		}
	}
	for(int i = n - 2 ; i >= 0 ; i--){
		h = 1;
		for(int j = 0 ; j < 30 ; j++){
			if(a[i] & h){
				ne[i][j] = i;
			} else {
				ne[i][j] = ne[i + 1][j];
			}
			h *= 2;
		}
	}
	solve(0 , n);
	ll ans = 1ll * n * (n + 1) / 2;
	ans -= mot;
	cout<<ans<<'\n';
	return 0;
}