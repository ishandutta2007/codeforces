#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int T,ind,i,j,k;
long long n,tmp,ans[10];
int vis[20][105];
int f4[20],f7[20];
bool success;

void dfs(long long n,int x,int y)
{
	int i,j;
	if(success)return;
	if(n==0)
	{
		if(y==0)
		{
			for(i=1;i<=6;++i)ans[i]=0;
			tmp=1;
			for(i=0;i<x;++i)
			{
				k=0;
				for(j=f4[i];j;--j)ans[++k]+=tmp*4;
				for(j=f7[i];j;--j)ans[++k]+=tmp*7;
				tmp*=10;
			}
			printf("%I64d %I64d %I64d %I64d %I64d %I64d\n",ans[1],ans[2],ans[3],ans[4],ans[5],ans[6]);
			success=true;
		}
		return;
	}
	if(vis[x][y]==ind)return;
	vis[x][y]=ind;
	for(i=0;i<=6;++i)
	for(j=6-i;j>=0;--j)
	if((4*i+7*j+y)%10==n%10)
	{
		f4[x]=i;
		f7[x]=j;
		dfs(n/10,x+1,(4*i+7*j+y)/10);
	}
}

int main()
{
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%I64d",&n);
		++ind;success=false;
		dfs(n,0,0);
		if(!success)printf("-1\n");
	}
}