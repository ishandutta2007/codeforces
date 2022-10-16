#include <stdio.h>
#include <stdlib.h>
#define int unsigned long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b)
{
    return a<b?a:b;
}
int a[200005],b[200005],r[200005];
inline int rd()
{
    char c=getchar();
    while(c<'A'&&c>'Z'&&c!='?')c=getchar();
    if(c=='L')return 1;
    else if(c=='W')return 2;
    else if(c=='D')return 3;
    return 0;
}////////////////////////
int chack(int n,int m,int k)
{
    if(k<=2*n/m/(m+1))return 1;
    return 0;
}
signed main()
{
    int n=read(),m=read(),i;
    if(m>=200000||m*(m+1)>2*n)return puts("-1")&0;
    for(i=1;i*i<=n;i++)if(n%i==0&&chack(n,m,n/i))
    {
        i=n/i;
        for(int ii=1;ii<m;ii++)printf("%lld ",(long long)i*ii),n-=ii*i;
        printf("%lld\n",(long long)n);
        return 0;
    }
    for(;i>=1;i--)if(n%i==0&&chack(n,m,i))
    {
        for(int ii=1;ii<m;ii++)printf("%lld ",(long long)i*ii),n-=ii*i;
        printf("%lld\n",(long long)n);
        return 0;
    }
    puts("-1");
}