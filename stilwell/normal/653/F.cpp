#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define sa_size 2000005
#define sa_maxlen 255
int lg[sa_size];
void get_lg(int n){int i;for(i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);}
struct suffix_array
{
	char str[sa_size];
	int sa[sa_size],rank[sa_size],trank[sa_size],tsa[sa_size],sum[sa_size],height[sa_size];
	int l;
	void build()
	{
		int i,j,k,p=sa_maxlen;
		for(i=1;i<=p;++i)sum[i]=0;
		for(i=1;i<=l;++i)trank[i]=str[i];
		for(i=1;i<=l;++i)++sum[trank[i]];
		for(i=1;i<=p;++i)sum[i]+=sum[i-1];
		for(i=l;i>=1;--i)sa[sum[trank[i]]--]=i;
		rank[sa[1]]=1;p=1;
		for(i=2;i<=l;++i)
		{
			if(trank[sa[i]]!=trank[sa[i-1]])++p;
			rank[sa[i]]=p;
		}
		for(k=1;k<=l;k*=2)
		{
			for(i=1;i<=p;++i)sum[i]=0;
			for(i=1;i<=l;++i)++sum[rank[i+k]];
			for(i=1;i<=p;++i)sum[i]+=sum[i-1];
			for(i=l;i>=1;--i)tsa[sum[rank[i+k]]--]=i;
			for(i=1;i<=p;++i)sum[i]=0;
			for(i=1;i<=l;++i)++sum[rank[i]];
			for(i=1;i<=p;++i)sum[i]+=sum[i-1];
			for(i=l;i>=1;--i)sa[sum[rank[tsa[i]]]--]=tsa[i];
			trank[sa[1]]=1;p=1;
			for(i=2;i<=l;++i)
			{
				if(rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+k]!=rank[sa[i-1]+k])++p;
				trank[sa[i]]=p;
			}
			for(i=1;i<=l;++i)rank[i]=trank[i];
			if(p==l)break;
		}
		for(i=1,k=0;i<=l;++i)
		{
			if(rank[i]==1)continue;
			for(;str[i+k]==str[sa[rank[i]-1]+k];)++k;
			height[rank[i]]=k;
			if(k>0)--k;
		}
	}
}a;

int n,i,j,k,aim,ll,rr;
int A[1000005],son[1000005],next[1000005];
char s[2000020];
long long ans;

struct node
{
	int l,r,sum;
}t[10000005];
int root[1000005];
int tot;

void C(int &x,int l,int r)
{
	if(!x)x=++tot;
	++t[x].sum;
	if(l==r)return;
	int mid=l+r>>1;
	if(aim<=mid)C(t[x].l,l,mid);
	else C(t[x].r,mid+1,r);
}

void Q(int x,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		ans+=t[x].sum;
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)Q(t[x].l,l,mid);
	else if(ll>mid)Q(t[x].r,mid+1,r);
		else Q(t[x].l,l,mid),Q(t[x].r,mid+1,r);
}

int main()
{
	scanf("%d",&n);a.l=n;
	scanf("%s",s+1);
	for(i=1;i<=n;++i)a.str[i]=s[i];
	a.build();
	for(i=1;i<=n;++i)
	{
		A[i]=A[i-1];
		if(s[i]=='(')++A[i];
		else --A[i];
		aim=i;C(root[n+A[i]],1,n);
	}
	for(i=n;i>=1;--i)
	{
		k=n+A[i];
		next[i]=son[k];son[k]=i;
	}
	for(i=1;i<=n;++i)
	{
		k=n+A[i-1]-1;
		for(;son[k];son[k]=next[son[k]])if(son[k]>=i)break;
		ll=i+a.height[a.rank[i]];
		if(son[k])rr=son[k];else rr=n;
		k=n+A[i-1];
		if(ll<=rr)Q(root[k],1,n);
	}
	printf("%I64d\n",ans);
}