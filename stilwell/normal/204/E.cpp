#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define sa_size 600001
#define sa_maxlen 200005
int lg[sa_size];
void get_lg(int n){int i;for(i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);}
struct suffix_array
{
	int str[sa_size];
	int sa[sa_size],rank[sa_size],trank[sa_size],tsa[sa_size],sum[sa_size],height[sa_size],LCP[30][sa_size];
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
		}
		for (i=1,k=0;i<=l;++i)
		{
			if(rank[i]==1)continue;
			for(;str[i+k]==str[sa[rank[i]-1]+k];)++k;
			height[rank[i]]=k;
			if(k>0)--k;
		}
		for(i=1;i<=l;++i)LCP[0][i]=height[i];
		for(k=1;k<=lg[l];++k)
        for(i=1;i+(1<<k)<=l+1;++i)
        LCP[k][i]=min(LCP[k-1][i],LCP[k-1][i+(1<<k-1)]);
	}
	inline int lcp(int x,int y)
	{
		if(x==y)return l-x;
		//x=rank[x];y=rank[y];
		if(x>y)swap(x,y);
		int k=lg[y-x];
		return min(LCP[k][x+1],LCP[k][y-(1<<k)+1]);
	}
}a;

int n,m,L,i,j,k,key,ll,rr,l,r,mid,aim,tot;
char s[200001];
int from[1000005],froml[1000005];
int Max[1500005];
int last[1000005],pre[1000005];
int sum[1500005];
long long ans[100005];
int tmp;

void C(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		if(key>Max[p])Max[p]=key;
		return;
	}
	int mid=(l+r)/2;
	if(rr<=mid)C(p*2,l,mid);
	else if(ll>mid)C(p*2+1,mid+1,r);
		else C(p*2,l,mid),C(p*2+1,mid+1,r);
}

void Q(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		key+=sum[p];
		return;
	}
	int mid=(l+r)/2;
	if(rr<=mid)Q(p*2,l,mid);
	else if(ll>mid)Q(p*2+1,mid+1,r);
		else Q(p*2,l,mid),Q(p*2+1,mid+1,r);
}

void A(int p,int l,int r)
{
	++sum[p];
	if(l==r)return;
	int mid=(l+r)/2;
	if(key<=mid)A(p*2,l,mid);
	else A(p*2+1,mid+1,r);
}

void D(int p,int l,int r)
{
	--sum[p];
	if(l==r)return;
	int mid=(l+r)/2;
	if(key<=mid)D(p*2,l,mid);
	else D(p*2+1,mid+1,r);
}

void GetAns(int p,int l,int r)
{
	if(l==r)
	{
		if(froml[a.sa[l]]<Max[p])Max[p]=froml[a.sa[l]];
		ans[from[a.sa[l]]]+=Max[p];
		return;
	}
	int mid=(l+r)/2;
	if(Max[p]>Max[p*2])Max[p*2]=Max[p];
	if(Max[p]>Max[p*2+1])Max[p*2+1]=Max[p];
	GetAns(p*2,l,mid);
	GetAns(p*2+1,mid+1,r);
}

int main()
{
	scanf("%d%d",&n,&m);
	l=1;a.str[1]=300;key=300;
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		k=strlen(s+1);
		for(j=1;j<=k;++j)
		{
			++l;
			a.str[l]=s[j];
			from[l]=i;
			froml[l]=k-j+1;
		}
		++l;++key;
		a.str[l]=key;
		if(m==1)printf("%I64d ",(long long)(1+k)*k/2);
	}
	if(m==1)return 0;
	L=l;
	a.l=l;
	get_lg(l);
	a.build();
	for(i=1;i<=L;++i)
	if(from[a.sa[i]]!=0)
	{
		pre[i]=last[from[a.sa[i]]];
		last[from[a.sa[i]]]=i;
	}
	tot=0;
	for(i=1;i<=L;++i)
	{
		if(a.sa[i]!=0)
		{
			if(pre[i])
			{
				key=pre[i];
				D(1,1,L);
			}
			else ++tot;
			key=i;
			A(1,1,L);
		}
		if(tot>=m)
		{
			l=1;r=i;aim=1;rr=i;
			while(l<=r)
			{
				mid=(l+r)/2;
				key=0;ll=mid;
				Q(1,1,L);
				if(key>=m)aim=mid,l=mid+1;
				else r=mid-1;
			}
			tmp=a.lcp(aim,i);
			l=1;r=aim;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(a.lcp(mid,i)>=tmp)aim=mid,r=mid-1;
				else l=mid+1;
			}
			ll=aim;rr=i;key=tmp;
			C(1,1,L);
		}
	}
	for(i=4*L;i>=1;--i)sum[i]=0;
	for(i=1;i<=L;++i)if(from[a.sa[i]]!=0)last[from[a.sa[i]]]=0;
	for(i=L;i>=1;--i)
	if(from[a.sa[i]]!=0)
	{
		pre[i]=last[from[a.sa[i]]];
		last[from[a.sa[i]]]=i;
	}
	tot=0;
	for(i=L;i>=1;--i)
	{
		if(a.sa[i]!=0)
		{
			if(pre[i])
			{
				key=pre[i];
				D(1,1,L);
			}
			else ++tot;
			key=i;
			A(1,1,L);
		}
		if(tot>=m)
		{
			l=i;r=L;aim=L;ll=i;
			while(l<=r)
			{
				mid=(l+r)/2;
				key=0;rr=mid;
				Q(1,1,L);
				if(key>=m)aim=mid,r=mid-1;
				else l=mid+1;
			}
			tmp=a.lcp(i,aim);
			l=aim;r=L;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(a.lcp(i,mid)>=tmp)aim=mid,l=mid+1;
				else r=mid-1;
			}
			ll=i;rr=aim;key=tmp;
			C(1,1,L);
		}
	}
	GetAns(1,1,L);
	printf("%I64d",ans[1]);
	for(i=2;i<=n;++i)printf(" %I64d",ans[i]);
}