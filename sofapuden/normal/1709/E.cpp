#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<set<int>> mer;
vector<vector<int>> gr;
vector<int> notxor;
vector<int> v;
int ans = 0;

void dfs(int x, int p){
	bool ok = 1;
	for(auto y : gr[x]){
		if(y == p)continue;
		dfs(y,x);
		notxor[y]^=v[x];
		if(mer[y].size() > mer[x].size()){
			swap(mer[y],mer[x]);
			swap(notxor[y],notxor[x]);
		}
		for(auto z : mer[y]){
			if(mer[x].count(z^notxor[y]^notxor[x]^v[x]))ok = 0;
		}
		for(auto z : mer[y]){
			mer[x].insert(z^notxor[y]^notxor[x]);
		}
	}
	if(!ok){
		ans++;
		mer[x].clear();
		notxor[x] = 0;
	}
}

void solve(){
	int n; cin >> n;
	v.resize(n);
	mer.resize(n);
	notxor.resize(n,0);
	for(auto &x : v)cin >> x;
	for(int i = 0; i < n; ++i)mer[i].insert(v[i]);
	gr.resize(n);
	for(int i = 0; i < n-1; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(0,0);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}