#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

int n,m,d,i,j,k,ansl,ansr,ll,rr,lim,tmp;
int a[200005];
long long Min[800005],add[800005],val;
int st1[200005],stl1[200005],str1[200005],top1;
int st2[200005],stl2[200005],str2[200005],top2;

map <int,int> pre;

void ans_update(int l,int r)
{
	if(r-l<ansr-ansl)return;
	if(r-l>ansr-ansl)
	{
		ansl=l;ansr=r;
		return;
	}
	if(l<ansl)ansl=l,ansr=r;
}

void down(int x)
{
	add[x<<1]+=add[x];Min[x<<1]+=add[x];
	add[x<<1|1]+=add[x];Min[x<<1|1]+=add[x];
	add[x]=0;
}

void C(int x,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		add[x]+=val;
		Min[x]+=val;
		return;
	}
	int mid=l+r>>1;
	if(add[x])down(x);
	if(rr<=mid)C(x<<1,l,mid);
	else if(ll>mid)C(x<<1|1,mid+1,r);
		else C(x<<1,l,mid),C(x<<1|1,mid+1,r);
	if(Min[x<<1]<Min[x<<1|1])Min[x]=Min[x<<1];else Min[x]=Min[x<<1|1];
}

void Q(int x,int l,int r)
{
	if(Min[x]>0||tmp)return;
	if(l>=ll&&r<=rr)
	{
		if(l==r)
		{
			tmp=l;
			return;
		}
		int mid=l+r>>1;
		if(add[x])down(x);
		Q(x<<1,l,mid);
		Q(x<<1|1,mid+1,r);
		return;
	}
	int mid=l+r>>1;
	if(add[x])down(x);
	if(rr<=mid)Q(x<<1,l,mid);
	else if(ll>mid)Q(x<<1|1,mid+1,r);
		else Q(x<<1,l,mid),Q(x<<1|1,mid+1,r);
}

int main()
{
	ansl=1;ansr=0;
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	if(d==0)
	{
		for(i=k=1;i<=n;++i)
		{
			if(a[i]!=a[k])k=i;
			ans_update(k,i);
		}
		printf("%d %d\n",ansl,ansr);
		return 0;
	}
	ll=1;rr=n;val=-(long long)m*d;
	C(1,1,n);
	lim=1;
	// Max-Min <= (r-l)d+md
	for(i=1;i<=n;++i)
	{
		k=pre[a[i]];
		if(k+1>lim)lim=k+1;
		pre[a[i]]=i;
		if(i>1&&(a[i]-a[i-1])%d!=0)lim=i;
		
		for(;top1&&st1[top1]>=a[i];--top1)
		{
			ll=stl1[top1];rr=str1[top1];val=st1[top1];
			C(1,1,n);
		}
		st1[++top1]=a[i];
		stl1[top1]=str1[top1-1]+1;
		str1[top1]=i;
		ll=stl1[top1];rr=str1[top1];val=-st1[top1];
		C(1,1,n);
		
		for(;top2&&st2[top2]<=a[i];--top2)
		{
			ll=stl2[top2];rr=str2[top2];val=-st2[top2];
			C(1,1,n);
		}
		st2[++top2]=a[i];
		stl2[top2]=str2[top2-1]+1;
		str2[top2]=i;
		ll=stl2[top2];rr=str2[top2];val=st2[top2];
		C(1,1,n);
		
		tmp=0;ll=lim;rr=i;
		Q(1,1,n);
		ans_update(tmp,i);
		
		ll=1;rr=i;val=-d;
		C(1,1,n);
	}
	printf("%d %d\n",ansl,ansr);
}