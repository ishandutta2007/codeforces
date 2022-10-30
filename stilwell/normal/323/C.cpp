#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,a,b,c,d,i,j,k,l,r,ll,rr,aim,ans;
int p[1000005],pp[1000005],q[1000005],qq[1000005],num[1000005];

int f(int x){return (x-1+ans)%n+1;}

struct node
{
	int l,r,sum;
}t[30000005];
int root[1000005],tot;

void C(int &now,int pre,int l,int r)
{
	now=++tot;t[now]=t[pre];
	++t[now].sum;
	if(l==r)return;
	int mid=l+r>>1;
	if(aim<=mid)C(t[now].l,t[pre].l,l,mid);
	else C(t[now].r,t[pre].r,mid+1,r);
}

void Q(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		ans+=t[p].sum;
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)Q(t[p].l,l,mid);
	else if(ll>mid)Q(t[p].r,mid+1,r);
		else Q(t[p].l,l,mid),Q(t[p].r,mid+1,r);
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&p[i]);
	for(i=1;i<=n;++i)pp[p[i]]=i;
	for(i=1;i<=n;++i)scanf("%d",&q[i]);
	for(i=1;i<=n;++i)qq[q[i]]=i;
	for(i=1;i<=n;++i)num[pp[i]]=qq[i];
	for(i=1;i<=n;++i)aim=num[i],C(root[i],root[i-1],1,n);
	scanf("%d",&m);
	for(;m;--m)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		l=f(a);r=f(b);if(l>r)swap(l,r);
		ll=f(c);rr=f(d);if(ll>rr)swap(ll,rr);
		ans=0;Q(root[l-1],1,n);
		ans=-ans;Q(root[r],1,n);
		printf("%d\n",ans);++ans;
	}
}