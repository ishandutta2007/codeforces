#include<bits/stdc++.h>
using namespace std;
const int maxn = 200100;
vector<int> G[maxn];
int d[maxn], c[maxn];
void DFS(int u, int fa, int u_c, int fa_c){
	c[u] = u_c;
	int cnt = 0;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(v == fa) continue;
		cnt++; 
		while(cnt == fa_c || cnt == u_c) cnt++;
		DFS(v, u, cnt, u_c);
	}
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		d[u]++;
		d[v]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, d[i] + 1);
	DFS(1, -1, 1, -1);
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++)
		printf("%d ", c[i]);
	printf("\n");
	return 0;
}