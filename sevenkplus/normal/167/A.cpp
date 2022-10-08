#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 100010
int n,p,d,a[N],b[N];double c[N];
int main()
{
    scanf("%d%d%d",&n,&p,&d);
    for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
    for(int i=0;i<n;i++)
    {
        double t=b[i];t/=p;
        if(t/2.0*b[i]<d)c[i]=a[i]+t+(d-t/2.0*b[i])/b[i];
        else c[i]=a[i]+sqrt(d*2.0/p);
        if(i)c[i]=max(c[i],c[i-1]);
    }
    for(int i=0;i<n;i++)
        printf("%.9lf\n",c[i]);
    return 0;
}