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
signed main()
{
	int a=read(),b=read();
	if(b/a==1)return puts("NO")&0;
	puts("YES");
	int x=b/a;
	for(int i=1;i<a;i++)printf("%d ",x),b-=x;
	printf("%d\n1\n",b);
}