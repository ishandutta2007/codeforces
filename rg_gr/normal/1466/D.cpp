#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int reaD()
{
    char c=getchar();
    while(c<97||c>'z')c=getchar();
    return c-97;
}
int a[100005];
int f[100005],q[100005];
int cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),sum=0;
        for(int i=1;i<=n;i++)sum+=a[i]=read();
        memset(f,0,sizeof(int)*(n+3));
        for(int i=1;i<n;i++)
        {
            int x=read(),y=read();
            f[x]++,f[y]++;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<f[i];j++)q[cnt++]=a[i];
        }
        std::sort(q,q+cnt,cmp);
        for(int i=0;i<n-1;i++)
        {
            printf("%lld ",sum);
            sum+=q[i];
        }
        puts("");
    }
}
//425316