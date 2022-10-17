#include <cstdio>
#include <cstring>
#define Maxn 100
int win[Maxn+5][Maxn+5][30];
int ed[Maxn+5][Maxn+5];
int n,m;
char qu[3];
int u,v;
int dfs(int x,int y,int z){
	if(win[x][y][z]!=-1){
		return win[x][y][z];
	}
	win[x][y][z]=0;
	int now;
	for(int i=1;i<=n;i++){
		if(ed[x][i]>=z){
			now=dfs(y,i,ed[x][i]);
			if(now==0){
				win[x][y][z]=1;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		scanf("%s",qu);
		ed[u][v]=(*qu)-'a'+1;
	}
	memset(win,-1,sizeof win);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dfs(i,j,1)){
				putchar('A');
			}
			else{
				putchar('B');
			}
		}
		puts("");
	}
	return 0;
}