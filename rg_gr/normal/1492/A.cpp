#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
    int num=0;char c=getchar();
    while(c<48||c>57)c=getchar();
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num;
}
inline int max(int a,int b)
{
    return a<b?a:b;
}//
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),a=read(),b=read(),c=read();
        int ansa=(a-n)%(a);
        int ansb=(b-n)%(b);
        int ansc=(c-n)%(c);
        ansa=ansa+a;ansa%=a;
        ansb=ansb+b;ansb%=b;
        ansc=ansc+c;ansc%=c;
        printf("%lld\n",max(max(ansa,ansb),ansc));
    }
}