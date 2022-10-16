#include <stdio.h>
#include <string.h> 
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
signed  main()
{
    int n=read(),a=read()-1,b=read()-1;
    int qwq=0;
    for(int i=1;i<=n;i+=i)qwq++;
    int u=n>>1,nct=0;
    while(u)
    {
        if((a&u)==(b&u))nct++;
        else break;
        u>>=1;
    }
    if(nct==0)puts("Final!");
    else printf("%lld\n",qwq-nct-1);
}