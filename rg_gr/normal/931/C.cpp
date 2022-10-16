#include <stdio.h>
#include <string.h> 
#include <queue>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int a[100005];
signed main()
{
    int n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    std::sort(a+1,a+1+n);
    if(a[n]-a[1]<=1)
    {
        printf("%lld\n",n);
        for(int i=1;i<=n;i++)printf("%lld ",a[i]);
        return 0;
    }
    int bas=a[1]+1;
    int L=0,M=0,R=0;
    for(int i=1;i<=n;i++)
    {
        a[i]-=bas;
        if(a[i]==-1)L++;
        else if(a[i]==0)M++;
        else R++;
    }
    int ansM=(M>>1)<<1,ansQ=(L<R?L:R)<<1;
    if(ansQ<ansM)
    {
        printf("%lld\n",n-ansM);
        for(int i=0;i<L+(M>>1);i++)printf("%lld ",bas-1);
        if(M&1)printf("%lld ",bas);
        for(int i=0;i<R+(M>>1);i++)printf("%lld ",bas+1);
    }
    else
    {
        printf("%lld\n",n-ansQ);
        for(int i=0;i<L-(ansQ>>1);i++)printf("%lld ",bas-1);
        for(int i=0;i<M+ansQ;i++)printf("%lld ",bas);
        for(int i=0;i<R-(ansQ>>1);i++)printf("%lld ",bas+1);
    }
    
}