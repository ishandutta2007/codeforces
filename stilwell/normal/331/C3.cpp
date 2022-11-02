#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int i,j,k,u,v,tot,aim;
long long n,ans,f[25][10][10];
int num[25],g[25][10][10];

int main()
{
	for(j=0;j<=9;++j)
	for(k=0;k<=9;++k)
	if(j>k)
	{
		f[1][j][k]=1;
		g[1][j][k]=10+k-j;
	}
	else
	{
		if(j==0)
		{
			f[1][j][k]=1;
			g[1][j][k]=0;
		}
		else
		{
			f[1][j][k]=2;
			g[1][j][k]=10-j;
		}
	}
	for(i=2;i<=20;++i)
	for(j=0;j<=9;++j)
	for(k=0;k<=9;++k)
	{
		u=9;v=k;
		while(u>=0)
		{
			f[i][j][k]+=f[i-1][max(j,u)][v];
			v=g[i-1][max(j,u)][v];
			--u;
		}
		g[i][j][k]=v;
	}
	scanf("%I64d",&n);
	if(n<=9){printf("%d\n",n>0);return 0;}
	for(;n;n/=10)num[++tot]=n%10;
	v=num[1];
	for(i=2;i<=tot;++i)
	{
		while(num[i]>=0)
		{
			u=0;
			for(j=i;j<=tot;++j)if(num[j]>u)u=num[j];
			ans+=f[i-1][u][v];
			v=g[i-1][u][v];
			if(u==0&&num[i]==0)break;
			--num[i];
		}
		if(u>0)
		for(j=i+1;j<=tot;++j)
		{
			--num[j];
			if(num[j]<0)num[j]+=10;
			else break;
		}else break;
		for(j=i+1;j<=tot;++j)if(num[j]!=0)break;
		if(j>tot)
		{
			if(i!=tot)ans+=f[i][0][v];
			break;
		}
	}
	printf("%I64d\n",ans);
}