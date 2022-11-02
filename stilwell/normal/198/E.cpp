#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int x,y,p,r,n,i,j,k,ll,rr,P;
long long qx[300005],qp[300005],R;
int Min[2000005];

struct node
{
	int x,y,m,p,r;
	long long X,R;
}t[300005];

inline bool cmp(const node &a,const node &b){return a.X<b.X;}

void C(int p,int l,int r)
{
	if(Min[p]>P)return;
	if(l==r)
	{
		++rr;
		qx[rr]=t[l].R;
		qp[rr]=t[l].p;
		Min[p]=0x7fffffff;
		return;
	}
	int mid=l+r>>1;
	C(p<<1,l,mid);
	C(p<<1|1,mid+1,r);
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
}

void Q(int p,int l,int r)
{
	if(t[l].X>R)return;
	if(t[r].X<=R)
	{
		C(p,l,r);
		return;
	}
	int mid=l+r>>1;
	Q(p<<1,l,mid);
	Q(p<<1|1,mid+1,r);
}

void E(int p,int l,int r)
{
	if(l==r)
	{
		Min[p]=t[l].m;
		return;
	}
	int mid=l+r>>1;
	E(p<<1,l,mid);
	E(p<<1|1,mid+1,r);
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
}

int main()
{
	scanf("%d%d%d%d%d",&x,&y,&p,&r,&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d%d%d",&t[i].x,&t[i].y,&t[i].m,&t[i].p,&t[i].r);
		t[i].x-=x;t[i].y-=y;
		t[i].X=(long long)t[i].x*t[i].x+(long long)t[i].y*t[i].y;
		t[i].R=(long long)t[i].r*t[i].r;
	}
	sort(t+1,t+n+1,cmp);
	qx[1]=(long long)r*r;
	qp[1]=p;
	ll=0;rr=1;
	E(1,1,n);
	while(ll<rr)
	{
		++ll;R=qx[ll];P=qp[ll];
		Q(1,1,n);
	}
	printf("%d\n",rr-1);
}