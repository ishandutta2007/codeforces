#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

set<int> adj[N+5];
set<int> radj[N+5];

int n,m,s;

vector<int> rute;
vector<int> rute2;
bool vis[N+5];

bool dfs(int x, int bef=-1, int stat = 0){
	if(stat == 0) rute.push_back(x);
	else rute2.push_back(x);
//	printf("VIS %d %d SZ = %d\n", x, stat, rute.size());
	if(rute.size() + rute2.size() > 2){
//		printf("CEK DARI %d - %d ada ga?\n",s, x);
		if(adj[s].find(x) != adj[s].end()) return true;
	}
	vis[x] = true;
	
	if(stat == 0){
		for(auto y: adj[x]){
			if(y == bef) continue;
			if(vis[y]) continue;
			for(int i=0;i<=1;i++){
				bool tmp = dfs(y, x, i);
				if(tmp) return true;
				if(i == 0)rute.pop_back();
				else rute2.pop_back();
			}
		}
		
	} else {
		for(auto y: radj[x]){
			if(y == bef) continue;
			if(vis[y]) continue;
			bool tmp = dfs(y, x, stat);
			if(tmp) return true;
			rute2.pop_back();
		}
	}
	
	return false;
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].insert(v);
		radj[v].insert(u);
	}
	bool ans = dfs(s);
	if(ans){
		printf("Possible\n");
		if(rute2.size() != 0) rute.push_back(rute2[0]);
		printf("%d\n", rute.size());
		for(auto x: rute){
			printf("%d ", x);
		}
		printf("\n");
		if(rute2.size() == 0) rute2.push_back(rute.back());
		rute2.push_back(s);
		reverse(rute2.begin(), rute2.end());
		printf("%d\n", rute2.size());
		for(auto x: rute2){
			printf("%d ", x);
		}
		printf("\n");
	} else {
		printf("Impossible\n");
	}
	return 0;
}