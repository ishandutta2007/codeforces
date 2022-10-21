#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

int ds[maxn][52] , dsz[maxn][52];
bool dc[maxn][52];
vector<pii> s[52];

bool merge(int v , int u , int k){
	int dv , du;
	bool cv = 0 , cu = 0;
	int h = v;
	while(ds[h][k] != h){
		cv ^= dc[h][k];
		h = ds[h][k];
	}
	dv = h;
	h = u;
	while(ds[h][k] != h){
		cu ^= dc[h][k];
		h = ds[h][k];
	}
	du = h;
	if(dv == du){
		if(cv == cu) return false;
		s[k].push_back({-1 , -1});
		return true;
	}
	if(dsz[dv][k] < dsz[du][k]) swap(dv , du);
	s[k].push_back({du , dv});
	dsz[dv][k] += dsz[du][k];
	dc[du][k] = !(cv ^ cu);
	ds[du][k] = dv;
	return true;
}

void undo(int k){
	if(s[k].empty()) return;
	if(s[k].back().first == -1){
		s[k].pop_back();
		return;
	}
	int u = s[k].back().first , v = s[k].back().second; s[k].pop_back();
	dsz[v][k] -= dsz[u][k];
	dc[u][k] = 0;
	ds[u][k] = u;
	return;
}

vector<pii> ed , qu;
int ce[maxn];
bitset<maxn> ans;

struct segtree {

	int sz = 1;
	vector<vector<int>> val , del;

	void init(int n){
		while(sz < n) sz <<= 1;
		val.resize(sz << 1);
		del.resize(sz << 1);
		return;
	}

	void add(int l , int r , int i , int x , int lx , int rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x].push_back(i);
			return;
		}
		int m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , i , ln , lx , m); add(l , r , i , rn , m , rx);
		return;
	}

	void add(int l , int r , int i){
		add(l , r , i , 0 , 0 , sz);
		return;
	}

	void DFS(int x , int lx , int rx){
		for(auto j : val[x]){
			int v = ed[j].first , u = ed[j].second , k = ce[j];
			merge(v , u , k);
			del[x].push_back(k);
		}
		if(rx - lx == 1){
			if(lx < sze(qu) - 1){
				int j = qu[lx + 1].first , v = ed[j].first , u = ed[j].second , k = qu[lx + 1].second;
				if(ans[lx + 1] = merge(v , u , k)){
					ce[j] = k;
					undo(k);
				}
			}
		} else {
			int m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
			DFS(ln , lx , m); DFS(rn , m , rx);
		}
		reverse(all(del[x]));
		for(auto k : del[x]){
			undo(k);
		}
		return;
	}

	void DFS(){
		DFS(0 , 0 , sz);
		return;
	}

};

segtree st;
int ls[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ce , 0 , sizeof(ce));
	memset(ls , -1 , sizeof(ls));
	int n , m , k , q;
	cin>>n>>m>>k>>q;
	for(int j = 0 ; j <= k ; j++){
		for(int i = 0 ; i < n ; i++){
			ds[i][j] = i;
			dsz[i][j] = 1;
			dc[i][j] = false;
		}
	}
	ans[0] = true;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		ed.push_back({v , u});
	}
	for(int i = 0 ; i < q ; i++){
		int j , k;
		cin>>j>>k; j--;
		qu.push_back({j , k});
	}
	st.init(q);
	for(int i = 0 ; i < q ; i++){
		int j = qu[i].first;
		if(ls[j] != -1){
			st.add(ls[j] , i , j);
		}
		ls[j] = i;
	}
	for(int i = 0 ; i < m ; i++){
		if(ls[i] != -1){
			st.add(ls[i] , q , i);
		}
	}
	ce[qu[0].first] = qu[0].second;
	st.DFS();
	for(int i = 0 ; i < q ; i++){
		cout<<(ans[i] ? "YES\n" : "NO\n");
	}
	return 0;
}