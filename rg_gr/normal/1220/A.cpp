#include <stdio.h>
#include <string.h> 
#include <queue>
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
//int a[1005][1005];
int z,e,r,o,n;
inline int readd()
{
    char c=getchar();
    while(c<'a'||c>'z')c=getchar();
    if(c=='z')z++;
    else if(c=='e')e++;
    else if(c=='r')r++;
    else if(c=='o')o++;
    else n++;
    return 114514;
}
inline int min(int a,int b)
{
    return a<b?a:b;;
}
signed main()
{
    int nnn=read();
    for(int i=1;i<=nnn;i++)readd();
    //ans1
    int ans1=0;
    int Z=z,E=e,R=r,O=o,N=n;
    ans1=min(Z,min(E,min(R,O)));
    Z-=ans1,E-=ans1,R-=ans1,O-=ans1;
    int qwq=min(O,min(N,E));

    int tot1=ans1+qwq;

    //puts("???");
    int ans2=0;
    Z=z,E=e,R=r,O=o,N=n;
    int qaq=min(O,min(N,E));
    O-=qaq,N-=qaq,E-=qaq;
    ans2=min(Z,min(E,min(R,O)));

    int tot2=ans2+qaq;
    //printf("%lld %lld - %lld %lld\n",qwq,ans1,qaq,ans2);
    if(tot1<=tot2)
    {
        for(int i=0;i<qaq;i++)putchar(49),putchar(32);
        for(int i=0;i<ans2;i++)putchar(48),putchar(32);
    }
    else// for(int i=0;i<qwq;i++)
    {
        for(int i=0;i<qwq;i++)putchar(49),putchar(32);
        for(int i=0;i<ans1;i++)putchar(48),putchar(32);
    }
    puts("");
}