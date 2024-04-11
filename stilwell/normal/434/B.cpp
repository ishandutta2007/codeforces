#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,q,i,j,k,opt,x,y,ll,rr,ans;
int a[1005][1005];
int u[1005][1005],d[1005][1005],l[1005][1005],r[1005][1005];

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(a[i][j])
	{
		if(a[i-1][j])u[i][j]=u[i-1][j]+1;else u[i][j]=1;
		if(a[i][j-1])l[i][j]=l[i][j-1]+1;else l[i][j]=1;
	}
	for(i=n;i>=1;--i)
	for(j=m;j>=1;--j)
	if(a[i][j])
	{
		if(a[i+1][j])d[i][j]=d[i+1][j]+1;else d[i][j]=1;
		if(a[i][j+1])r[i][j]=r[i][j+1]+1;else r[i][j]=1;
	}
	for(;q;--q)
	{
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)
		{
			if(a[x][y])
			{
				for(j=x-1;a[j][y];--j)d[j][y]-=d[x][y];
				for(j=x+1;a[j][y];++j)u[j][y]-=u[x][y];
				for(j=y-1;a[x][j];--j)r[x][j]-=r[x][y];
				for(j=y+1;a[x][j];++j)l[x][j]-=l[x][y];
				l[x][y]=r[x][y]=u[x][y]=d[x][y]=0;
			}
			else
			{
				if(a[x-1][y])u[x][y]=u[x-1][y]+1;else u[x][y]=1;
				if(a[x+1][y])d[x][y]=d[x+1][y]+1;else d[x][y]=1;
				if(a[x][y-1])l[x][y]=l[x][y-1]+1;else l[x][y]=1;
				if(a[x][y+1])r[x][y]=r[x][y+1]+1;else r[x][y]=1;
				for(j=x-1;a[j][y];--j)d[j][y]+=d[x][y];
				for(j=x+1;a[j][y];++j)u[j][y]+=u[x][y];
				for(j=y-1;a[x][j];--j)r[x][j]+=r[x][y];
				for(j=y+1;a[x][j];++j)l[x][j]+=l[x][y];
			}
			a[x][y]=1-a[x][y];
		}
		else
		{
			ans=0;
			ll=rr=x;
			for(j=l[x][y];j>=1;--j)
			{
				while(l[ll-1][y]>=j)--ll;
				while(l[rr+1][y]>=j)++rr;
				if((rr-ll+1)*j>ans)ans=(rr-ll+1)*j;
			}
			ll=rr=x;
			for(j=r[x][y];j>=1;--j)
			{
				while(r[ll-1][y]>=j)--ll;
				while(r[rr+1][y]>=j)++rr;
				if((rr-ll+1)*j>ans)ans=(rr-ll+1)*j;
			}
			ll=rr=y;
			for(j=u[x][y];j>=1;--j)
			{
				while(u[x][ll-1]>=j)--ll;
				while(u[x][rr+1]>=j)++rr;
				if((rr-ll+1)*j>ans)ans=(rr-ll+1)*j;
			}
			ll=rr=y;
			for(j=d[x][y];j>=1;--j)
			{
				while(d[x][ll-1]>=j)--ll;
				while(d[x][rr+1]>=j)++rr;
				if((rr-ll+1)*j>ans)ans=(rr-ll+1)*j;
			}
			printf("%d\n",ans);
		}
	}
}