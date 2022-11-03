/*
ID: Sfiction
OJ: CF
PROB: 167A
*/
#include <cstdio>
#include <cmath>
const int MAXN=100000;
double f[MAXN];
int main()
{
    double a,d,v,x;
    int n;
    int i;
    scanf("%d%lf%lf",&n,&a,&d);
    for (i=0;i<n;++i)
    {
        scanf("%lf%lf",&f[i],&v);
        x=v*v/(2*a);
        if (d<x) f[i]+=sqrt(2*d/a);
        else f[i]+=v/a+(d-x)/v;
    }
    printf("%.10lf",f[0]);
    for (i=1;i<n;++i)
    {
        if (f[i]<f[i-1]) f[i]=f[i-1];
        printf("\n%.10lf",f[i]);
    }
    return 0;
}