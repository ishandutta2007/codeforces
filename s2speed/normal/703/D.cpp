#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;

const int MAX_N = 1e6 + 20;

struct segtree {
	
	int sz = 0;
	vector<int> val;

	void init(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		val.assign(2 * sz , 0);
		return;
	}

	void set(int l , int r , int k , int x , int lx , int rx){
		if(rx <= l || lx >= r){
			return;
		}
		if(rx <= r && lx >= l){
			val[x] ^= k;
			return;
		}
		int mx = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		set(l , r , k , ln , lx , mx);
		set(l , r , k , rn , mx , rx);
		return;
	}

	void set(int l , int r , int k){
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	int cal(int i , int x , int lx , int rx){
		if(rx - lx == 1){
			return val[x];
		}
		int mx = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1 , h;
		if(i < mx){
			h = cal(i , ln , lx , mx);
		} else {
			h = cal(i , rn , mx , rx);
		}
		h ^= val[x];
		return h;
	}

	int cal(int i){
		return cal(i , 0 , 0 , sz);
	}

};

segtree st;
int a[MAX_N] , ans[MAX_N];
vector<pii> v , q;
map<int , int> mp;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	st.init(n);
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	for(int i = 0 ; i < m ; i++){
		int l , r;
		cin>>l>>r; l--;
		v.push_back({l , r});
		q.push_back({r , i});
	}
	sort(q.begin() , q.end()); q.push_back({-1 , -1});
	int x = 0;
	for(int i = 1 ; i <= n ; i++){
		int o = mp[a[i]];
		st.set(0 , o , a[i]);
		mp[a[i]] = i;
		while(q[x].first == i){
			int j = q[x].second;
			ans[j] = st.cal(v[j].first);
			x++;
		}
	}
	for(int i = 0 ; i < m ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}