#include <stdio.h>
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
int a[200005],v[200005];
signed main()
{
    int T=1;//read();
    while(T--)
    {
        int n=read(),r=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++)if(a[i])
            for(int j=1>i-r+1?1:i-r+1;j<=n&&j<=i+r-1;j++)v[j]=1;
        for(int i=1;i<=n;i++)if(v[i]==0){puts("-1");return 0;}
        int cov=0,ans=0;
        while(cov<n)
        {
            for(int i=cov+r;i>=0;i--)
            {
                //if(i==cov-r||i==0){puts("-1");return 0;}
                if(a[i]){ans++,cov=i+r-1;break;}
            }
            
        }
        printf("%lld\n",ans);
    }
}