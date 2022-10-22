#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 3e5;

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

bool mark[MAX_N];
ll d[MAX_N] , p[300001] , dad[MAX_N] , a[MAX_N] , g = -1 , bf = -1 , r , ans = 0;
vector< pair<ll , ll> > adj[MAX_N];
set<ll> b;
set< pair<ll , ll> > s;
stack<ll> st;

void DFS(){
	ll q = st.top() , qs = adj[q].size() , dp = 0 , ed = -1;
	if(dad[q] != -1 && b.find(q) != b.end()){
		dp++;
	}
	for(int i = 0 ; i < qs ; i++){
		ll u = adj[q][i].first;
		if(mark[u] == false){
			st.push(u);
			mark[u] = true;
			dad[u] = q;
			DFS();
			dp += p[adj[q][i].second];
		}
		if(u == dad[q]){
			ed = adj[q][i].second;
		}
	}
	if(q != r){
		p[ed] = dp;
		if(dp % 2 == 1){
			ans++;
		}
	}
	st.pop();
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		if(a[i] == -1 && g == -1){
			g = i;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		ll u , v; cin>>u>>v; u--; v--; d[u]++; d[v]++;
		pair<ll , ll> h , l;
		h = make_pair(u , v); l = make_pair(v , u);
		if(s.find(h) != s.end()){
			continue;
		}
		s.insert(h); s.insert(l);
		adj[u].push_back( make_pair(v , i) );
		adj[v].push_back( make_pair(u , i) );
	}
	for(int i = 0 ; i < m ; i++){
		p[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		mark[i] = false;
		if(a[i] == -1){
			continue;
		}
		ll h = d[i];
		if(h % 2 != a[i]){
			b.insert(i);
			if(bf == -1){
				bf = i;
			}
		}
	}
	if(bf == -1){
		cout<<m<<"\n";
		for(int i = 1 ; i <= m ; i++){
			cout<<i<<"\n";
		}
		return 0;
	}
	if(b.size() % 2 == 1 && g == -1){
		cout<<"-1\n";
		return 0;
	}
	if(g == -1){
		r = bf;
	} else {
		r = g;
	}
	st.push(r);
	mark[r] = true;
	dad[r] = -1;
	DFS();
	cout<<m - ans<<"\n";
	for(int i = 1 ; i <= m ; i++){
		if(p[i] % 2 == 0){
			cout<<i<<"\n";
		}
	}
	return 0;
}