#include <stdio.h>
#include <string.h>
#define int long long
inline int read()
{
    int f=1,num=0;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
inline int re1d()
{
    char c=getchar();
    while (c<48||c>49)
    {
        c=getchar();
    }
    return c&1;
    
}
int a[1000005],vis[1000005];
signed main()
{
    int n=read();
    while(n--)
    {
        memset(vis,0,sizeof(vis));
        int n=read(),q=n-1;;
        for(int i=1;i<=n;i++)a[i]=read();
        if(n==1){puts("1");continue;}
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j]==i)
                {
                    while(a[j]<a[j-1]&&j>1)
                    {
                        if(vis[j])break;
                        a[j]^=a[j-1]^=a[j]^=a[j-1];
                        vis[j]=1;
                        j--;
                        q--;
                        if(q==0)goto en;
                    }
                }
            }
        }
        en:;
        for(int i=1;i<=n;i++)printf("%lld ",a[i]);
        puts("");
    }
}