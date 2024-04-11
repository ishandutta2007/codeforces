#include <stdio.h>
#include <string.h> 
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
    int T=read();
    while(T--)
    {
        int n=read(),k=read();
        for(int i=1;i<=n;i++)a[i]=read();
        std::sort(a+1,a+n+1);
        int mex=-1,max=a[n];a[0]=-1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]-1>a[i-1])
            {
                mex=a[i-1]+1;
                break;
            }
        }
        if(mex==-1)
        {
            printf("%lld\n",max+1+k);
            continue;
        }
        if(max-1==mex)
        {
            printf("%lld\n",n);
        }
        else
        {
            if(k==0)printf("%lld\n",n);
            else
            {
                int aa=(max+mex-1)/2+1;
                for(int i=1;i<=n;i++)
                {
                    if(a[i]==aa)
                    {
                        printf("%lld\n",n);
                        goto ng;
                    }
                }
                printf("%lld\n",n+1);
            }
        }
        ng:;
    }
}