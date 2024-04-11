#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v,l,r,mid,aim;
int a[100005],sum[100005];
int son[100005],next[2000005],x[2000005];
long long ans[2000005];
int st[100005],top;

double cal(int x,int y)
{
	double res=(sum[x]-sum[y]+(double)y*a[y]-(double)x*a[x])/(a[x]-a[y]);
	return res;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		next[i]=son[v];son[v]=i;x[i]=u;
	}
	for(i=1;i<=n;++i)
	{
		while(top&&a[i]<=a[st[top]])--top;
		while(top>1&&cal(st[top],i)>=cal(st[top-1],i))--top;
		st[++top]=i;
		for(j=son[i];j;j=next[j])
		{
			l=1;r=top;aim=top;
			while(l<=r)
			{
				mid=l+r>>1;
				if(st[mid]+x[j]>=i)aim=mid,r=mid-1;
				else l=mid+1;
			}
			l=aim;r=top-1;aim=top;
			while(l<=r)
			{
				mid=l+r>>1;
				if(cal(st[mid],st[mid+1])<=x[j]-i)aim=mid,r=mid-1;
				else l=mid+1;
			}
			ans[j]=sum[i]-sum[st[aim]]+(long long)(x[j]-i+st[aim])*a[st[aim]];
		}
	}
	for(i=1;i<=m;++i)printf("%I64d\n",ans[i]);
}