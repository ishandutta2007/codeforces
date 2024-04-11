#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,l,ll,rr,L,R,opt,u,v,ans;
int sum[400005];
bool Rev;

void Q(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		ans+=sum[p];
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)Q(p<<1,l,mid);
	else if(ll>mid)Q(p<<1|1,mid+1,r);
		else Q(p<<1,l,mid),Q(p<<1|1,mid+1,r);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(l=1;l<n;l<<=1);
	for(i=1;i<=n;++i)
	for(j=l+i-1;j;j>>=1)++sum[j];
	L=1;R=n;
	for(;m;--m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&u);
			if(u<=(R-L+1)/2)
			{
				if(Rev)
				{
					u=R-u+1;
					for(i=u;i<=R;++i)
					{
						k=sum[l+i-1];
						for(j=l+i-1;j;j>>=1)sum[j]-=k;
						for(j=l+u-(i-u+1)-1;j;j>>=1)sum[j]+=k;
					}
					R=u-1;
				}
				else
				{
					u=L+u-1;
					for(i=L;i<=u;++i)
					{
						k=sum[l+i-1];
						for(j=l+i-1;j;j>>=1)sum[j]-=k;
						for(j=l+u+(u-i+1)-1;j;j>>=1)sum[j]+=k;
					}
					L=u+1;
				}
			}
			else
			{
				if(Rev)
				{
					u=R-u;
					for(i=L;i<=u;++i)
					{
						k=sum[l+i-1];
						for(j=l+i-1;j;j>>=1)sum[j]-=k;
						for(j=l+u+(u-i+1)-1;j;j>>=1)sum[j]+=k;
					}
					L=u+1;
					
				}
				else
				{
					u=L+u;
					for(i=u;i<=R;++i)
					{
						k=sum[l+i-1];
						for(j=l+i-1;j;j>>=1)sum[j]-=k;
						for(j=l+u-(i-u+1)-1;j;j>>=1)sum[j]+=k;
					}
					R=u-1;
				}
				Rev^=1;
			}
		}
		else
		{
			scanf("%d%d",&ll,&rr);
			if(Rev)ll=R-ll,rr=R-rr+1,swap(ll,rr);
			else ll=L+ll,rr=L+rr-1;
			ans=0;
			Q(1,1,l);
			printf("%d\n",ans);
		}
	}
}