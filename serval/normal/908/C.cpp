#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double x[1005];
int n,i,j;
double r;
double ans[1005];
int main()
{
    scanf("%d",&n);
    scanf("%lf",&r);
    for (i=1;i<=n;i++)
    {
        scanf("%lf",&x[i]);
        ans[i]=r;
        for (j=1;j<i;j++)
            if (abs(x[i]-x[j])<=2.0*r)
                if (sqrt(4.0*r*r-(x[i]-x[j])*(x[i]-x[j]))+ans[j]>ans[i])
                    ans[i]=sqrt(4.0*r*r-(x[i]-x[j])*(x[i]-x[j]))+ans[j];
        printf("%.8lf ",ans[i]);
    }
    return 0;
}