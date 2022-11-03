/*
ID: Sfiction
OJ: ZOJ
PROB: 500A
*/
#include <cstdio>
#include <cstring>

const int MAXN=30100;

int dt[MAXN];
bool vis[MAXN];

int main(){
	memset(dt,0,sizeof(dt));
	memset(vis,0,sizeof(vis));

	int n,des;
	scanf("%d%d",&n,&des);
	for (int i=1;i<n;++i)
		scanf("%d",&dt[i]);
	vis[n]=true;
	for (int i=1;i<n;i+=dt[i])
		vis[i]=true;
	puts(vis[des] ? "YES" : "NO");
	return 0;
}