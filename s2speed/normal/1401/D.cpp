#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll md = 1e9 + 7;

vector<ll> adj[100000] , counter , p;
stack<ll> st;
bool mark[100000];

void DFS(){
	ll v = st.top() , ads = adj[v].size();
	for(int i = 0 ; i < ads ; i++){
		if(mark[adj[v][i]] == true){
			mark[adj[v][i]] = false;
			st.push(adj[v][i]);
			DFS();
			counter[v] += counter[adj[v][i]];
		}
	}
	st.pop();
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	mark[0] = false;
	ll t;
	cin>>t;
	while(t--){
		ll n , m , h , ans = 0;
		cin>>n;
		counter.assign(n , 1);
		for(int i = 1 ; i < n ; i++){
			mark[i] = true;
			ll u , v;
			cin>>u>>v; u--; v--;
			adj[u].push_back(v); adj[v].push_back(u);
		}
		st.push(0);
		DFS();
		for(int i = 0 ; i < n ; i++){
			counter[i] *= (n - counter[i]);
		}
		sort(counter.begin() , counter.end() , greater<ll>());
		cin>>m;
		if(m < n - 1){
			for(int i = 1 ; i < n - m ; i++){
				p.push_back(1);
			}
		}
		for(int i = 0 ; i < m ; i++){
			cin>>h;
			p.push_back(h);
		}
		sort(p.begin() , p.end());
		for(int i = m - 1; i >= n - 1; i--){
			p[n - 2] *= p[i];
			p[n - 2] %= md;
			p.pop_back();
		}
		reverse(p.begin() , p.end());
		for(int i = 0; i < n - 1; i++){
			ans += p[i] * counter[i];
			ans %= md;
		}
		cout<<ans<<"\n";
		for(int i = 0 ; i < n ; i++){
			adj[i].clear();
		}
		counter.clear();
		p.clear();
	}
	return 0;
}