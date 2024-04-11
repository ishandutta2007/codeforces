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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

ll ds[maxn] , dsz[maxn] , cnt;
vector<ll> dv;

ll dsu(ll v){
	ll h = v;
	while(ds[h] != h){
		h = ds[h];
	}
	return h;
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(v == u){
		dv.push_back(-1);
		return;
	}
	if(dsz[v] < dsz[u]) swap(v , u);
	cnt -= dsz[v] & 1;
	cnt -= dsz[u] & 1;
	dsz[v] += dsz[u];
	cnt += dsz[v] & 1;
	ds[u] = v;
	dv.push_back(u);
	return;
}

void undo(){
	ll u = dv.back(); dv.pop_back();
	if(u == -1) return;
	ll v = ds[u];
	cnt -= dsz[v] & 1;
	dsz[v] -= dsz[u];
	cnt += dsz[v] & 1;
	cnt += dsz[u] & 1;
	ds[u] = u;
	return;
}

ll n , m;
vector<pll> ed , sr;
ll pt = 0 , ans[maxn];

struct segtree {

	ll sz = 1;
	vector<vector<ll>> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.resize(sz << 1);
		return;
	}

	void add(ll l , ll r , ll i , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x].push_back(i);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , i , ln , lx , m); add(l , r , i , rn , m , rx);
		return;
	}

	void add(ll l , ll r , ll i){
		if(l >= r) return;
		add(l , r , i , 0 , 0 , sz);
		return;
	}

	void DFS(ll x , ll lx , ll rx){
		if(lx >= m) return;
		for(auto i : val[x]){
			merge(ed[i].first , ed[i].second);
		}
		if(rx - lx == 1){
			while(cnt && pt <= m){
				if(sr[pt].second > lx){
					pt++;
					continue;
				}
				ll i = sr[pt++].second;
				merge(ed[i].first , ed[i].second);
				add(lx , lx + 1 , i);
				add(i , lx , i);
			}
			ans[lx] = sr[pt - 1].first;
		} else {
			ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
			DFS(rn , m , rx);
			DFS(ln , lx , m);
		}
		ll h = sze(val[x]);
		while(h){
			undo();
			h--;
		}
		return;
	}

	void DFS(){
		DFS(0 , 0 , sz);
		return;
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ans , 0 , sizeof(ans));
	cin>>n>>m;
	if(n & 1){
		while(m){
			cout<<"-1\n";
			m--;
		}
		return 0;
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		ed.push_back({v , u});
		sr.push_back({w , i});
	}
	sort(all(sr)); sr.push_back({-1 , 0});
	st.init(m);
	iota(ds , ds + n , 0);
	fill(dsz , dsz + n , 1);
	cnt = n;
	st.DFS();
	for(ll i = 0 ; i < m ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}