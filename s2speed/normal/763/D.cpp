#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 1e5 + 17 , md = 2000000357 , P = 131 , inf = 2e16;
ll st[200] , sz = 200;

ll n;
ll tv[maxn];
ll d[maxn];
ll hs[maxn] , pr[maxn][2] , z[maxn];
vector<int> adj[maxn] , v , hc[maxn] , ps[maxn];
map<pll , ll> cnt;
ll res = 0;

void pDFS(ll r , ll par){
	z[r] = 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		pDFS(i , r);
		z[r] += z[i];
	}
	v.clear();
	for(ll i = 0 ; i < sz ; i++){
		v.push_back(st[i]);
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		v.push_back(hs[i]);
	}
	sort(all(v));
	ll h = 0;
	for(auto i : v){
		h *= P; h += i; h %= md;
	}
	hs[r] = h;
	return;
}

void root(ll r){
	z[r] = n;
	ll h = 0;
	for(ll i = 0 ; i < sz ; i++){
		hc[r].push_back(st[i]);
	}
	for(auto i : adj[r]){
		hc[r].push_back(hs[i]);
	}
	sort(all(hc[r]));
	for(auto i : hc[r]){
		h *= P; h += i; h %= md;
		ps[r].push_back(h);
	}
	hs[r] = h;
	return;
}

void reroot(ll v , ll u){
	pr[v][0] = hs[v]; pr[v][1] = hs[u];
	res -= (--cnt[{hs[v] , z[v]}] == 0);
	res -= (--cnt[{hs[u] , z[u]}] == 0);
	ll h = hs[v] , j = lower_bound(all(hc[v]) , hs[u]) - hc[v].begin();
	h -= tv[d[v] - j - 1] * ps[v][j] % md;
	if(j) h += tv[d[v] - j - 1] * ps[v][j - 1] % md;
	h %= md; h += (h < 0) * md;
	hs[v] = h;
	z[v] -= z[u];
	root(u);
	res += (++cnt[{hs[v] , z[v]}] == 1);
	res += (++cnt[{hs[u] , z[u]}] == 1);
	return;
}

ll ans[maxn];

void rDFS(ll r , ll par){
	ans[r] = res;
	for(auto i : adj[r]){
		if(i == par) continue;
		reroot(r , i);
		rDFS(i , r);
		res -= (--cnt[{hs[r] , z[r]}] == 0);
		res -= (--cnt[{hs[i] , z[i]}] == 0);
		hs[r] = pr[r][0]; hs[i] = pr[r][1];
		z[i] -= z[r]; z[r] = n;
		res += (++cnt[{hs[r] , z[r]}] == 1);
		res += (++cnt[{hs[i] , z[i]}] == 1);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll i = 0 ; i < sz ; i++){
		st[i] = rng() % (md - 1) + 1;
	}
	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = tv[i - 1] * P % md;
	}
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	pDFS(0 , -1);
	for(ll i = 0 ; i < n ; i++){
		d[i] = sze(adj[i]) + sz;
		res += (++cnt[{hs[i] , z[i]}] == 1);
	}
	root(0);
	rDFS(0 , -1);
	ll mx = 0 , ind = -1;
	for(ll i = 0 ; i < n ; i++){
		if(ans[i] > mx){
			mx = ans[i];
			ind = i;
		}
	}
	cout<<ind + 1<<'\n';
	return 0;
}