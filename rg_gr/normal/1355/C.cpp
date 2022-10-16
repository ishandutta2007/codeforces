#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
int a[200005];
inline int max(int a,int b)
{
	return a>b?a:b;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int maxmin(int x)
{
	int maxn=0,minn=9;
	while(x)maxn=max(maxn,x%10),minn=min(minn,x%10),x/=10;
	return maxn*minn;
}
/*int cntTg(int x,int b,int c,int d)
{
	int lb=c-x+1,rb=d-x+1;
	int ua=0;
	if(lb<b)ub-=(b-lb)*(b-lb+1)/2;
	if(rb<b)
	lb=max(lb,b);lb=min(lb,c);
	rb=max(rb,b);rb=min(rb,c);
	
	lb=c-lb+1;rb=c-rb+1;
	return (lb+rb)*(rb-lb+1)/2;
}*/
int cnt(int i,int b,int c,int d)
{
	int x=i;
	int allOK=i+b-1;
	int ans=0;
	if(allOK>c)ans+=(c-b+1)*(allOK-c),c=allOK;;
	if(allOK>=d)return (d-c+1)*(c-b+1);
	d=min(d,c+x-1);
	int C=b+x-1-c,D=d-c;
	printf("all %d , C %d D %d c %d d %d\n",allOK,C,D,c,d);
	return (C+D)*(D-C+1)/2+ans;
}
int cnt1(int i,int b,int c,int d)
{
	int x=i,cc=c;
	int cntL=0,cntR=0,cntt=0;;
	if(b+x-1>c)
	{
		cntL+=(c-b+1)*(min(b+x-1-c,d-c));
		cc=b+x-1;
	}
	if(c+x-1<d)d=c+x-1;
	int tl=cc-x+1,tr=d-x+1;
	tl=max(tl,b);tr=max(tr,b);
	tl=min(tl,c);tr=min(tr,c);
	//printf("%lld %lld %lld\n",tl,tr,cntL);
	tl=c-tl+1,tr=c-tr+1;
	cntt=(tr+tl)*(tl-tr+1)/2;
	//printf("- %lld %lld %lld\n",tl,tr,cntt);
	return cntL+cntR+cntt;
}
signed main()
{
	int a=read(),b=read(),c=read(),d=read();
	int ans=0;
	for(int i=a;i<=b;i++)ans+=cnt1(i,b,c,d);
	printf("%lld\n",ans);
}