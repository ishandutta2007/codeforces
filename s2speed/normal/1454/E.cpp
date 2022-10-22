#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

const ll MAX_N = 2e5 + 20;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

set<ll> s;
set<pll> sptr;
vector<ll> adj[MAX_N] , v , f[MAX_N];
vector<pll> e;
ll z[MAX_N] , ans = 0;
pll c;
bool mark[MAX_N] , lk;

void DFS1(ll r){
	mark[r] = true;
	for(auto i : adj[r]){
		if(!mark[i]){
			sptr.insert( {min(i , r) , max(i , r)} );
			DFS1(i);
		}
	}
}

void DFS2(ll r){
	mark[r] = true;
	v.push_back(r);
	if(r == c.second){
		lk = true;
		return;
	}
	for(auto i : adj[r]){
		if(!mark[i]){
			DFS2(i);
		}
		if(lk){
			break;
		}
	}
	if(!lk){
		v.pop_back();
	}
}

void DFS3(ll r){
	mark[r] = true;
	for(auto i : adj[r]){
		if(mark[i] || s.count(i)){
			continue;
		}
		f[r].push_back(i);
		DFS3(i);
	}
	for(auto i : f[r]){
		z[r] += z[i];
	};
}

void solve(){
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		z[i] = 1;
		mark[i] = false;
		f[i].clear();
		adj[i].clear();
	}
	lk = false;
	ans = 0;
	s.clear();
	sptr.clear();
	v.clear();
	e.clear();
	for(int i = 0 ; i < n ; i++){
		ll u , v;
		cin>>u>>v; u--; v--;
		if(u > v){
			swap(u , v);
		}
		adj[u].push_back(v); adj[v].push_back(u);
		e.push_back( {u , v} );
	}
	DFS1(0);
	ll h = n;
	h *= n - 1;
	h /= 2;
	ans += h;
	for(int i = 0 ; i < n ; i++){
		if(!sptr.count(e[i])){
			c = e[i];
			break;
		}
	}
	for(int i = 0 ; i < n ; i++){
		mark[i] = false;
	}
	DFS2(c.first);
	for(auto i : v){
		s.insert(i);
	}
	for(int i = 0 ; i < n ; i++){
		mark[i] = false;
	}
	h = 0;
	for(auto i : v){
		DFS3(i);
		ll q = z[i];
		q *= n - z[i];
		h += q;
	}
	h /= 2;
	ans += h;
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}