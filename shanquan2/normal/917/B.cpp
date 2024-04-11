#include<bits/stdc++.h>
using namespace std;

struct edge{
	int nxt,to;
	int c;
}e[10005];
int n,m,ft[105];
int f[105][105][26];
int dfs(int i,int j,int a){
	if(f[i][j][a])return f[i][j][a];
	int g=-1;
	for(int k=ft[i];k;k=e[k].nxt)if(e[k].c>=a){
		int u=e[k].to;
		if(dfs(j,u,e[k].c)==-1){g=1;break;}
	}
//	printf("%d %d %d %d\n",i,j,a,g);
	return f[i][j][a]=g;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;char s[10];
		scanf("%d%d%s",&x,&y,s);
		e[i]=(edge){ft[x],y,s[0]-'a'};ft[x]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int g=dfs(i,j,0);
			if(g==1)printf("A");else printf("B");
		}
		printf("\n");
	}
	return 0;
}