#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,b,c,d,t,ans,lim,x,y,xx,yy;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&a,&b,&c,&d);
		if(a>c)
		{
			swap(a,c);
			swap(b,d);
		}
		if(a==c&&b<d)
			swap(b,d);
		if(b>d)
		{
			m-=(d-c)*n;
			b-=d-c;
			c=a;
			d=c;
		}
		else if(b>c)
		{
			m-=(b-c)*n;
			d-=b-c;
			b=c;
		}
		if(m<=0)
		{
			puts("0");
			continue;
		}
		x=max(c,a)-min(a,c)+max(b,d)-min(b,d);
		y=max(b,d)-min(a,c);
		if(y)
		{
			xx=m%y;
			yy=m/y;
			yy=min(yy,n);
			xx=m-yy*y;
			ans=min(yy?x*yy+xx*2:1000000000000000000ll,(yy<n&&xx<y)?x*(yy+1)-(y-xx):100000000000000000ll);
		}
		else 
			ans=m*2;
		printf("%lld\n",ans);
	}
	return 0;
}//1