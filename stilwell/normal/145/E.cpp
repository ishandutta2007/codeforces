#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,ll,rr;
int sum4[4000005],sum7[4000005],sum47[4000005],sum74[4000005];
bool rev[4000005];
char s[1000005],opt[105];

void Max(int &x,int y){if(y>x)x=y;}

void update(int x)
{
	int l=x<<1,r=x<<1|1;
	sum4[x]=sum4[l]+sum4[r];
	sum7[x]=sum7[l]+sum7[r];
	sum47[x]=max(sum4[l]+sum47[r],sum47[l]+sum7[r]);
	sum74[x]=max(sum7[l]+sum74[r],sum74[l]+sum4[r]);
}

void build(int x,int l,int r)
{
	if(l==r)
	{
		if(s[l]=='4')sum4[x]=1;
		else sum7[x]=1;
		sum47[x]=sum74[x]=1;
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	update(x);
}

void Rev(int x)
{
	rev[x]^=1;
	swap(sum4[x],sum7[x]);
	swap(sum47[x],sum74[x]);
}

void C(int x,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		Rev(x);
		return;
	}
	int mid=l+r>>1;
	if(rev[x])
	{
		Rev(x<<1);Rev(x<<1|1);
		rev[x]=false;
	}
	if(rr<=mid)C(x<<1,l,mid);
	else if(ll>mid)C(x<<1|1,mid+1,r);
		else C(x<<1,l,mid),C(x<<1|1,mid+1,r);
	update(x);
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	build(1,1,n);
	
	for(;m;--m)
	{
		scanf("%s",opt+1);
		if(opt[1]=='s')
		{
			scanf("%d%d",&ll,&rr);
			C(1,1,n);
		}else printf("%d\n",sum47[1]);
	}
}