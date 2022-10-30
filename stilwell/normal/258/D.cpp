#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v;
int a[1005];
double p[1005][1005],tmp,ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	if(a[i]>a[j])p[i][j]=1;
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		for(i=1;i<=n;++i)
		if(i!=u&&i!=v)
		{
			tmp=(p[u][i]+p[v][i])/2;
			p[u][i]=p[v][i]=tmp;
			tmp=(p[i][u]+p[i][v])/2;
			p[i][u]=p[i][v]=tmp;
		}
		p[u][v]=p[v][u]=0.5;
	}
	for(i=1;i<=n;++i)
	for(j=i+1;j<=n;++j)
	ans+=p[i][j];
	printf("%.20lf\n",ans);
}