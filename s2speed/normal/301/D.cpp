#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;

struct segtree {

	int sz = 0;
	vector<ll> val;

	void init(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		val.assign(2 * sz , 0);
	}

	void set(int l , int r , int k , int x , int lx , int rx){
		int ln = 2 * x + 1 , rn = ln + 1;
		if(rx <= l || lx >= r){
			return;
		}
		if(rx <= r && lx >= l){
			val[x] += k;
			return;
		}
		int m = (rx + lx) / 2;
		set(l , r , k , ln , lx , m);
		set(l , r , k , rn , m , rx);
		return;
	}

	void set(int l , int r , int k){
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	int cal(int i , int x , int lx , int rx){
		int ln = 2 * x + 1 , rn = ln + 1;
		if(rx - lx == 1){
			return val[x];
		}
		int m = (rx + lx) / 2 , h;
		if(i < m){
			h = cal(i , ln , lx , m);
		} else {
			h = cal(i , rn , m , rx);
		}
		h += val[x];
		return h;
	}

	int cal(int i){
		return cal(i , 0 , 0 , sz);
	}

};

vector<ll> d[MAX_N];

void d_build(int r){
	for(int i = 1 ; i <= r ; i++){
		for(int j = 2 * i ; j <= r ; j += i){
			d[j].push_back(i); d[i].push_back(j);
		}
	}
}

segtree st;
vector<pii> q , v;
int ans[MAX_N] , a[MAX_N] , p[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n , m;
	cin>>n>>m;
	d_build(n);
	for(int i = 0 ; i < MAX_N ; i++){
		p[i] = n + 1;
	}
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]; p[a[i]] = i;
	}
	st.init(n);
	for(int i = 0 ; i < m ; i++){
		int l , r;
		cin>>l>>r; l--; r--;
		q.push_back({r , i});
		v.push_back({l , r});
	}
	sort(q.begin() , q.end());
	q.push_back({-1 , -1});
	int vs = v.size();
	int x = 0;
	for(int i = 0 ; i < n ; i++){
		for(auto o : d[a[i]]){
			if(p[o] < i){
				st.set(0 , p[o] + 1 , 1);
			}
		}
		while(q[x].first == i){
			int j = q[x].second , l = v[j].first;
			ans[j] = st.cal(l);
			x++;
		}
	}
	for(int i = 0 ; i < m ; i++){
		cout<<ans[i] + v[i].second - v[i].first + 1<<'\n';
	}
	return 0;
}