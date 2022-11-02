#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,p,i,j,k,u,v;
int c[505],fa[100005],type[100005],stand[505];
int f[505][505];

struct node
{
	int u,v,c;
}t[100005];
int get(int x)
{
	if(fa[x]==x)return x;
	fa[x]=get(fa[x]);
	return fa[x];
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=p;++i)scanf("%d",&c[i]);
	for(i=1;i<=m;++i)scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].c);
	for(i=1;i<=p;++i)
	for(k=1;k<=c[i];++k)
	type[++j]=i;
	for(i=1;i<=n;++i)
	if(type[i]!=type[i-1])
	stand[type[i]]=i;
	for(i=1;i<=n;++i)fa[i]=i;
	for(i=1;i<=m;++i)
	if(t[i].c==0)
	{
		u=get(t[i].u);v=get(t[i].v);
		if(u!=v)fa[u]=v;
	}
	for(i=1;i<=n;++i)
	if(get(i)!=get(stand[type[i]]))
	{
		printf("No\n");
		return 0;
	}
	for(i=1;i<=p;++i)
	for(j=1;j<=p;++j)
	if(i!=j)f[i][j]=1000000005;
	for(i=1;i<=m;++i)
	if(t[i].c<f[type[t[i].u]][type[t[i].v]])
	f[type[t[i].u]][type[t[i].v]]=f[type[t[i].v]][type[t[i].u]]=t[i].c;
	for(k=1;k<=p;++k)
	for(i=1;i<=p;++i)
	for(j=1;j<=p;++j)
	if(f[i][k]+f[k][j]<f[i][j])
	f[i][j]=f[i][k]+f[k][j];
	for(i=1;i<=p;++i)
	for(j=1;j<=p;++j)
	if(f[i][j]==1000000005)
	f[i][j]=-1;
	printf("Yes\n");
	for(i=1;i<=p;++i)
	{
		printf("%d",f[i][1]);
		for(j=2;j<=p;++j)printf(" %d",f[i][j]);
		printf("\n");
	}
}