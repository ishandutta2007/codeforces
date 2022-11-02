#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int i,j,k,q[15],u,v;
long long x[15],y[15],z[15],xx[15],yy[15],zz[15],mindist,dist;

inline long long sqr(long long x){return x*x;}

void dfs(int t)
{
	if(t>8)
	{
		mindist=sqr(x[1]-x[2])+sqr(y[1]-y[2])+sqr(z[1]-z[2]);
		for(i=3;i<=8;++i)
		{
			dist=sqr(x[1]-x[i])+sqr(y[1]-y[i])+sqr(z[1]-z[i]);
			if(dist<mindist)mindist=dist;
		}
		if(mindist==0)return;
		for(i=1;i<=8;++i)
		{
			k=0;
			for(j=1;j<=8;++j)
			if(i!=j)
			{
				dist=sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]);
				if(dist<mindist)return;
				if(dist==mindist)q[++k]=j;
			}
			if(k!=3)return;
			for(j=1;j<=3;++j)
			for(k=j+1;k<=3;++k)
			{
				u=q[j];v=q[k];
				if((x[i]-x[u])*(x[i]-x[v])+(y[i]-y[u])*(y[i]-y[v])+(z[i]-z[u])*(z[i]-z[v])!=0)
				return;
			}
		}
		printf("YES\n");
		for(i=1;i<=8;++i)printf("%I64d %I64d %I64d\n",x[i],y[i],z[i]);
		exit(0);
	}
	x[t]=xx[t];y[t]=yy[t];z[t]=zz[t];dfs(t+1);
	x[t]=xx[t];y[t]=zz[t];z[t]=yy[t];dfs(t+1);
	x[t]=yy[t];y[t]=xx[t];z[t]=zz[t];dfs(t+1);
	x[t]=yy[t];y[t]=zz[t];z[t]=xx[t];dfs(t+1);
	x[t]=zz[t];y[t]=xx[t];z[t]=yy[t];dfs(t+1);
	x[t]=zz[t];y[t]=yy[t];z[t]=xx[t];dfs(t+1);
}

int main()
{
	for(i=1;i<=8;++i)scanf("%I64d%I64d%I64d",&xx[i],&yy[i],&zz[i]);
	x[1]=xx[1];y[1]=yy[1];z[1]=zz[1];
	dfs(2);
	printf("NO\n");
}