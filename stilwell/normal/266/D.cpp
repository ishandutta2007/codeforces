#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,x,y,z,ans,Max,tmp;
int u[40005],v[40005],c[40005];
int f[205][205];

struct node
{
	int a,b;
}t[205];
inline bool cmp(const node &a,const node &b){return a.a>b.a;}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	f[i][j]=1000000000;
	for(i=1;i<=n;++i)f[i][i]=0;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
		f[u[i]][v[i]]=f[v[i]][u[i]]=c[i];
	}
	for(k=1;k<=n;++k)
	for(i=1;i<=n;++i)
	for(j=i+1;j<=n;++j)
	if(f[i][k]+f[k][j]<f[i][j])
	f[i][j]=f[j][i]=f[i][k]+f[k][j];
	ans=1000000000;
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=n;++j)t[j].a=f[j][u[i]],t[j].b=f[j][v[i]];
		sort(t+1,t+n+1,cmp);
		Max=0;
		for(j=1;j<=n;++j)
		{
			if(t[j].a+c[i]>Max&&Max+c[i]>t[j].a)
			{
				if(t[j].a+Max+c[i]<ans)
				ans=t[j].a+Max+c[i];
			}
			else
			{
				if(max(t[j].a,Max)*2<ans)
				ans=max(t[j].a,Max)*2;
			}
			if(t[j].b>Max)Max=t[j].b;
		}
	}
	printf("%d",ans/2);
	if(ans%2)printf(".5");
	printf("\n");
}