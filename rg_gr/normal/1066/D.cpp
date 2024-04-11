#include <stdio.h>
#include <map>
#include <algorithm>
#include <string.h>
#define int long long
inline int read()
{
    int f=1,num=0;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
int a[200005];
int chack(int p,int n,int m,int k)
{
    int cur=1,now=0;
    for(int i=p;i<=n;i++)
    {
        if(a[i]+now>k)cur++,now=0;
        if(cur>m)return 0;
        now+=a[i];
    }
    return 1;
}
signed main()
{
    int n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    int L=1,R=n,ans=n;
    while(L<=R)
    {
        int M=L+R>>1;
        if(chack(M,n,m,k))ans=M,R=M-1;
        else L=M+1;
    }
    printf("%lld\n",n-ans+1);
}