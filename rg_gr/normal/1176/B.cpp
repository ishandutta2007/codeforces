#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),cnt1=0,cnt2=0,cnt0=0;
        for(int i=0;i<n;i++)
        {

            int x=read();
            if(x%3==1)cnt1++;
            else if(x%3==2)cnt2++;
            else cnt0++;
        }
        int q=min(cnt1,cnt2);
        cnt1-=q;cnt2-=q;
        q+=cnt1/3;q+=cnt2/3;q+=cnt0;
        printf("%lld\n",q);
    }
}