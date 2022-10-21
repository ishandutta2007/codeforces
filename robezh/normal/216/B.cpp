#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, bool> P;

vector<int> G[105];
bool used[105];

P dfs(int p){
	int ans = 1;
	bool ansb = (G[p].size() == 2);
	used[p] = true;
	
	
	for(int i = 0; i < G[p].size(); i++){
		if(!used[G[p][i]]){
			int k = G[p][i];
			P p = dfs(k);
			ans += p.first;
			ansb &= p.second;
		}
	}
	return P(ans,ansb);
}

int main(){
	int n,m;
	scanf("%d%d", &n, &m);
	fill(used+1, used+1+n, false);
	int a,b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			P p = dfs(i);
			if((p.first % 2 == 1) && p.second) res++;
		}
	}
	cout << ((n - res) % 2 == 0 ? res : res+1);
}