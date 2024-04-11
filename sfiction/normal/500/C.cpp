/*
ID: Sfiction
OJ: ZOJ
PROB: 500C
*/
#include <cstdio>
#include <cstring>

const int MAXN=550,MAXM=1100;

int n,m;
int w[MAXN];
int b[MAXM];
bool vis[MAXN];

int cnt,list[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&w[i]);
	memset(vis,0,sizeof(vis));
	cnt=0;
	for (int i=0;i<m;++i){
		scanf("%d",&b[i]);
		if (!vis[b[i]]){
			vis[b[i]]=true;
			list[cnt++]=b[i];
		}
	}
	int ans=0;
	for (int i=0;i<m;++i){
		int j;
		for (j=0;list[j]!=b[i];++j)
			ans+=w[list[j]];
		for (;j>0;--j)
			list[j]=list[j-1];
		list[0]=b[i];
	}
	printf("%d",ans);
	return 0;
}