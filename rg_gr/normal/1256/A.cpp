#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
    int f=1,num=0;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
inline int re1d()
{
    char c=getchar();
    while (c<48||c>49)
    {
        c=getchar();
    }
    return c&1;
    
}
inline int max(int a,int b)
{
    return a<b?a:b;
}

signed main()
{
    int n=read();
    while(n--)
    {
        int a=read(),b=read(),n=read(),s=read();
        int q=s/n*n;
        int D=s-q;
        if(D>b){puts("NO");continue;}
        int p=s-a*n;
        if(p>b)puts("NO");
        else puts("YES");
    }
}