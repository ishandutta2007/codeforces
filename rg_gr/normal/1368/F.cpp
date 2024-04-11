#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <bitset>
#include <map>
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
#define ff fflush(stdout)
int a[1005];
inline int ok(int x)
{
    int iq=0;
    for(int i=1;i<=x;i++)iq+=a[i];
    return iq;
}
inline int f(int a,int bb){return a>bb?a:bb;}
signed main()
{
    int n=read();
    int q=sqrt(n);
    while(1)
    {
        if(ok(n)>=n/(q)*(q-1)+f(0,n%q-1)-q+1)break;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=q)break;
            if((i%q==1)||a[i])continue;
            cnt++;
        }
        printf("%lld ",cnt);
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=q)break;
            if((i%q==1)||a[i])continue;
            cnt++;
            printf("%lld ",i);
            a[i]=1;
        }
        puts("");
        ff;
        int p=read();
        for(int i=p;i<p+cnt;i++)a[(i-1)%n+1]=0;
    }
    /*int need=n>>1;need--;
    while(1)
    {
        if(ok(n)>=need)break;
        int ans=0;
        for(int i=1;i<=(n);i+=2)if(a[i]==0)ans++;
        printf("%lld ",ans);
        for(int i=1;i<=(n);i+=2)if(a[i]==0)printf("%lld ",i),a[i]=1;
        puts("");
        ff;
        int x=read();
        for(int i=0;i<ans;i++)a[(i+x-1)%n+1]=0;
    }
    int qwq=4;
    while(1)
    {
        int ans=0;
        for(int i=2;i<n;i+=qwq)ans++;
        ans=ans/qwq*qwq;
        if(ans==0)break;
        printf("%lld ",ans);
        for(int i=qwq/2,j=0;j<ans;i+=qwq,j++)printf("%lld ",i);puts("");ff;
    }*/
    puts("0");
    ff;
    return 0;
}