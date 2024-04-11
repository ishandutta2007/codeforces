#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,ll,rr,key,aim,opt;
long long sum[1000005],Max[1000005],ans;

void build(int p,int l,int r)
{
	if(l==r)
	{
		scanf("%I64d",&sum[p]);
		Max[p]=sum[p];
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	sum[p]=sum[p<<1]+sum[p<<1|1];
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
}

void C(int p,int l,int r)
{
	if(Max[p]<key)return;
	int mid=l+r>>1;
	if(l>=ll&&r<=rr)
	{
		if(l==r)
		{
			sum[p]%=key;
			Max[p]=sum[p];
			return;
		}
		C(p<<1,l,mid);
		C(p<<1|1,mid+1,r);
		sum[p]=sum[p<<1]+sum[p<<1|1];
		Max[p]=max(Max[p<<1],Max[p<<1|1]);
		return;
	}
	if(rr<=mid)C(p<<1,l,mid);
	else if(ll>mid)C(p<<1|1,mid+1,r);
		else C(p<<1,l,mid),C(p<<1|1,mid+1,r);
	sum[p]=sum[p<<1]+sum[p<<1|1];
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
}

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

void A(int p,int l,int r)
{
	if(l==r)
	{
		sum[p]=Max[p]=key;
		return;
	}
	int mid=l+r>>1;
	if(aim<=mid)A(p<<1,l,mid);
	else A(p<<1|1,mid+1,r);
	sum[p]=sum[p<<1]+sum[p<<1|1];
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
}

int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(;m;--m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			ans=0;
			scanf("%d%d",&ll,&rr);
			Q(1,1,n);
			printf("%I64d\n",ans);
		}
		if(opt==2)
		{
			scanf("%d%d%d",&ll,&rr,&key);
			C(1,1,n);
		}
		if(opt==3)
		{
			scanf("%d%d",&aim,&key);
			A(1,1,n);
		}
	}
}