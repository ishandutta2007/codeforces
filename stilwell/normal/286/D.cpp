#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,ll,rr,tmp,tmp1,tmp2,tot,tot2,root,root2,aim;
long long ans;

struct seg1
{
	int l,r,Min;
}t[7000005];
struct seg2
{
	int l,r,k1;
	long long k2;
}q[7000005];

void C(int &p,int l,int r)
{
	if(!p)t[p=++tot].Min=2000000050;
	if(l>=ll&&r<=rr)
	{
		if(tmp<t[p].Min)t[p].Min=tmp;
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)C(t[p].l,l,mid);
	else if(ll>mid)C(t[p].r,mid+1,r);
		else C(t[p].l,l,mid),C(t[p].r,mid+1,r);
}

void C2(int &p,int l,int r)
{
	if(!p)p=++tot2;
	if(l>=ll&&r<=rr)
	{
		q[p].k1+=tmp1;
		q[p].k2+=tmp2;
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)C2(q[p].l,l,mid);
	else if(ll>mid)C2(q[p].r,mid+1,r);
		else C2(q[p].l,l,mid),C2(q[p].r,mid+1,r);
}

void work(int l,int r,int key)
{
	if(r==-1)return;
	if(key>1000000050)return;
	ll=key-r+1;rr=key-l+2;if(ll<=0)ll=1;
	tmp1=1;tmp2=r-key;
	if(ll<=rr)C2(root2,1,1000000005);
	ll=rr+1;rr=1000000005;if(ll<=0)ll=1;
	tmp1=0;tmp2=r-l+1;
	if(ll<=rr)C2(root2,1,1000000005);
}

void M(int p,int l,int r)
{
	if(!t[p].l&&!t[p].r)
	{
		if(rr+1==l&&tmp==t[p].Min)rr=r;
		else
		{
			work(ll,rr,tmp);
			ll=l;rr=r;tmp=t[p].Min;
		}
		return;
	}
	if(!t[p].l)t[t[p].l=++tot].Min=t[p].Min;
	else if(t[p].Min<t[t[p].l].Min)t[t[p].l].Min=t[p].Min;
	if(!t[p].r)t[t[p].r=++tot].Min=t[p].Min;
	else if(t[p].Min<t[t[p].r].Min)t[t[p].r].Min=t[p].Min;
	int mid=l+r>>1;
	M(t[p].l,l,mid);
	M(t[p].r,mid+1,r);
}

void Q(int p,int l,int r)
{
	ans+=(long long)(aim-1)*q[p].k1+q[p].k2;
	if(l==r)return;
	int mid=l+r>>1;
	if(aim<=mid)Q(q[p].l,l,mid);
	else Q(q[p].r,mid+1,r);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(;m;--m)
	{
		scanf("%d%d%d",&ll,&rr,&tmp);++ll;++ll;++rr;++tmp;
		C(root,1,1000000005);
	}
	rr=-1;
	M(root,1,1000000005);
	work(ll,rr,tmp);
	for(;n;--n)
	{
		scanf("%d",&aim);++aim;
		ans=0;
		Q(root2,1,1000000005);
		printf("%I64d\n",ans);
	}
}