#include <bits/stdc++.h>
using namespace std;
const int maxn = 602;
const int N = 603;
int G[maxn][maxn];
int linker[maxn];
int n, m, cnt, k;
bool used[maxn];
bool dfs(int a){
	for (int i = 0;i < n;i++){
		if (G[a][i] && !used[i]){
			used[i] = 1;
			if (linker[i] == -1 || dfs(linker[i])){
				linker[i] = a;
				return true;
			}
		}
	}
	return false;
}
int hungery(){
	int result = 0;
	memset(linker,-1,sizeof(linker));
	for (int i = 0;i < cnt;i++){
		memset(used,0,sizeof(used));
		if (dfs(i)) result++;
	}
	//printf("res %d\n", result);
	return result;
}
int dis[N][N],s[N];
bool chk(int x){
	memset(G,0,sizeof(G));
	for(int i=0;i<cnt;i++){
		for(int j=0;j<n;j++){
			if(dis[s[i]][j] <= x) {
				//printf("link %d %d\n", i, j);
				G[i][j]=1;
			}
		}
	}
	return hungery()>=k;
}
int main() {
	for (int i = 0; i < N; i ++) for (int j = 0; j < N; j ++) dis[i][j] = i==j?0:1e8;
	scanf("%d%d%d%d",&n,&m,&cnt,&k);
	for(int i=0;i<cnt;i++){
		scanf("%d", &s[i]);--s[i];
	}
	for (int i = 1; i <= m; i ++) {	
		int u,v,w; scanf("%d%d%d",&u,&v,&w);--u;--v;
		dis[u][v]=min(dis[u][v], w);
		dis[v][u]=dis[u][v];
	}
	for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	int lef=-1, rig=11731312;
	
	if (chk(rig) == false) {
		return !printf("-1\n");
	}
	
	//chk(3); return 0;

	while(rig-lef>1){
		int mid=(lef+rig)>>1;
		if(chk(mid)) rig=mid; else lef=mid; 
	}
	printf("%d\n", rig);


}