#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 3e5 + 20 , md = 1e9 + 7;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

vector<ll> dsu[MAX_N];
ll ds[MAX_N] , p[MAX_N] , nt[MAX_N] , pt[MAX_N] , lds[MAX_N] , fds[MAX_N] , sds[MAX_N] , d[MAX_N];
vector<ll> adj[MAX_N];
bool mark[MAX_N] , ans = false , s[MAX_N];
set<pll> st;

void DFS(ll r){
	mark[r] = true;
	s[r] = true;
	for(auto i : adj[r]){
		if(s[i]){
			ans = true;
			return;
		}
		if(mark[i]){
			continue;
		}
		DFS(i);
		if(ans){
			return;
		}
	}
	s[r] = false;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		fds[i] = i;
		lds[i] = i;
		ds[i] = i;
		dsu[i].push_back(i);
		nt[i] = -1;
		pt[i] = -1;
		mark[i] = false;
		s[i] = false;
		d[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		cin>>p[i]; p[i]--;
	}
	for(int i = 0 ; i < k ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		if(ds[u] == ds[v]){
			ans = true;
			continue;
		}
		if(nt[v] != -1){
			ans = true;
			continue;
		}
		if(pt[u] != -1){
			ans = true;
			continue;
		}
		nt[v] = u;
		pt[u] = v;
		ll q = ds[u] , y = ds[v];
		if(dsu[ds[v]].size() < dsu[ds[u]].size()){
			swap(v , u);
		}
		ll h = ds[u];
		for(auto o : dsu[h]){
			ds[o] = ds[v];
			dsu[ds[v]].push_back(o);
		}
		dsu[h].clear();
		lds[ds[v]] = lds[q];
		fds[ds[v]] = fds[y];
	}
	if(ans){
		cout<<"0\n";
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		if(dsu[i].size() == 0){
			continue;
		}
		ll x = fds[i] , y = 0;
		while(x != lds[i]){
			sds[x] = y;
			y++;
			x = nt[x];
		}
		sds[x] = y;
	}
	for(int i = 0 ; i < n ; i++){
		if(p[i] == -1){
			continue;
		}
		if(ds[i] == ds[p[i]]){
			if(sds[i] < sds[p[i]]){
				cout<<"0\n";
				return 0;
			}
			continue;
		}
		pll o = {ds[p[i]] , ds[i]};
		if(st.count(o) == 0){
			st.insert(o);
			adj[ds[p[i]]].push_back(ds[i]);
			d[ds[i]]++;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(!mark[i]){
			DFS(i);
		}
	}
	if(ans){
		cout<<"0\n";
		return 0;
	}
	st.clear();
	for(int i = 0 ; i < n ; i++){
		st.insert({d[i] , i});
		mark[i] = false;
	}
	while(st.size() > 0){
		pii o = *st.begin();
		ll i = o.second;
		if(dsu[i].size() == 0){
			st.erase(st.begin());
			mark[i] = true;
			continue;
		}
		for(auto v : adj[i]){
			if(!mark[v]){
				st.erase({d[v] , v});
				d[v]--;
				st.insert({d[v] , v});
			}
		}
		ll x = fds[i];
		while(x != lds[i]){
			cout<<x + 1<<' ';
			x = nt[x];
		}
		cout<<x + 1<<' ';
		st.erase(o);
		mark[i] = true;
	}
	cout<<'\n';
	return 0;
}