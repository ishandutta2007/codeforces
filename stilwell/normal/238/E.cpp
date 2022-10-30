#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,S,T,i,j,k,l,u,v,tmp;
int f[105][105],g[105][105],p[105][105],t[105][105],ans[105][105],len[105];
bool Continue;

int main()
{
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	f[i][j]=100000;
	for(i=1;i<=n;++i)f[i][i]=0;
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		f[u][v]=1;
	}
	for(k=1;k<=n;++k)
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	if(f[i][k]+f[k][j]<f[i][j])
	f[i][j]=f[i][k]+f[k][j];
	scanf("%d",&m);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	g[i][j]=p[i][j]=-1;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);len[i]=f[u][v];
		if(f[u][v]>n)continue;
		for(j=1;j<=n;++j)if(f[u][j]+f[j][v]==f[u][v])++t[i][f[u][j]];
		for(j=1;j<=n;++j)
		if(f[u][j]+f[j][v]==f[u][v])
		{
			if(t[i][f[u][j]]==1)g[j][i]=f[u][j];
			p[j][i]=f[u][j];
		}
	}
	for(i=1;i<=n;++i)
	for(j=0;j<=m;++j)
	ans[i][j]=100000;
	ans[T][0]=0;
	for(Continue=true;Continue;)
	{
		Continue=false;
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		if(p[i][j]!=-1&&ans[i][0]+1<ans[i][j])
		ans[i][j]=ans[i][0]+1,Continue=true;
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		if(p[i][j]!=-1&&p[i][j]!=len[j])
		{
			tmp=-1;
			for(k=1;k<=n;++k)
			if(p[i][j]+1==p[k][j]&&f[i][k]==1&&ans[k][j]>tmp)
			tmp=ans[k][j];
			if(tmp!=-1&&tmp<ans[i][j])ans[i][j]=tmp,Continue=true;
		}
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		if(g[i][j]!=-1&&g[i][j]!=len[j]&&ans[i][j]<ans[i][0])
		ans[i][0]=ans[i][j],Continue=true;
	}
	if(ans[S][0]<=m)printf("%d\n",ans[S][0]);
	else printf("-1\n");
}