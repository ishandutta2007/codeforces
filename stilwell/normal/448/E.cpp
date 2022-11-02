#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long X,K,a[10005];
int son[10005],next[20000005],ed[20000005],tot;
int n,i,j,k;

void dfs(int x,int y)
{
	if(y==K||x==1)
	{
		printf("%I64d",a[x]);
		++tot;
		if(tot==100000){printf("\n");exit(0);}
		printf(" ");
		return;
	}
	for(int i=son[x];i;i=next[i])
	dfs(ed[i],y+1);
}

int main()
{
	scanf("%I64d%I64d",&X,&K);
	if(K>=100005)K=100005;
	for(i=1;(long long)i*i<=X;++i)
	if(X%i==0)
	{
		a[++n]=i;
		if(X/i!=i)a[++n]=X/i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i)
	for(j=i;j>=1;--j)
	if(a[i]%a[j]==0)
	{
		++tot;
		next[tot]=son[i];
		son[i]=tot;
		ed[tot]=j;
	}
	tot=0;
	dfs(n,0);
}