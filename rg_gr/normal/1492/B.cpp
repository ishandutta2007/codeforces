#include <stdio.h>
#include <string.h>
#include <algorithm>
inline int read()
{
    int num=0;char c=getchar();
    while(c<48||c>57)c=getchar();
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num;
}
inline int max(int a,int b)
{
    return a<b?a:b;
}
int a[100005],cnt,b[100005];
signed main()
{
    int T=read();
    while(T--)//
    {
        int n=read();
        cnt=n;
        for(int i=1;i<=n;i++)a[i]=read(),b[a[i]]=i;
        int cur=n,qaq=0;
        while(cnt)
        {
            for(int i=b[cur];i<=cnt;i++)
            {
                printf("%d ",a[i]);
            }
            cnt=b[cur]-1;
            cur--;
            while(b[cur]>cnt)cur--;
            //puts("?");
        }
        puts("");
    }
}