#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

struct piii{
	int a , t , x;
};
 
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

struct segtree{
	
	int size;
	vector<int> val;
	
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		val.assign(2 * size , 0);
	}
	
	int cal(int i , int x , int lx , int rx){
		if(rx - lx == 1){
			return val[x];
		}
		int m = (rx + lx) / 2 , h;
		if(i < m){
			h = cal(i , 2 * x + 1 , lx , m);
		} else {
			h = cal(i , 2 * x + 2 , m , rx);
		}
		return h + val[x];
	}
	
	int cal(int i){
		return cal(i , 0 , 0 , size);
	}
	
	void set(int l , int r , int k , int x , int lx , int rx){
		if(lx >= r || rx <= l) return;
		if(lx >= l && rx <= r){
			val[x] += k;
			return;
		}
		int m = (lx + rx) / 2;
		set(l , r , k , 2 * x + 1 , lx , m); set(l , r , k , 2 * x + 2 , m , rx);
		return;
	}
	
	void set(int l , int r , int k){
		set(l , r , k , 0 , 0 , size);
	}

	void clear(){
		val.clear();
		size = 0;
	}
	
};

vector<piii> v;
vector<pii> o[MAX_N];
vector<int> c , ot[MAX_N] , ans[MAX_N];
segtree st[MAX_N];
int cnt[MAX_N] , p[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cnt[i] = 0;
		p[i] = 0;
		int a , t , x;
		cin>>a>>t>>x;
		v.push_back({a , t , x});
		c.push_back(x);
	}
	sort(c.begin() , c.end());
	for(int i = 0 ; i < n ; i++){
		int x;
		vector<int>::iterator it;
		it = lower_bound(c.begin() , c.end() , v[i].x);
		x = it - c.begin();
		v[i].x = x;
	}
	for(int i = 0 ; i < n ; i++){
		o[v[i].x].push_back({v[i].a , v[i].t});
		if(v[i].a == 3){
			ot[v[i].x].push_back(v[i].t);
			cnt[v[i].x]++;
		}
	}
	for(int i = 0 ; i < n ; i++){
		st[i].init(cnt[i]);
		sort(ot[i].begin() , ot[i].end());
		int os = o[i].size();
		for(int j = 0 ; j < os ; j++){
			int a = o[i][j].first , t = o[i][j].second , b;
			vector<int>::iterator it;
			it = upper_bound(ot[i].begin() , ot[i].end() , t);
			b = it - ot[i].begin();
			if(a == 3){
				b--;
				ans[i].push_back(st[i].cal(b));
			} else if(a == 1){
				st[i].set(b , n , 1);
			} else {
				st[i].set(b , n , -1);
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(v[i].a != 3) continue;
		cout<<ans[v[i].x][p[v[i].x]]<<'\n';
		p[v[i].x]++;
	}
	return 0;
}