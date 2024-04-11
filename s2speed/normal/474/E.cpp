#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
struct segtree {

	ll sz = 1;
	vector<pll> val;

	void init(ll n){
		while(sz < n) sz *= 2;
		val.assign(2 * sz , {0 , -1});
		return;
	}

	void set(int i , ll o , int x , int lx , int rx){
		if(rx - lx == 1){
			val[x] = {o , lx};
			return;
		}
		int m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		if(i < m){
			set(i , o , ln , lx , m);
		} else {
			set(i , o , rn , m , rx);
		}
		if(val[ln].first >= val[rn].first){
			val[x] = val[ln];
		} else {
			val[x] = val[rn];
		}
		return;
	}

	void set(int i , ll o){
		set(i , o , 0 , 0 , sz);
		return;
	}

	pll cal(int l , int r , int x , int lx , int rx){
		if(rx <= l || lx >= r){
			return {0 , -1};
		}
		if(rx <= r && lx >= l){
			return val[x];
		}
		int m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		pll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		if(a.first >= b.first){
			return a;
		}
		return b;
	}

	pll cal(int l , int r){
		if(l >= r){
			return {0 , -1};
		}
		return cal(l , r , 0 , 0 , sz);
	}

};

ll a[MAX_N] , nt[MAX_N] , b[MAX_N] , n;
vector<pll> v;
vector<ll> h;

int bs(ll k){
	int l = 0 , r = n + 1;
	while(l < r - 1){
		int m = (r + l) / 2;
		if(h[m] > k && h[m - 1] <= k){
			return m;
		}
		if(h[m] <= k){
			l = m + 1;
		} else {
			r = m;
		}
	}
	return l;
}

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll d;
	cin>>n>>d;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		h.push_back(a[i]);
		v.push_back({a[i] , i});
	}
	h.push_back(1e16);
	sort(h.begin() , h.end());
	sort(v.begin() , v.end());
	for(int i = 0 ; i < n ; i++){
		b[v[i].second] = i;
	}
	st.init(n);
	for(int i = n - 1 ; i >= 0 ; i--){
		int l = bs(a[i] - d) , r = bs(a[i] + d - 1);
		pll o = st.cal(0 , l) , p = st.cal(r , n);
		if(o.first >= p.first){
			nt[i] = o.second;
			st.set(b[i] , o.first + 1);
		} else {
			nt[i] = p.second;
			st.set(b[i] , p.first + 1);
		}
	}
	pll p = st.cal(0 , n);
	cout<<p.first<<'\n';
	ll x = p.second;
	while(x != -1){
		x = v[x].second;
		cout<<x + 1<<' ';
		x = nt[x];
	}
	return 0;
}