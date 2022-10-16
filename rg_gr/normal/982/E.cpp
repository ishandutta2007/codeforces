#include <stdio.h>
#include <stdlib.h>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
int exgcd(int a,int b,int &x,int &y)
{
	int d=a,t;
	if(b==0)x=1,y=0;
	else d=exgcd(b,a%b,x,y),t=x,x=y,y=t-a/b*y;
	return d;
}
signed main()
{
	int n=read(),m=read(),x=read(),y=read(),dx=read(),dy=read();
	if(dx&&dy)
	{
		if(dx<0)x=n-x;
		if(dy<0)y=m-y;
		int a,b,d;
		d=exgcd(n,m,a,b);
		int p=(x-y)/d;
		if(p*d==x-y)
		{
			a*=p,b*=p,n/=d,m/=d;
			int ansx=a%m+m-1;ansx=ansx%m+1;
			int ansy=(ansx*n-p)/m;
			if((ansx&1)==(dx!=1))n=0;else n*=d;
			if((ansy&1)==(dy!=1))m=0;else m*=d;
			printf("%lld %lld\n",n,m);
		}
		else puts("-1");
	}
	else
	{
		if(dx)//dy==0
		{
			if(y==0)
			{
				if(dx==1)printf("%d 0\n",n);
				else puts("0 0");
			}
			else if(y==m)
			{
				if(dx==1)printf("%d %d\n",n,m);
				else printf("0 %d",m);
			}
			else puts("-1");
		}
		else//dx=000=0
		{
			if(x==0)
			{
				if(dy==1)printf("0 %d\n",m);
				else puts("0 0");
			}
			else if(x==n)
			{
				if(dy==1)printf("%d %d\n",n,m);
				else printf("%d 0",n);
			}
			else puts("-1");
		}
	}
	return 0;
}