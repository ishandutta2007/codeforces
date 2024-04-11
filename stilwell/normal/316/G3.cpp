#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define sa_size 1300005
#define sa_maxlen 10000
int lg[sa_size];
void get_lg(int n){int i;for(i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);}
struct suffix_array
{
	char str[sa_size];
	int sa[sa_size],rank[sa_size],trank[sa_size],tsa[sa_size],sum[sa_size],height[sa_size],LCP[22][600005];
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

int L,n,lim,last,i,j,k,ans,len[15],l[15],r[15],liml[15],limr[15];
int sum[600005][11],tmp[11];

bool check1(int x,int y)
{
	int l,r,mid,aim;
	for(l=1;l<=n;++l)tmp[l]=0;
	l=1;r=x;aim=x;
	while(l<=r)
	{
		mid=l+r>>1;
		if(a.lcp(mid,x)>=y)aim=mid,r=mid-1;
		else l=mid+1;
	}
	for(l=1;l<=n;++l)tmp[l]+=sum[x][l]-sum[aim-1][l];
	l=x+1;r=L;aim=x;
	while(l<=r)
	{
		mid=l+r>>1;
		if(a.lcp(mid,x)>=y)aim=mid,l=mid+1;
		else r=mid-1;
	}
	for(l=1;l<=n;++l)tmp[l]+=sum[aim][l]-sum[x][l];
	for(l=1;l<=n;++l)if(tmp[l]>limr[l])return false;
	return true;
}

bool check2(int x,int y)
{
	int l,r,mid,aim;
	for(l=1;l<=n;++l)tmp[l]=0;
	l=1;r=x;aim=x;
	while(l<=r)
	{
		mid=l+r>>1;
		if(a.lcp(mid,x)>=y)aim=mid,r=mid-1;
		else l=mid+1;
	}
	for(l=1;l<=n;++l)tmp[l]+=sum[x][l]-sum[aim-1][l];
	l=x+1;r=L;aim=x;
	while(l<=r)
	{
		mid=l+r>>1;
		if(a.lcp(mid,x)>=y)aim=mid,l=mid+1;
		else r=mid-1;
	}
	for(l=1;l<=n;++l)tmp[l]+=sum[aim][l]-sum[x][l];
	for(l=1;l<=n;++l)if(tmp[l]<liml[l])return false;
	return true;
}

void work(int x)
{
	int l=1,r=len[0]-a.sa[x]+1,mid,aim1=r+1,aim2;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check1(x,mid))aim1=mid,r=mid-1;
		else l=mid+1;
	}
	l=aim1;r=len[0]-a.sa[x]+1;aim2=aim1-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check2(x,mid))aim2=mid,l=mid+1;
		else r=mid-1;
	}
	if(lim+1>aim1)aim1=lim+1;
	if(aim1>aim2)return;
	ans+=aim2-aim1+1;
}

int main()
{
	scanf("%s",a.str+1);
	len[0]=strlen(a.str+1);
	L=len[0]+1;a.str[L++]=1;
	l[0]=1;r[0]=len[0];
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",a.str+L);
		len[i]=strlen(a.str+L);
		l[i]=L;r[i]=L+len[i]-1;
		L+=len[i];
		a.str[L++]=i+1;
		scanf("%d%d",&liml[i],&limr[i]);
	}
	a.l=L;get_lg(L);
	a.build();
	for(i=1;i<=L;++i)
	for(j=0;j<=n;++j)
	sum[i][j]=sum[i-1][j]+(a.sa[i]>=l[j]&&a.sa[i]<=r[j]);
	last=0;
	for(i=1;i<=L;++i)
	if(a.sa[i]<=len[0])
	{
		if(last)lim=a.lcp(last,i);
		work(i);
		last=i;
	}
	printf("%d\n",ans);
}