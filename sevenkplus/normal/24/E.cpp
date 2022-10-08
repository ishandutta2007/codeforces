#include<cstdio>
#include<algorithm>
#define N 524289
int a[N],v[N],n;
int main()
{
    scanf("%d",&n);for(int i=0;i<n;i++)scanf("%d%d",a+i,v+i);
    double l=0,r=1000000002;int T=100;
    while(T--)
    {
        double mid=(l+r)/2,ma=-1e20;
        bool f=0;
        for(int i=0;i<n;i++)
            if(v[i]>0)ma=std::max(ma,a[i]+v[i]*mid);
            else if(a[i]+v[i]*mid<=ma){f=1;break;}
        if(f)r=mid;else l=mid;
    }
    if(l>1000000001)puts("-1");else printf("%.9lf\n",l);
    return 0;
}