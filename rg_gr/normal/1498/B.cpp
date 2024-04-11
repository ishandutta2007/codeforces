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
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),w=read();
        for(int i=0;i<n;i++)a[i]=read(),t[lowbit(a[i])]++;
        int lf=n,ans=0,cur=n;
        while(lf)
        {
            //puts("plpl");
            ans++;
            cur=w;
            for(int i=30;i>=0;i--)
            {
                if(t[i]&&cur>=(1<<i))
                {
                    t[i]--,cur-=(1<<i),lf--,i++;
                    //printf("%lld\n",lf);
                    if(lf==0)break;
                }
            }
        }
        printf("%lld\n",ans);
    }
}