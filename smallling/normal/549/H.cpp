#include<cmath>
#include<cstdio>
#include<algorithm>

#define eps 1e-10

using namespace std;

double l,r,mid,ans,a1,a2,a3,a4,minn,maxx,min14,min23,max14,max23;

bool check(double x)
{
    min14=a1*a4;
    min14=min(min14,(a1-x)*(a4+x));
    min14=min(min14,(a1-x)*(a4-x));
    min14=min(min14,(a1+x)*(a4+x));
    min14=min(min14,(a1+x)*(a4-x));
    max14=a1*a4;
    max14=max(max14,(a1-x)*(a4+x));
    max14=max(max14,(a1-x)*(a4-x));
    max14=max(max14,(a1+x)*(a4+x));
    max14=max(max14,(a1+x)*(a4-x)); 
    min23=a2*a3;
    min23=min(min23,(a2-x)*(a3+x));
    min23=min(min23,(a2-x)*(a3-x));
    min23=min(min23,(a2+x)*(a3+x));
    min23=min(min23,(a2+x)*(a3-x));
    max23=a2*a3;
    max23=max(max23,(a2-x)*(a3+x));
    max23=max(max23,(a2-x)*(a3-x));
    max23=max(max23,(a2+x)*(a3+x));
    max23=max(max23,(a2+x)*(a3-x));
    minn=min14-max23;
    maxx=max14-min23;
    if(minn<=0&&maxx>=0)return 1;
    return 0;
}

int main()
{
    int cnt=0;
    l=0;r=10000000000.0;
    scanf("%lf%lf%lf%lf",&a1,&a2,&a3,&a4);
    while(l+eps<=r&&cnt<=500)
    {
        mid=(l+r)/2.;
        if(check(mid))ans=mid,r=mid-eps;
        else l=mid+eps;
        cnt++;
    }
    printf("%.9lf\n",ans);
}