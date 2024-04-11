#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef pair<pii , int> piii;

const ll MAX_N = 1e6 + 20 , md = 1e9 + 7;

struct segtree {

	int sz = 0;
	vector<ll> val;

	void init(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		val.assign(2 * sz , 1);
	}

	void set(int l , int r , ll k , int x , int lx , int rx){
		int ln = 2 * x + 1 , rn = ln + 1;
		if(rx <= l || lx >= r){
			return;
		}
		if(rx <= r && lx >= l){
			val[x] *= k;
			val[x] %= md;
			return;
		}
		int m = (rx + lx) / 2;
		set(l , r , k , ln , lx , m);
		set(l , r , k , rn , m , rx);
		return;
	}

	void set(int l , int r , ll k){
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(int i , int x , int lx , int rx){
		int ln = 2 * x + 1 , rn = ln + 1;
		if(rx - lx == 1){
			return val[x];
		}
		int m = (rx + lx) / 2;
		ll h;
		if(i < m){
			h = cal(i , ln , lx , m);
		} else {
			h = cal(i , rn , m , rx);
		}
		h *= val[x]; h %= md;
		return h;
	}

	ll cal(int i){
		return cal(i , 0 , 0 , sz);
	}

};

vector<ll> pr[MAX_N] , v;
ll l[MAX_N] , t[MAX_N];
int a[MAX_N] , gh[MAX_N];

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

void prime(){
	gh[0] = 0;
	gh[1] = 0;
	for(int i = 2 ; i < MAX_N ; i++){
		gh[i] = 1;
	}
	for(int i = 2 ; i < MAX_N ; i++){
		if(gh[i]){
			v.push_back(i);
			gh[i] = v.size() - 1;
			pr[i].push_back(i);
			for(int j = 2 * i ; j < MAX_N ; j += i){
				pr[j].push_back(i);
				gh[j] = false;
			}
		}
	}
}

segtree st;
vector<piii> q;
ll ans[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	st.init(n);
	int m;
	cin>>m;
	for(int i = 0 ; i < m ; i++){
		int l , r;
		cin>>l>>r; l--; r--;
		q.push_back({{r , l} , i});
	}
	sort(q.begin() , q.end());
	q.push_back({{-1 , -1} , -1});
	int vs = v.size();
	for(int i = 0 ; i < vs ; i++){
		l[i] = -1;
		ll h = tav(v[i] , md - 2);
		h *= (v[i] - 1);
		h %= md;
		t[i] = h;
	}
	int x = 0;
	for(int i = 0 ; i < n ; i++){
		for(auto p : pr[a[i]]){
			st.set(l[gh[p]] + 1 , i + 1 , t[gh[p]]);
			l[gh[p]] = i;
		}
		st.set(0 , i + 1 , a[i]);
		while(q[x].first.first == i){
			int l = q[x].first.second , j = q[x].second;
			ans[j] = st.cal(l);
			x++;
		}
	}
	for(int i = 0 ; i < m ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}