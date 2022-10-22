#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 15 , MAXM = 1e3 + 15 , md = 1e9 + 7 , inf = 2e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

int n , m;
bitset<MAXM> gh;

void prime(){
	gh.set(); gh[0] = false; gh[1] = false;
	for(int i = 2 ; i < m ; i++){
		if(gh[i]){
			for(int j = i * i ; j < m ; j += i){
				gh[j] = false;
			}
		}
	}
	for(int i = m ; i < MAXM ; i++){
		gh[i] = false;
	}
	return;
}

void rotate(int x , int k);

struct segtree {

	int sz = 1;
	vector< bitset<MAXM> > val;
	vector<int> laz;
	bitset<MAXM> z , res;

	void init(int n){
		while(sz < n) sz <<= 1;
		val.assign(2 * sz , z);
		laz.assign(2 * sz , 0);
		return;
	}

	void build(vector<int> &a , int x , int lx , int rx){
		if(rx - lx == 1){
			if(lx < n){
				val[x][a[lx] % m] = true;
			}
			return;
		}
		int m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		val[x] = val[ln] | val[rn];
		return;
	}

	void build(vector<int> &a){
		build(a , 0 , 0 , sz);
		return;
	}

	void shift(int x , int lx , int rx){
		int h = laz[x];
		laz[x] = 0;
		h %= m;
		if(h == 0) return;
		rotate(x , h);
		if(rx - lx == 1) return;
		int ln = 2 * x + 1 , rn = ln + 1;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void add(int l , int r , int k , int x , int lx , int rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		int m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		val[x] = val[ln] | val[rn];
		return;
	}

	void add(int l , int r , int k){
		k %= m; k = m - k;
		if(k == m) return;
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	void cal(int l , int r , int x , int lx , int rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			res |= val[x];
			return;
		}
		int m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		cal(l , r , ln , lx , m); cal(l , r , rn , m , rx);
		return;
	}

	int cal(int l , int r){
		res.reset();
		cal(l , r , 0 , 0 , sz);
		res &= gh;
		return res.count();
	}

};

/*
7 7
5 4 5 1 4 6 6
1 2
1 3
2 4
2 5
3 6
3 7
3
2 1
1 2 2
2 5
*/

segtree st;

void rotate(int x , int k){
	bitset<MAXM> h = st.val[x] << (MAXM - k);
	st.val[x] >>= k;
	h >>= (MAXM - m);
	st.val[x] |= h;
	return;
}

vector<int> adj[MAXN];
int bt[MAXN] , ft[MAXN] , tme = 0;

void DFS(int r , int par){
	bt[r] = tme++;
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	ft[r] = tme;
	return;
}

int a[MAXN];
vector<int> b;

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>m; b.resize(n);
	prime();
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	st.init(n);
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	for(int i = 0 ; i < n ; i++){
		b[bt[i]] = a[i];
	}
//	for(int i = 0 ; i < n ; i++){
//		cout<<b[i]<<' ';
//	}
//	cout<<'\n';
	st.build(b);
//	for(int i = 0 ; i < n ; i++){
//		cout<<bt[i]<<' '<<ft[i]<<'\n';
//	}
	int q;
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		int t;
		cin>>t;
		if(t == 1){
			int v , k;
			cin>>v>>k; v--;
			st.add(bt[v] , ft[v] , k);
		} else {
			int v;
			cin>>v; v--;
			cout<<st.cal(bt[v] , ft[v])<<'\n';
		}
	}
	return 0;
}