#include<bits/stdc++.h>
 
using namespace std;
typedef pair<int , int> pint;
 
const int MAX_N = 1e6 + 20;
 
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

	int size = 0;
	vector<int> val , laz;

	void init(int n){
		size = 1;
		while(size < n){
			size *= 2;
		}
		val.assign(2 * size , 0);
		laz.assign(2 * size , -1);
	}

	void build(string &a , char c , int x , int lx , int rx){
		int ln = 2 * x + 1 , rn = 2 * x + 2;
		if(rx - lx == 1){
			if(lx < a.size()){
				val[x] = (a[lx] == c);
			}
			return;
		}
		int m = (rx + lx) / 2;
		build(a , c , ln , lx , m);
		build(a , c , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void build(string &a , char c){
		build(a , c , 0 , 0 , size);
		return;
	}

	void set(int l , int r , int k , int x , int lx , int rx){
		int ln = 2 * x + 1 , rn = 2 * x + 2;
		if(laz[x] != -1){
			val[x] = (rx - lx) * laz[x];
			if(rx - lx > 1){
				laz[ln] = laz[x];
				laz[rn] = laz[x];
			}
			laz[x] = -1;
		}
		if(rx <= r && lx >= l){
			val[x] = (rx - lx) * k;
			if(rx - lx > 1){
				laz[ln] = k;
				laz[rn] = k;
			}
			return;
		}
		if(rx <= l || lx >= r){
			return;
		}
		int m = (lx + rx) / 2;
		set(l , r , k , ln , lx , m);
		set(l , r , k , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(int l , int r , int k){
		if(l >= r){
			return;
		}
		set(l , r , k , 0 , 0 , size);
		return;
	}

	int cal(int l , int r , int x , int lx , int rx){
		int ln = 2 * x + 1 , rn = 2 * x + 2;
		if(laz[x] != -1){
			val[x] = (rx - lx) * laz[x];
			if(rx - lx > 1){
				laz[ln] = laz[x];
				laz[rn] = laz[x];
			}
			laz[x] = -1;
		}
		if(rx <= r && lx >= l){
			return val[x];
		}
		if(rx <= l || lx >= r){
			return 0;
		}
		int m = (rx + lx) / 2;
		int a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return (a + b);
	}

	int cal(int l , int r){
		return cal(l , r , 0 , 0 , size);
	}

};

segtree st[26];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	int n , q;
	cin>>n>>q>>s;
	char c = 'a';
	for(int i = 0 ; i < 26 ; i++ , c++){
		st[i].init(n);
		st[i].build(s , c);
	}
	while(q--){
		int l , r , o[26] , x , y;
		bool b;
		cin>>l>>r>>b; l--;
		for(int i = 0 ; i < 26 ; i++){
			o[i] = st[i].cal(l , r);
		}
		if(b){
			y = l;
			for(int i = 0 ; i < 26 ; i++){
				x = y;
				y += o[i];
				st[i].set(l , x , 0);
				st[i].set(x , y , 1);
				st[i].set(y , r , 0);
			}
		} else {
			y = l;
			for(int i = 25 ; i >= 0 ; i--){
				x = y;
				y += o[i];
				st[i].set(l , x , 0);
				st[i].set(x , y , 1);
				st[i].set(y , r , 0);
			}
		}
	}
	string ans;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 26 ; j++){
			if(st[j].cal(i , i + 1) == 1){
				ans += (j + 'a');
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}