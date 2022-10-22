#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll {ll first , second , third;};
struct piii {int first , second , third;};

const ll MAXN = 3e5 + 20 , md = 1e9 + 7;
 
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

vector<pll> ed , adj[MAXN];
vector<ll> tdj[MAXN];
bitset<MAXN> mark , tree;
ll st[MAXN] , ft[MAXN] , nt[MAXN] , xt[MAXN] , tme = 0 , dis[MAXN] , dep = 0;
bool ans = true;

void eDFS(ll r){
	mark[r] = true;
	st[r] = tme++;
	dis[r] = dep++;
	for(auto p : adj[r]){
		ll i = p.first , ind = p.second;
		if(mark[i]) continue;
		tdj[r].push_back(i);
		tree[ind] = true;
		eDFS(i);
	}
	ft[r] = tme;
	dep--;
	return;
}

void tDFS(ll r , ll par){
	for(auto i : tdj[r]){
		tDFS(i , r);
	}
	nt[r] = st[r];
	xt[r] = st[r];
	for(auto i : tdj[r]){
		if(i == par) continue;
		nt[r] = min(nt[r] , nt[i]);
		xt[r] = max(xt[r] , xt[i]);
	}
	for(auto p : adj[r]){
		ll i = p.first;
		if(i == par) continue;
		nt[r] = min(nt[r] , st[i]);
		xt[r] = max(xt[r] , st[i]);
	}
	if(par == -1) return;
	if(st[r] <= nt[r] && ft[r] > xt[r]){
		ans = false;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back({u , i}); adj[u].push_back({v , i});
		ed.push_back({v , u});
	}
	eDFS(0);
	tDFS(0 , -1);
	if(!ans){
		cout<<"0\n";
		return 0;
	}
	for(int i = 0 ; i < m ; i++){
		ll v = ed[i].first , u = ed[i].second;
		if(dis[v] < dis[u]) swap(v , u);
		v++; u++;
		if(tree[i]){
			cout<<u<<' '<<v<<'\n';
		} else {
			cout<<v<<' '<<u<<'\n';
		}
	}
	return 0;
}