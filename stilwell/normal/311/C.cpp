#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,p,i,j,k,l,opt,u,v;
int c[100005],Max[400005];
long long h,K,dist[10005],a[100005];
int q[100005],ll,rr;
bool use[100005],inq[100005];

void update(int x)
{
	if(Max[x<<1]==-1)Max[x]=Max[x<<1|1];
	else if(Max[x<<1|1]==-1)Max[x]=Max[x<<1];
		else
		{
			if(c[Max[x<<1]]>=c[Max[x<<1|1]])Max[x]=Max[x<<1];
			else Max[x]=Max[x<<1|1];
		}
}

int main()
{
	scanf("%I64d%d%d%d",&h,&n,&m,&p);
	for(l=1;l<n;l*=2);
	for(i=l+l-1;i;--i)Max[i]=-1;
	for(i=1;i<p;++i)dist[i]=h+1;
	for(i=1;i<=n;++i)
	{
		scanf("%I64d%d",&a[i],&c[i]);--a[i];
		if(a[i]%p==0)
		{
			use[i]=true;
			Max[j=l+i-1]=i;
			for(j>>=1;j;j>>=1)update(j);
		}
	}
	for(;m;--m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%I64d",&K);
			ll=rr=0;
			for(i=0;i<p;++i)q[++rr]=i,inq[i]=true;
			while(ll!=rr)
			{
				++ll;if(ll==100000)ll=1;inq[q[ll]]=false;
				if(dist[q[ll]]+K<dist[(q[ll]+K)%p])
				{
					dist[(q[ll]+K)%p]=dist[q[ll]]+K;
					if(!inq[(q[ll]+K)%p])
					{
						++rr;if(rr==100000)rr=1;
						q[rr]=(q[ll]+K)%p;inq[(q[ll]+K)%p]=true;
					}
				}
			}
			for(i=1;i<=n;++i)
			if(!use[i]&&dist[a[i]%p]<=a[i])
			{
				use[i]=true;
				Max[j=l+i-1]=i;
				for(j>>=1;j;j>>=1)update(j);
			}
		}
		if(opt==2)
		{
			scanf("%d%d",&u,&v);c[u]-=v;
			for(j=l+u-1>>1;j;j>>=1)update(j);
		}
		if(opt==3)
		{
			if(Max[1]==-1)printf("0\n");
			else
			{
				printf("%d\n",c[Max[1]]);
				c[Max[1]]=0;
				for(j=l+Max[1]-1>>1;j;j>>=1)update(j);
			}
		}
	}
}