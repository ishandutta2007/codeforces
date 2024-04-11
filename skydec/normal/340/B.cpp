#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
int n,i,j,k,ii;
double Min,Max,ans,tmp;
double x[2001],y[2001];
 
double abs(double x){if(x<0)return -x;return x;}
double sqr(double x){return x*x;}
double dist(int a,int b){return sqr(x[a]-x[b])+sqr(y[a]-y[b]);}
 
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%lf%lf",&x[i],&y[i]);
    for(i=1;i<=n;++i)
    {
        Max=0;
        for(j=1;j<=n;++j)if(!Max||dist(i,j)>dist(i,Max))Max=j;
        j=Max;
        Min=1e20;
        Max=-1e20;
        for(k=1;k<=n;++k)
        if(k!=i&&k!=j)
        {
            tmp=(x[j]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[j]-y[i]);
            if(tmp<Min)Min=tmp;
            if(tmp>Max)Max=tmp;
        }
        if(Max-Min>ans)ans=Max-Min;
    }
    printf("%.3lf\n",ans/2.0);
}