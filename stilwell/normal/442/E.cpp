#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,id[1005];
double w,h,x[1005],y[1005],dist[1005][1005];
double pi,a,d,l,r,mid,ans,tmp;

struct node
{
	double x;int y;
}t[100005];
inline bool cmp(const node &a,const node &b){return a.x<b.x;}
double sqr(double x){return x*x;}

void add(double l,double r)
{
	if(l<-pi)
	{
		add(l+2*pi,pi);
		add(-pi,r);
		return;
	}
	if(r>pi)
	{
		add(l,pi);
		add(-pi,r-2*pi);
		return;
	}
	++m;t[m].x=l;t[m].y=1;
	++m;t[m].x=r;t[m].y=-1;
}

bool check(int p,double r)
{
	int i,j,k;
	m=0;
	++m;t[m].x=-pi;t[m].y=0;
	for(i=1;i<=n;++i)
	if(dist[i][p]>0.5&&dist[i][p]<=2*r)
	{
		a=atan2(y[i]-y[p],x[i]-x[p]);
		d=acos(dist[i][p]/2/r);
		if(d<0)d=-d;
		add(a-d,a+d);
	}
	if(x[p]<=r)
	{
		a=atan2(0,-1);
		d=acos(x[p]/r);
		if(d<0)d=-d;
		add(a-d,a+d);add(a-d,a+d);
	}
	if(x[p]+r>=w)
	{
		a=atan2(0,1);
		d=acos((w-x[p])/r);
		if(d<0)d=-d;
		add(a-d,a+d);add(a-d,a+d);
	}
	if(y[p]<=r)
	{
		a=atan2(-1,0);
		d=acos(y[p]/r);
		if(d<0)d=-d;
		add(a-d,a+d);add(a-d,a+d);
	}
	if(y[p]+r>=h)
	{
		a=atan2(1,0);
		d=acos((h-y[p])/r);
		if(d<0)d=-d;
		add(a-d,a+d);add(a-d,a+d);
	}
	sort(t+1,t+m+1,cmp);
	k=0;
	for(i=1;i<=m;i=j)
	{
		if(t[i].x==pi)return false;
		for(j=i;j<=m&&t[j].x==t[i].x;++j)k+=t[j].y;
		if(k<=1)return true;
	}
	return false;
}

int main()
{
	pi=acos(-1);
	scanf("%lf%lf%d",&w,&h,&n);
	for(i=1;i<=n;++i)scanf("%lf%lf",&x[i],&y[i]);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	dist[i][j]=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
	ans=1e-9;
	for(i=1;i<=n;++i)id[i]=i;
	random_shuffle(id+1,id+n+1);
	for(i=1;i<=n;++i)
	if(check(id[i],ans+1e-9))
	{
		l=ans;r=2e6;
		for(;r-l>1e-9;)
		{
			mid=(l+r)/2;
			if(check(id[i],mid))ans=mid,l=mid;
			else r=mid;
		}
	}
	printf("%.15lf\n",ans);
}