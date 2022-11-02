#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,l,r;
int num[26];
char s[100005];

struct Seg
{
	int ll,rr,tmp;
	int sum[400005],cover[400005];
	
	void C(int p,int l,int r)
	{
		if(l>=ll&&r<=rr)
		{
			sum[p]=tmp*(r-l+1);
			cover[p]=tmp;
			return;
		}
		int mid=l+r>>1;
		if(cover[p]!=-1)
		{
			sum[p<<1]=cover[p]*(mid-l+1);
			sum[p<<1|1]=cover[p]*(r-mid);
			cover[p<<1]=cover[p<<1|1]=cover[p];
			cover[p]=-1;
		}
		if(rr<=mid)C(p<<1,l,mid);
		else if(ll>mid)C(p<<1|1,mid+1,r);
			else C(p<<1,l,mid),C(p<<1|1,mid+1,r);
		sum[p]=sum[p<<1]+sum[p<<1|1];
	}
	
	void Q(int p,int l,int r)
	{
		if(l>=ll&&r<=rr)
		{
			tmp+=sum[p];
			return;
		}
		int mid=l+r>>1;
		if(cover[p]!=-1)
		{
			sum[p<<1]=cover[p]*(mid-l+1);
			sum[p<<1|1]=cover[p]*(r-mid);
			cover[p<<1]=cover[p<<1|1]=cover[p];
			cover[p]=-1;
		}
		if(rr<=mid)Q(p<<1,l,mid);
		else if(ll>mid)Q(p<<1|1,mid+1,r);
			else Q(p<<1,l,mid),Q(p<<1|1,mid+1,r);
	}
	
	void Cover(int l,int r,int c)
	{
		ll=l;rr=r;tmp=c;
		C(1,1,n);
	}
	
	int Query(int l,int r)
	{
		ll=l;rr=r;tmp=0;
		Q(1,1,n);
		return tmp;
	}
}t[26];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;++i)t[s[i]-'a'].Cover(i,i,1);
	for(;m;--m)
	{
		scanf("%d%d",&l,&r);
		k=0;
		for(i=0;i<26;++i)
		{
			num[i]=t[i].Query(l,r);
			k+=num[i]&1;
			if(k>=2)break;
		}
		if(k>=2)continue;
		for(i=0;i<26;++i)if(num[i])t[i].Cover(l,r,0);
		k=-1;
		for(i=0;i<26;++i)if(num[i]&1)k=i;
		for(i=0;i<26;++i)
		if(num[i])
		{
			num[i]/=2;
			if(!num[i])continue;
			t[i].Cover(l,l+num[i]-1,1);
			t[i].Cover(r-num[i]+1,r,1);
			l+=num[i];r-=num[i];
		}
		if(k!=-1)t[k].Cover(l,r,1);
	}
	for(i=1;i<=n;++i)
	{
		for(j=0;j<26;++j)if(t[j].Query(i,i))break;
		printf("%c",'a'+j);
	}
	printf("\n");
}