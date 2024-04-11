#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

const ll MAX_N = 1e3 + 20 , md = 1e9 + 7;

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

struct segtree {

	int sz = 0;
	vector<int> val2 , val3;

	void init(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		val2.assign(2 * sz , 0);
		val3.assign(2 * sz , 0);
	}

	void build(vector<ll> &a , int x , int lx , int rx){
		int ln = 2 * x + 1 , rn = ln + 1;
		if(rx - lx == 1){
			if(lx < a.size()){
				if(a[lx] == 2){
					val2[x] = 1;
				} else if(a[lx] == 3){
					val3[x] = 1;
				}
			}
			return;
		}
		int m = (rx + lx) / 2;
		build(a , ln , lx , m);
		build(a , rn , m , rx);
		val2[x] = val2[ln] + val2[rn];
		val3[x] = val3[ln] + val3[rn];
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
	}

	pii cal(int l , int r , int x , int lx , int rx){
		int ln = 2 * x + 1 , rn = ln + 1;
		if(rx <= l || lx >= r){
			return {0 , 0};
		}
		if(rx <= r && lx >= l){
			return {val2[x] , val3[x]};
		}
		int m = (rx + lx) / 2;
		pii a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		a.first += b.first;
		a.second += b.second;
		return a;
	}

	pii cal(int l , int r){
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 0;
		val2.clear();
		val3.clear();
		return;
	}

};

segtree st[2 * MAX_N];
vector<ll> r[MAX_N] , c[MAX_N];
int up[MAX_N][MAX_N] , dn[MAX_N][MAX_N] , lt[MAX_N][MAX_N] , rt[MAX_N][MAX_N] , t[4000] , o[7000] , b[7000] , n;
pii ans = {0 , 0};

void tmax(pii p){
	int a2 , a3;
	a2 = ans.first - p.first;
	a3 = ans.second - p.second;
	if(a2 >= 0 && a3 >= 0){
		return;
	}
	if(a2 <= 0 && a3 <= 0){
		ans = p;
		return;
	}
	if(a2 <= 0){
		if(t[a3] < -a2){
			ans = p;
		}
		return;
	}
	if(t[-a3] >= a2){
		ans = p;
	}
	return;
}

void cross(int a[MAX_N][MAX_N]){
	for(int i = 0 ; i < n ; i++){
		r[i].clear();
		c[i].clear();
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			r[i].push_back(a[i][j]);
			c[j].push_back(a[i][j]);
		}
	}
	for(int i = 0 ; i < n ; i++){
		st[i].clear();
		st[i].init(n);
		st[i].build(r[i]);
	}
	for(int i = n ; i < 2 * n ; i++){
		st[i].clear();
		st[i].init(n);
		st[i].build(c[i - n]);
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i][0] == 0){
			up[i][0] = 0;
		} else {
			up[i][0] = -1;
		}
		for(int j = 1 ; j < n ; j++){
			if(a[i][j] == 0){
				up[i][j] = j;
			} else {
				up[i][j] = up[i][j - 1];
			}
		}
		if(a[i][n - 1] == 0){
			dn[i][n - 1] = n - 1;
		} else {
			dn[i][n - 1] = n;
		}
		for(int j = n - 2 ; j >= 0 ; j--){
			if(a[i][j] == 0){
				dn[i][j] = j;
			} else {
				dn[i][j] = dn[i][j + 1];
			}
		}
	}
	for(int j = 0 ; j < n ; j++){
		if(a[0][j] == 0){
			lt[0][j] = 0;
		} else {
			lt[0][j] = -1;
		}
		for(int i = 1 ; i < n ; i++){
			if(a[i][j] == 0){
				lt[i][j] = i;
			} else {
				lt[i][j] = lt[i - 1][j];
			}
		}
		if(a[n - 1][j] == 0){
			rt[n - 1][j] = n - 1;
		} else {
			rt[n - 1][j] = n;
		}
		for(int i = n - 2 ; i >= 0 ; i--){
			if(a[i][j] == 0){
				rt[i][j] = i;
			} else {
				rt[i][j] = rt[i + 1][j];
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(a[i][j] == 0){
				continue;
			}
			int d = 5000;
			d = min(d , i - lt[i][j]);
			d = min(d , rt[i][j] - i);
			d = min(d , j - up[i][j]);
			d = min(d , dn[i][j] - j);
			if(d == 1){
				tmax({(a[i][j] == 2) , (a[i][j] == 3)});
				continue;
			}
			pii v , h;
			h = st[j + n].cal(i - d + 1 , i + d);
			v = h;
			h = st[i].cal(j - d + 1 , j + d);
			v.first += h.first - (a[i][j] == 2);
			v.second += h.second - (a[i][j] == 3);
			tmax(v);
		}
	}
	return;
}

int a[MAX_N][MAX_N] , di[MAX_N][MAX_N];
vector<ll> v[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	t[0] = 0;
	o[0] = 1;
	b[0] = 1;
	for(int i = 1 ; i < 7000 ; i++){
		o[i] = 0;
	}
	for(int i = 1 ; i < 4000 ; i++){
		int q = 0;
		for(int j = 1 ; j < 7000 ; j++){
			o[j] += b[j - 1];
			if(o[j] >= 2){
				o[j + 1] += o[j] / 2;
				o[j] %= 2;
			}
			if(o[j] == 1){
				q = j;
			}
		}
		for(int j = 1 ; j < 7000 ; j++){
			b[j] = o[j];
		}
		t[i] = q;
	}
	bool zero = true;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		for(int j = 0 ; j < n ; j++){
			int h = s[j] - '0';
			a[i][j] = h;
			if(h != 0){
				zero = false;
			}
		}
	}
	if(zero){
		cout<<"0\n";
		return 0;
	}
	cross(a);
	for(int q = 0 , k = 0 ; k < 2 * n - 1 ; k += 2 , q++){
		int i , j;
		i = min(k , n - 1);
		j = max(k - n + 1 , 0);
		while(i >= 0 && j < n){
			v[q].push_back(a[i][j]);
			i--; j++;
		}
	}
	for(int i = 0 ; i < n ; i++){
		int q , k , o;
		q = n - v[i].size();
		k = q / 2;
		o = v[i].size() + k;
		for(int j = 0 ; j < k ; j++){
			di[i][j] = 0;
		}
		for(int j = k ; j < o ; j++){
			di[i][j] = v[i][j - k];
		}
		for(int j = o ; j < n ; j++){
			di[i][j] = 0;
		}
		v[i].clear();
	}
	cross(di);
	for(int q = 0 , k = 1 ; k < 2 * n - 1 ; k += 2 , q++){
		int i , j;
		i = min(k , n - 1);
		j = max(k - n + 1 , 0);
		while(i >= 0 && j < n){
			v[q].push_back(a[i][j]);
			i--; j++;
		}
	}
	for(int i = 0 ; i < n ; i++){
		int q , k , o;
		q = n - v[i].size();
		k = q / 2;
		o = v[i].size() + k;
		for(int j = 0 ; j < k ; j++){
			di[i][j] = 0;
		}
		for(int j = k ; j < o ; j++){
			di[i][j] = v[i][j - k];
		}
		for(int j = o ; j < n ; j++){
			di[i][j] = 0;
		}
		v[i].clear();
	}
	cross(di);
	ll r;
	r = tav(2 , ans.first);
	r *= tav(3 , ans.second);
	r %= md;
	cout<<r<<'\n';
	return 0;
}