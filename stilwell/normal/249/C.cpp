#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v,c,sum;
int lim[100005],now[100005];
double C[600005][15],f[100005][105],tmp[105],ans,Tmp;

double calc(int a,int b)
{
	if(b>a)return 0;
	double ans=1;
	for(int i=1;i<=b;++i)
	ans*=a,ans/=i,--a;
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&lim[i]);
		now[i]=lim[i];
		f[i][lim[i]]=1;
		ans+=f[i][0];
	}
	for(i=0;i<=600000;++i)
	for(j=0;j<=10;++j)
	C[i][j]=calc(i,j);
	scanf("%d",&m);
	for(;m;--m)
	{
		scanf("%d%d%d",&u,&v,&c);
		k=lim[u];
		for(i=0;i<=k;++i)tmp[i]=0;
		for(i=0;i<=k;++i)
		for(j=0;j<=i&&j<=c;++j)
		tmp[i-j]+=f[u][i]*C[i][j]*C[now[u]-i][c-j]/C[now[u]][c];
		ans+=tmp[0]-f[u][0];
		for(i=0;i<=k;++i)f[u][i]=tmp[i];
		now[u]-=c;now[v]+=c;
		printf("%.20lf\n",ans);
	}
}