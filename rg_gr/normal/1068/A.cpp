#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
signed main()
{
    int n=read(),m=read(),k=read(),l=read();l+=k;
    int q=(l-1)/m+1;
    if(q*m>n)puts("-1");
    else printf("%lld\n",q);
}