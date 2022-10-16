#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int a[200005];
int t[200005];
inline int lowbit(int x)
{
    int q=0;
    while(x>1)x>>=1,q++;
    return q;
}
inline int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),ans,q;
        hihi:;
        ans=0,q=n;
        while(q)ans+=q%10,q/=10;
        //printf("%lld\n",gcd(n,ans));
        int p=gcd(n,ans);
        if(p>1){printf("%lld\n",n);continue;}
        n++;goto hihi;
    }
}