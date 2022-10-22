#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;

const ll MAXN = 3e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

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

	ll sz = 1;
	vector<ll> val , laz;

	void init(ll n){
		while(sz < n) sz *= 2;
		val.assign(sz * 2 , 0);
		laz.assign(sz * 2 , 0);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		if(laz[x] == 0) return;
		ll h = laz[x];
		laz[x] = 0;
		val[x] += h * (rx - lx);
		if(rx - lx == 1) return;
		ll ln = 2 * x + 1 , rn = 2 * x + 2;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] += k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

vector<plll> ofq;
vector<pll> bad;
vector<ll> adj[MAXN] , path;
ll ans[MAXN];
bitset<MAXN> mark , cy;
segtree st;

void DFS(ll v , ll par){
	path.push_back(v);
	mark[v] = true;
	for(auto i : adj[v]){
		if(i == par) continue;
		if(mark[i]){
			if(cy[i]) continue;
			cy[i] = true;
			ll l = i , r = i , x = path.size() - 1;
			while(path[x] != i){
				l = min(l , path[x]);
				r = max(r , path[x]);
				cy[path[x]] = true;
				x--;
			}
			bad.push_back({r , l});
			continue;
		}
		DFS(i , v);
	}
	path.pop_back();
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		DFS(i , -1);
	}
	sort(all(bad));
	bad.push_back({n , n});
	ll q;
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		ll l , r;
		cin>>l>>r; l--; r--;
		ofq.push_back({{r , l} , i});
	}
	sort(all(ofq));
	ofq.push_back({{n , n} , n});
	st.init(n);
	ll x = 0 , y = 0 , ml = -1;
	for(int i = 0 ; i < n ; i++){
		while(bad[x].first == i){
			ml = max(ml , bad[x].second);
			x++;
		}
		st.add(ml + 1 , i + 1 , 1);
		while(ofq[y].first.first == i){
			ans[ofq[y].second] = st.cal(ofq[y].first.second , ofq[y].first.first + 1);
			y++;
		}
	}
	for(int i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

/*

*/