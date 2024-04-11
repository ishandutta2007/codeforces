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
int a[1000005],b[1000005];
inline int re1d()
{
    char c=getchar();int qw=0;
    while(!(c>='A'&&c<='Z' || c>='a'&&c<='z')){if(c==-1)return -1;c=getchar();}
    while((c>='A'&&c<='Z' || c>='a'&&c<='z'))c=getchar(),qw++;
    return qw;
    
}
int chack(int m,int k,int n)
{
    int cur=1,qwq=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>m)return 0;
        if(qwq+a[i]<=m)qwq+=a[i];
        else cur++,qwq=a[i];
        if(cur==k+1)return 0;
    }
    return 1;
}
signed main()
{
    int k=read();
    int n=0;
    for(int i=1;;i++)
    {
        int x=re1d()+1;
        if(!x)break;
        a[++n]=x;
    }
    a[n]--;
    int L=1,R=10000000,ans=10000000;
    while(L<=R)
    {
        int M=L+R>>1;
        if(chack(M,k,n))R=M-1,ans=M;
        else L=M+1;
    }
    printf("%lld\n",ans);
}