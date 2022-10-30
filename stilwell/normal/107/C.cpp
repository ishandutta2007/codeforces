#include <stdio.h>
#include <stdlib.h>
using namespace std;

int N,n,m,i,j,k,l,u,v,now;
int Maxlim[25],Minlim[25],Max[25],Min[25],num[25];
int ans[25],init[25],canuse[100005];
bool lim[25][25],check[25][25],use[25];
long long K,f[100005];

int main()
{
	scanf("%d%I64d%d",&n,&K,&m);K-=2001;
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		lim[u][v]=check[u][v]=true;
	}
	for(k=1;k<=n;++k)
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	check[i][j]|=check[i][k]&check[k][j];
	for(i=1;i<=n;++i)
	if(check[i][i])
	{
		printf("The times have changed\n");
		return 0;
	}
	N=1<<n;
	for(i=1;i<=n;++i)Maxlim[i]=0,Minlim[i]=n+1;
	for(i=0;i<N;++i)
	{
		for(j=1;j<=n;++j)init[j]=0;
		for(j=1;j<=n;++j)
		if(!(i&(1<<j-1)))
		for(k=1;k<=n;++k)
		if(lim[j][k])++init[k];
		for(j=1;j<=n;++j)
		if(!init[j]&&(!(i&(1<<j-1))))
		canuse[i]|=1<<j-1;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		if(!use[j]&&j>=Maxlim[i]&&j<=Minlim[i])
		{
			l=0;
			for(k=1;k<=n;++k)if(!use[k]&&k!=j)num[++l]=k;
			for(k=i+1;k<=n;++k)Max[k]=Maxlim[k],Min[k]=Minlim[k];
			for(k=i+1;k<=n;++k)
			{
				if(lim[k][i]&&j<Min[k])Min[k]=j;
				if(lim[i][k]&&j>Max[k])Max[k]=j;
			}
			u=1<<i;
			for(k=(1<<i)-1;k<N;k+=u)f[k]=0;
			f[(1<<i)-1]=1;
			for(k=(1<<i)-1;k<N;k+=u)
			if(f[k])
			{
				now=1;
				for(l=i+1;l<=n;++l)if(k&(1<<l-1))++now;
				now=num[now];
				for(l=i+1;l<=n;++l)
				if((canuse[k]&(1<<l-1))&&now>=Max[l]&&now<=Min[l])
				f[k|(1<<l-1)]+=f[k];
			}
			if(f[N-1]<=K)K-=f[N-1];
			else break;
		}
		if(j>n)
		{
			printf("The times have changed\n");
			return 0;
		}
		ans[i]=j;use[j]=true;
		for(j=i+1;j<=n;++j)
		{
			if(lim[j][i]&&ans[i]<Minlim[j])Minlim[j]=ans[i];
			if(lim[i][j]&&ans[i]>Maxlim[j])Maxlim[j]=ans[i];
		}
	}
	for(i=1;i<=n;++i)
	{
		printf("%d",ans[i]);
		if(i==n)printf("\n");
		else printf(" ");
	}
}