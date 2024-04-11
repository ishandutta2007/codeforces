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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> adj[maxn] , v[2] , p[maxn] , q[maxn] , u , res;
ll a[maxn] , b[maxn] , l[maxn] , c[maxn] , o , pr[maxn] , dis[maxn] , dep = 0 , dp[maxn] , z[maxn];
bitset<maxn> d;
priority_queue<pll , vector<pll> , greater<pll>> pq;
vector<pll> ans;

bool mDFS(ll r , ll par){
	pr[r] = par;
	dp[r] = 0;
	dis[r] = dep;
	dep ^= 1;
	for(auto i : adj[r]){
		if(i == par) continue;
		if(!mDFS(i , r)) return false;
		dp[r] += dp[i];
	}
	dep ^= 1;
	v[0].clear(); v[1].clear();
	if(d[r]){
		dp[r] += (1 - (dep << 1));
		v[dep].push_back(r);
	}
	if(r == 0){
		if(dp[r] != 0) return false;
		for(auto i : adj[r]){
			if(i == par) continue;
			v[(dp[i] == -1)].push_back(z[i]);
		}
		ll vs = sze(v[0]);
		for(ll i = 0 ; i < vs ; i++){
			a[o] = v[0][i]; b[o] = v[1][i]; l[o++] = r;
		}
		return true;
	}
	if(dp[r] != -1 && dp[r] != 1) return false;
	for(auto i : adj[r]){
		if(i == par) continue;
		v[(dp[i] == -1)].push_back(z[i]);
	}
	ll vs = min(sze(v[0]) , sze(v[1]));
	for(ll i = 0 ; i < vs ; i++){
		a[o] = v[0][i]; b[o] = v[1][i]; l[o++] = r;
	}
	z[r] = v[(dp[r] == -1)][vs];
	return true;
}

void path(ll j){
	res.clear(); u.clear();
	ll h = a[j];
	while(h != l[j]){
		res.push_back(h);
		h = pr[h];
	}
	res.push_back(l[j]);
	h = b[j];
	while(h != l[j]){
		u.push_back(h);
		h = pr[h];
	}
	while(!u.empty()){
		res.push_back(u.back());
		u.pop_back();
	}
	p[j] = res;
	return;
}

void solve(){
	o = 0;
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear();
		d[i] = false;
		q[i].clear();
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		d.flip(v); d.flip(u);
	}
	if(!mDFS(0 , -1)){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(ll i = 0 ; i < o ; i++){
		c[i] = 0;
		path(i);
		for(auto j : p[i]){
			c[i] += d[j];
			if(j != a[i] && j != b[i]) q[j].push_back(i);
		}
		pq.push({c[i] , i});
	}
	ans.clear();
	while(!pq.empty()){
		pll t = pq.top(); pq.pop();
		ll v = t.second;
		if(t.first != c[v]) continue;
		ll ps = sze(p[v]);
		for(ll i = 1 ; i < ps - 1 ; i += 2){
			ans.push_back({p[v][i] , p[v][i + 1]});
		}
		for(ll i = 0 ; i < ps ; i += 2){
			ans.push_back({p[v][i] , p[v][i + 1]});
		}
		for(auto i : q[a[v]]){
			c[i]--;
			pq.push({c[i] , i});
		}
		for(auto i : q[b[v]]){
			c[i]--;
			pq.push({c[i] , i});
		}
	}
	for(auto p : ans){
		cout<<p.first + 1<<' '<<p.second + 1<<'\n';
	}
	return;
}

/*
1
5
1 2
2 3
2 4
4 5
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}