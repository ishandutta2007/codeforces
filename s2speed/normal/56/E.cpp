#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int , int> pii;
 
const int MAX_N = 1e5 + 20;
 
int tav(int n , int k){
	int res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

struct segtree {

	int sz = 0;
	vector<int> val , laz;

	void init(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		val.assign(2 * sz , 0);
		laz.assign(2 * sz , 0);
		return;
	}

	void shift(int x , int lx , int rx){
		if(laz[x] == 0) return;
		int ln = 2 * x + 1 , rn = ln + 1;
		val[x] += laz[x];
		if(rx - lx > 1){
			laz[ln] += laz[x];
			laz[rn] += laz[x];
		}
		laz[x] = 0;
		return;
	}

	void set(int l , int r , int k , int x , int lx , int rx){
		shift(x , lx , rx);
		int ln = 2 * x + 1 , rn = ln + 1;
		if(rx <= l || lx >= r){
			return;
		}
		if(rx <= r && lx >= l){
			val[x] += k;
			if(rx - lx > 1){
				laz[ln] += k;
				laz[rn] += k;
			}
			return;
		}
		int m = (rx + lx) / 2;
		set(l , r , k , ln , lx , m);
		set(l , r , k , rn , m , rx);
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void set(int l , int r , int k){
		set(l , r , k , 0 , 0 , sz);
		return;
	}

	int cal(int l , int r , int x , int lx , int rx){
		shift(x , lx , rx);
		int ln = 2 * x + 1 , rn = ln + 1;
		if(rx <= l || lx >= r){
			return 0;
		}
		if(rx <= r && lx >= l){
			return val[x];
		}
		int m = (rx + lx) / 2 , a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	int cal(int l , int r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
vector<pii> q , d;
int ans[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int x , h;
		cin>>x>>h;
		q.push_back({x , i});
		d.push_back({x , h - 1});
	}
	sort(q.begin() , q.end());
	ans[q[n - 1].second] = 1;
	st.init(n);
	st.set(n - 1 , n , 1);
	for(int i = n - 2 ; i >= 0 ; i--){
		st.set(i , n , 1);
		int j = q[i].second , x = d[j].first , h = d[j].second , r;
		vector<pii>::iterator it;
		it = upper_bound(q.begin() , q.end() , make_pair(x + h , n));
		r = it - q.begin();
		ans[j] = st.cal(i , r);
		st.set(i , i + 1 , ans[j] - 1);
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}