#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5;

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

vector<ll> adj[MAX_N];
stack<ll> st;
ll ans = 0 , p[MAX_N] , a[MAX_N] , dad[MAX_N] , bad = 0 , n , m;
bool mark[MAX_N];

void DFS(){
	ll q = st.top() , qs = adj[q].size();
	if(q == 0 && p[q] == -1){
		p[q] = a[q];
	} else if(p[q] == -1) {
		if(a[q] == 1){
			p[q] = p[dad[q]] + 1;
		} else {
			p[q] = 0;
		}
	}
	if(p[q] > m){
		bad++;
	}
	if(qs == 1 && q != 0){
		if(bad == 0){
			ans++;
		}
		if(p[q] > m){
			bad--;
		}
		st.pop();
		return;
	}
	for(int i = 0 ; i < qs ; i++){
		ll u = adj[q][i];
		if(mark[u] == false){
			mark[u] = true;
			st.push(u);
			dad[u] = q;
			DFS();
		}
	}
	if(p[q] > m){
		bad--;
	}
	st.pop();
	return;
}

void solve(){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		p[i] = -1;
		mark[i] = false;
	}
	for(int i = 1 ; i < n ; i++){
		ll u , v;
		cin>>u>>v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	st.push(0);
	mark[0] = true;
	dad[0] = -1;
	DFS();
	cout<<ans<<"\n";
	for(int i = 0 ; i < n ; i++){
		adj[i].clear();
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}