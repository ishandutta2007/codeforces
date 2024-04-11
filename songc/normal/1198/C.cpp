#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, M, Q;
bool vis[303030];
vector<pii> adj[303030];
vector<int> Mat, Ind;

bool dfs(int u){
	vis[u] = true;
	bool tf = true, leaf = true;
	for (pii v : adj[u]){
		if (vis[v.first]) continue;
		leaf = false;
		if (dfs(v.first) && tf){
			Mat.push_back(v.second);
			tf = false;
		}
	}
	if (leaf) Ind.push_back(u);
	return tf;
}

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &M);
		Mat.clear();
		Ind.clear();
		for (int i=1; i<=3*N; i++) vis[i] = false, adj[i].clear();
		for (int i=1; i<=M; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(pii(v, i));
			adj[v].push_back(pii(u, i));
		}
		for (int i=1; i<=3*N; i++) if (!vis[i]) dfs(i);
		if (Mat.size() >= N){
			puts("Matching");
			for (int i=0; i<N; i++) printf("%d ", Mat[i]);
			printf("\n");
		}
		else{
			puts("IndSet");
			for (int i=0; i<N; i++) printf("%d ", Ind[i]);
			printf("\n");
		}
	}
	return 0;
}