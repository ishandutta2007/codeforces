#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
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
const ll N=3e5+50;
db C=1.0;
ll n,T=0;
struct Node
{
	ll p,t,l,r;
}a[N];
bool cmp(const Node &a,const Node &b)
{
	return a.p*b.t>a.t*b.p;
}
bool cmp2(const Node &a,const Node &b)
{
	return a.p<b.p;
}
int main()
{
	ll i,l,r,l2,r2,w1,w2,sum,now;
	db x;
	n=rd();
	for(i=1;i<=n;i++) a[i].p=rd();
	for(i=1;i<=n;i++) a[i].t=rd(),T+=a[i].t;
	sort(a+1,a+n+1,cmp);
	sum=0;
	for(l=1;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&a[r+1].p*a[l].t==a[l].p*a[r+1].t) r++;
		now=0;
		for(i=l;i<=r;i++) now+=a[i].t;
		for(i=l;i<=r;i++) a[i].l=sum+a[i].t,a[i].r=sum+now;
		sum+=now;
	}
	sort(a+1,a+n+1,cmp2);
	for(l=1;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&a[r+1].p==a[l].p) r++;
		if(r==n) break;
		l2=r2=r+1;
		while(r2<n&&a[r2+1].p==a[l2].p) r2++;
		w1=a[l].l;
		for(i=l+1;i<=r;i++) w1=min(w1,a[i].l);
		w2=a[l2].r;
		for(i=l2+1;i<=r2;i++) w2=max(w2,a[i].r);
		
		x=(double)(T*(a[l2].p-a[l].p))/(double)(a[l2].p*w2-a[l].p*w1);
		if(x>0) C=min(C,x); 
		//printf("S%lld %lld  %lld %lld   %lf\n",l,r,l2,r2,C);
	}
	printf("%.11lf\n",C);
	return 0;
}