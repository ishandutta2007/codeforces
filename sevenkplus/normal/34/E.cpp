#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 12
double x[N],y[N];int n,z[N];double T,t;
double met(int i,int j)
{
    if(fabs(y[j]-y[i])<1e-10)return 1e10;
    if(x[i]>x[j])swap(i,j);
    double t=(x[j]-x[i])/(y[i]-y[j]);
    if(t<1e-12)return 1e10;
    return (x[j]-x[i])/(y[i]-y[j]);
}
int main()
{
    scanf("%d%lf",&n,&T);
    for(int i=0;i<n;i++)scanf("%lf%lf%d",x+i,y+i,z+i);
    while(T-t>1e-10)
    {
        double t1=T-t;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)t1=min(t1,met(i,j));
        for(int i=0;i<n;i++)x[i]+=y[i]*t1;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(fabs(x[i]-x[j])<1e-12)
                {
                    double yx=((z[i]-z[j])*y[i]+2*z[j]*y[j])/(z[i]+z[j]),yy=((z[j]-z[i])*y[j]+2*z[i]*y[i])/(z[i]+z[j]);
                    y[i]=yx,y[j]=yy;
                }
        t+=t1;
    }
    for(int i=0;i<n;i++)printf("%.9lf\n",x[i]);
    return 0;
}