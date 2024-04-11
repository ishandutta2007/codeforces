#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,i,j,k,L,ll,rr,ans;
int a[100005],l[100005],r[100005];
int sum[100005],sum0[400005],sum1[400005];
bool rev[400005];
long long Ans;

vector<int> Ins[100005],Del[100005];

int find(int x)
{
	int l=1,r=n,mid,ans=0;
	while(l<=r)
	{
		mid=l+r>>1;
		if(a[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}

void Rev(int p)
{
	swap(sum0[p],sum1[p]);
	rev[p]^=1;
}

void C(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		Rev(p);
		return;
	}
	int mid=l+r>>1;
	if(rev[p])Rev(p<<1),Rev(p<<1|1),rev[p]=false;
	if(rr<=mid)C(p<<1,l,mid);
	else if(ll>mid)C(p<<1|1,mid+1,r);
		else C(p<<1,l,mid),C(p<<1|1,mid+1,r);
	sum0[p]=sum0[p<<1]+sum0[p<<1|1];
	sum1[p]=sum1[p<<1]+sum1[p<<1|1];
}

void Q(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		ans+=sum0[p];
		return;
	}
	int mid=l+r>>1;
	if(rev[p])Rev(p<<1),Rev(p<<1|1),rev[p]=false;
	if(rr<=mid)Q(p<<1,l,mid);
	else if(ll>mid)Q(p<<1|1,mid+1,r);
		else Q(p<<1,l,mid),Q(p<<1|1,mid+1,r);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&l[i],&r[i]);
		l[i]=find(l[i]-1)+1;
		r[i]=find(r[i]);
		if(l[i]<=r[i])Ins[l[i]].push_back(i),Del[r[i]].push_back(i);
	}
	for(L=1;L<n;L*=2);
	for(i=1;i<=n;++i)sum0[L+i-1]=1;
	for(i=L-1;i;--i)sum0[i]=sum0[i<<1]+sum0[i<<1|1];
	for(i=1;i<=n;++i)
	{
		for(j=Ins[i].size()-1;j>=0;--j)
		{
			ll=l[Ins[i][j]];rr=r[Ins[i][j]];
			C(1,1,L);
		}
		ans=0;ll=1;rr=i-1;
		if(ll<=rr)Q(1,1,L);
		sum[i]+=rr-ll+1-ans;
		ans=0;ll=i+1;rr=n;
		if(ll<=rr)Q(1,1,L);
		sum[i]+=ans;
		for(j=Del[i].size()-1;j>=0;--j)
		{
			ll=l[Del[i][j]];rr=r[Del[i][j]];
			C(1,1,L);
		}
	}
	Ans=1ll*n*(n-1)*(n-2)/6;
	for(i=1;i<=n;++i)Ans-=1ll*sum[i]*(sum[i]-1)/2;
	printf("%I64d\n",Ans);
}