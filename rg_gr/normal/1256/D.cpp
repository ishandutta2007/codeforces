#include <stdio.h>
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
int a[1000005];
signed main()
{
    int n=read();
    while(n--)
    {
        int n=read(),k=read();
        for(int i=0;i<n;i++)a[i]=re1d();
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                if(i-cur<=k){k-=i-cur;if(i!=cur)a[i]=1;a[cur++]=0;}
                else 
                {
                    a[i]=1;
                    a[i-k]=0;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++)putchar(48|a[i]);
        puts("");
    }
}