#include<stdio.h>
#include<cstring>
#define MAXN 4200000
using namespace std;
int n;
int data[MAXN];
int head[MAXN];int tot=0;
int res[MAXN];bool go[MAXN];
void dfs(int x)
{
	if(go[x])return;go[x]=1;
	for(int i=0;i<=21;i++)
	if(((1<<i)&x)==0)
	{
		dfs(x+(1<<i));
		if(res[x]==-1&&res[x+(1<<i)]!=-1)res[x]=res[x+(1<<i)];
	}
}
int main()
{
	scanf("%d",&n);memset(res,-1,sizeof res);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
		int ans=0;
		for(int j=0;j<=21;j++)
		if((data[i]&(1<<j))==0)ans+=(1<<j);
		res[ans]=data[i];
	}
	dfs(0);
	for(int i=1;i<=n;i++)printf("%d ",res[data[i]]);
	return 0;
}