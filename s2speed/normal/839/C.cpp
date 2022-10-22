#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5;

vector<ll> adj[MAX_N];
double E[MAX_N];
bool mark[MAX_N];
stack<ll> st;

void DFS(){
	ll v = st.top() , vs = adj[v].size();
	if(vs == 1 && v != 0){
		st.pop();
		return;
	}
	for(int i = 0 ; i < vs ; i++){
		ll u = adj[v][i];
		if(mark[u] == false){
			mark[u] = true;
			st.push(u);
			DFS();
			double h , q = vs;
			if(v == 0){
				h = 1 / q;
			} else {
				h = 1 / (q - 1);
			}
			E[v] += E[u] * h;
		}
	}
	E[v]++;
	st.pop();
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin>>n;
	if(n == 1){
		cout<<"0\n";
		return 0;
	}
	for(int i = 1 ; i < n ; i++){
		mark[i] = false;
		ll u , v;
		cin>>u>>v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	for(int i = 0 ; i < n ; i++){
		E[i] = 0;
	}
	mark[0] = true;
	st.push(0);
	DFS();
	printf("%.15lf" , E[0]);
	return 0;
}