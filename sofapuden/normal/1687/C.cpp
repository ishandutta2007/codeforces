#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
int u(int x, vector<int> &U){
	return U[x] = x^U[x] ? u(U[x],U) : x;
}
*/

void solve(){
	int n, m; cin >> n >> m;
	vector<ll> A(n), B(n);
	for(auto &x : A)cin >> x;
	for(auto &x : B)cin >> x;

	set<int> go;
	ll cu = 0;
	for(int i = 0; i < n; ++i){
		if(!cu){
			go.insert(i+1);
		}
		cu+=A[i];
		cu-=B[i];
	}
	go.insert(n+1);
	//vector<int> nxt(n+5);
	vector<int> am(m,0);
	//iota(nxt.begin(),nxt.end(),0);

	vector<vector<int>> G(n+2);
	vector<pair<int,int>> ran;
	for(int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		G[a].push_back(i);
		G[b+1].push_back(i);
		ran.emplace_back(a,b);
	}
	if(cu){
		cout << "NO\n";
		return;
	}
	set<int> lef;
	for(int i = 1; i <= n+1; ++i)lef.insert(i);
	queue<int> todo;
	for(auto x : go){
		lef.erase(x);
		for(auto y : G[x]){
			am[y]++;
			if(am[y] == 2)todo.push(y);
		}
	}
	while(todo.size()){
		auto q = todo.front();
		todo.pop();
		auto x = ran[q];
		while(lef.lower_bound(x.first) != lef.end() && *lef.lower_bound(x.first) <= x.second){
			int z = *lef.lower_bound(x.first);
			for(auto y : G[z]){
				am[y]++;
				if(am[y] == 2)todo.push(y);
			}
			lef.erase(z);
		}
	}
	if(!lef.size()){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}