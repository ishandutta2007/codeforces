#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e3 + 16 , maxm = 5e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

int ds[maxn] , a[maxm] , b[maxm] , w[maxm];
bitset<maxn> c;

int dsu(int v){
	if(v == ds[v]) return v;
	int u = ds[v];
	ds[v] = dsu(ds[v]);
	c[v] = c[v] ^ c[u];
	return ds[v];
}

void merge(int v , int u){
	int a = v , b = u;
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	c[u] = !(c[a] ^ c[b]);
	return;
}

int n , m , q;

struct segtree {

	int sz = 1;
	vector<vector<int>> val;

	void init(int n){
		while(sz < n) sz <<= 1;
		val.resize(sz << 1);
		return;
	}

	void build(int x , int lx , int rx){
		if(rx - lx == 1){
			if(lx < m) val[x].push_back(lx);
			return;
		}
		int m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		build(ln , lx , m); build(rn , m , rx);
		vector<pii> v;
		for(auto i : val[ln]){
			v.push_back({w[i] , i});
		}
		for(auto i : val[rn]){
			v.push_back({w[i] , i});
		}
		sort(all(v) , greater<pii>());
		c.reset();
		iota(ds , ds + n , 0);
		for(auto p : v){
			int i = p.second;
			if(dsu(a[i]) == dsu(b[i])){
				if(c[a[i]] == c[b[i]]){
					val[x].push_back(i);
					break;
				}
				continue;
			}
			val[x].push_back(i);
			merge(a[i] , b[i]);
		}
		return;
	}

	void build(){
		build(0 , 0 , sz);
		return;
	}

	vector<int> res;

	void cal(int l , int r , int x , int lx , int rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			for(auto i : val[x]) res.push_back(i);
			return;
		}
		int m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		cal(l , r , ln , lx , m); cal(l , r , rn , m , rx);
		return;
	}

	void cal(int l , int r){
		res.clear();
		cal(l , r , 0 , 0 , sz);
		return;
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m>>q;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin>>v>>u>>w[i]; v--; u--;
		a[i] = v; b[i] = u;
	}
	a[m] = b[m] = 0; w[m] = -1;
	st.init(m);
	st.build();
	for(int e = 0 ; e < q ; e++){
		int l , r;
		cin>>l>>r; l--;
		st.cal(l , r);
		vector<pii> v;
		for(auto i : st.res) v.push_back({w[i] , i});
		sort(all(v) , greater<pii>()); v.push_back({-1 , m});
		c.reset();
		iota(ds , ds + n , 0);
		for(auto p : v){
			int i = p.second;
			if(dsu(a[i]) == dsu(b[i])){
				if(c[a[i]] == c[b[i]]){
					cout<<w[i]<<'\n';
					break;
				}
				continue;
			}
			merge(a[i] , b[i]);
		}
	}
	return 0;
}

/*
3 3 1
1 2 4
2 3 5
3 1 6
1 3
*/