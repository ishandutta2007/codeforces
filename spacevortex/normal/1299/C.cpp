#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
struct Point{ld x,y;};
const Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
const Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
ld cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
const ll N=1e6+50;
ll n,top=0;
Point bp;
ld a[N],sum[N];
Point p[N];
ll stk[N];
int main()
{
	ll i,j,pos,sl,sr,mid;
	ld S;
	n=rd();
	for(i=1;i<=n;i++)
	{
		a[i]=rd();
		sum[i]=sum[i-1]+a[i];
		p[i]=(Point){(ld)i,sum[i]};
	}
	for(i=1;i<=n;i++)
	{
		while(top>=2&&cross(p[i]-p[stk[top-1]],p[stk[top]]-p[stk[top-1]])>0) top--;
		stk[++top]=i;
	}
	//for(i=1;i<=top;i++) printf("#%lld %lld\n",i,stk[i]);
	for(i=1;i<=n;i=pos+1)
	{
		sl=1;sr=top;
		bp=p[i-1];
		while(sl<sr)
		{
			mid=(sl+sr)>>1;
			if(stk[mid]>=i&&(ld)(p[stk[mid]].y-bp.y)*(stk[mid+1]-i+1)<=(ld)(p[stk[mid+1]].y-bp.y)*(stk[mid]-i+1)) sr=mid;
			else sl=mid+1;
		}
		pos=stk[sl];
		S=0;
		for(j=i;j<=pos;j++) S+=a[j];
		S/=pos-i+1;
		//printf("U%lld %lld\n",i,pos);
		for(j=i;j<=pos;j++) 
		{
			a[j]=S;
			sum[j]=sum[j-1]+a[j];
		}
		p[pos]=(Point){(ld)pos,sum[pos]};
	}
	for(i=1;i<=n;i++)
	{
		printf("%.12lf\n",(double)a[i]);
	}
	return 0;
}