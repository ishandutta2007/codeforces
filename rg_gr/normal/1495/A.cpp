#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <math.h>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num;
}
int a[100005],b[100005];
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read();
        int cnt1=0,cnt2=0;
        for(int i=0;i<n+n;i++)
        {
            int x=read(),y=read();
            if(x==0)b[cnt2++]=y;
            else a[cnt1++]=x;
        }
        std::sort(a,a+n);
        std::sort(b,b+n);
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            //int j=n-i-1;
            int j=i;
            //printf("match %lld %lld\n",a[i],b[j]);
            ans+=sqrt(1.0*a[i]*a[i]+1.0*b[j]*b[j]);
        }
        printf("%.10lf\n",ans);
    }
}