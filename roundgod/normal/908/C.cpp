#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
double n,r;
double a[MAXN],h[MAXN];
int main()
{
    scanf("%lf%lf",&n,&r);
    for(int i=0;i<n;i++)
        scanf("%lf",&a[i]);
    for(int i=0;i<n;i++)
    {
        double res=r;
        for(int j=0;j<i;j++)
            res=max(res,sqrt(4*r*r-(a[i]-a[j])*(a[i]-a[j]))+h[j]);
        h[i]=res;
    }
    for(int i=0;i<n;i++)
        printf("%.10f ",h[i]);
    return 0;
}